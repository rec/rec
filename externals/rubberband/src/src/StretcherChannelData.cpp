/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*-  vi:set ts=8 sts=4 sw=4: */

/*
    Rubber Band
    An audio time-stretching and pitch-shifting library.
    Copyright 2007-2011 Chris Cannam.

    This is the commercial edition of Rubber Band.  This software may be
    used and distributed only in accordance with the terms under which it
    was licensed to you.  In particular, you may NOT
      - distribute any part of this source code to any third party
      - link this software against other code that is licensed under
        the GPL (e.g. libsamplerate or FFTW) unless you have obtained
        a proprietary license for that software as well
*/

#include "StretcherChannelData.h"

#include "dsp/Resampler.h"

#include "system/Allocators.h"

namespace RubberBand 
{
      
RubberBandStretcher::Impl::ChannelData::ChannelData(size_t windowSize,
                                                    size_t fftSize,
                                                    size_t outbufSize)
{
    std::set<size_t> s;
    construct(s, windowSize, fftSize, outbufSize);
}

RubberBandStretcher::Impl::ChannelData::ChannelData(const std::set<size_t> &sizes,
                                                    size_t initialWindowSize,
                                                    size_t initialFftSize,
                                                    size_t outbufSize)
{
    construct(sizes, initialWindowSize, initialFftSize, outbufSize);
}

void
RubberBandStretcher::Impl::ChannelData::construct(const std::set<size_t> &sizes,
                                                  size_t initialWindowSize,
                                                  size_t initialFftSize,
                                                  size_t outbufSize)
{
    size_t maxSize = initialWindowSize;
    if (initialFftSize > maxSize) maxSize = initialFftSize;

    // std::set is ordered by value
    std::set<size_t>::const_iterator i = sizes.end();
    if (i != sizes.begin()) {
        --i;
        if (*i > maxSize) maxSize = *i;
    }

    // max possible size of the real "half" of freq data
    size_t realSize = maxSize / 2 + 1;

//    std::cerr << "ChannelData::construct([" << sizes.size() << "], " << maxSize << ", " << outbufSize << ")" << std::endl;
    
    if (outbufSize < maxSize) outbufSize = maxSize;

    inbuf = new RingBuffer<float>(maxSize);
    outbuf = new RingBuffer<float>(outbufSize);

    mag = allocate_and_zero<process_t>(realSize);
    phase = allocate_and_zero<process_t>(realSize);
    prevPhase = allocate_and_zero<process_t>(realSize);
    prevError = allocate_and_zero<process_t>(realSize);
    unwrappedPhase = allocate_and_zero<process_t>(realSize);
    envelope = allocate_and_zero<process_t>(realSize);

    freqPeak = allocate_and_zero<size_t>(realSize);

    fltbuf = allocate_and_zero<float>(maxSize);
    dblbuf = allocate_and_zero<process_t>(maxSize);

    accumulator = allocate_and_zero<float>(maxSize);
    windowAccumulator = allocate_and_zero<float>(maxSize);
    interpolator = allocate_and_zero<float>(maxSize);
    interpolatorScale = 0;

    for (std::set<size_t>::const_iterator i = sizes.begin();
         i != sizes.end(); ++i) {
        ffts[*i] = new FFT(*i);
        if (sizeof(process_t) == sizeof(double)) {
            ffts[*i]->initDouble();
        } else {
            ffts[*i]->initFloat();
        }
    }
    fft = ffts[initialFftSize];

    resampler = 0;
    resamplebuf = 0;
    resamplebufSize = 0;

    reset();

    // Avoid dividing opening sample (which will be discarded anyway) by zero
    windowAccumulator[0] = 1.f;
}


void
RubberBandStretcher::Impl::ChannelData::setSizes(size_t windowSize,
                                                 size_t fftSize)
{
    size_t maxSize = std::max(windowSize, fftSize);
    size_t realSize = maxSize / 2 + 1;
    size_t oldMax = inbuf->getSize();
    size_t oldReal = oldMax / 2 + 1;

    if (oldMax >= maxSize) {

        // no need to reallocate buffers, just reselect fft

        //!!! we can't actually do this without locking against the
        //process thread, can we?  we need to zero the mag/phase
        //buffers without interference

        if (ffts.find(fftSize) == ffts.end()) {
            //!!! this also requires a lock, but it shouldn't occur in
            //RT mode with proper initialisation
            ffts[fftSize] = new FFT(fftSize);
            if (sizeof(process_t) == sizeof(double)) {
                ffts[fftSize]->initDouble();
            } else {
                ffts[fftSize]->initFloat();
            }
        }
        
        fft = ffts[fftSize];

        v_zero(fltbuf, maxSize);
        v_zero(dblbuf, maxSize);

        v_zero(mag, realSize);
        v_zero(phase, realSize);
        v_zero(prevPhase, realSize);
        v_zero(prevError, realSize);
        v_zero(unwrappedPhase, realSize);
        v_zero(freqPeak, realSize);

        return;
    }

    //!!! at this point we need a lock in case a different client
    //thread is calling process() -- we need this lock even if we
    //aren't running in threaded mode ourselves -- if we're in RT
    //mode, then the process call should trylock and fail if the lock
    //is unavailable (since this should never normally be the case in
    //general use in RT mode)

    RingBuffer<float> *newbuf = inbuf->resized(maxSize);
    delete inbuf;
    inbuf = newbuf;

    // We don't want to preserve data in these arrays

    mag = reallocate_and_zero(mag, oldReal, realSize);
    phase = reallocate_and_zero(phase, oldReal, realSize);
    prevPhase = reallocate_and_zero(prevPhase, oldReal, realSize);
    prevError = reallocate_and_zero(prevError, oldReal, realSize);
    unwrappedPhase = reallocate_and_zero(unwrappedPhase, oldReal, realSize);
    envelope = reallocate_and_zero(envelope, oldReal, realSize);
    freqPeak = reallocate_and_zero(freqPeak, oldReal, realSize);
    fltbuf = reallocate_and_zero(fltbuf, oldMax, maxSize);
    dblbuf = reallocate_and_zero(dblbuf, oldMax, maxSize);

    interpolator = reallocate_and_zero<float>(interpolator, oldMax, maxSize);

    // But we do want to preserve data in these

    accumulator = reallocate_and_zero_extension
        (accumulator, oldMax, maxSize);

    windowAccumulator = reallocate_and_zero_extension
        (windowAccumulator, oldMax, maxSize);

    interpolatorScale = 0;
    
    //!!! and resampler?

    if (ffts.find(fftSize) == ffts.end()) {
        ffts[fftSize] = new FFT(fftSize);
        if (sizeof(process_t) == sizeof(double)) {
            ffts[fftSize]->initDouble();
        } else {
            ffts[fftSize]->initFloat();
        }
    }
    
    fft = ffts[fftSize];
}

void
RubberBandStretcher::Impl::ChannelData::setOutbufSize(size_t outbufSize)
{
    size_t oldSize = outbuf->getSize();

//    std::cerr << "ChannelData::setOutbufSize(" << outbufSize << ") [from " << oldSize << "]" << std::endl;

    if (oldSize < outbufSize) {

        //!!! at this point we need a lock in case a different client
        //thread is calling process()

        RingBuffer<float> *newbuf = outbuf->resized(outbufSize);
        delete outbuf;
        outbuf = newbuf;
    }
}

void
RubberBandStretcher::Impl::ChannelData::setResampleBufSize(size_t sz)
{
    resamplebuf = reallocate_and_zero<float>(resamplebuf, resamplebufSize, sz);
    resamplebufSize = sz;
}

RubberBandStretcher::Impl::ChannelData::~ChannelData()
{
    delete resampler;

    deallocate(resamplebuf);

    delete inbuf;
    delete outbuf;

    deallocate(mag);
    deallocate(phase);
    deallocate(prevPhase);
    deallocate(prevError);
    deallocate(unwrappedPhase);
    deallocate(envelope);
    deallocate(freqPeak);
    deallocate(accumulator);
    deallocate(windowAccumulator);
    deallocate(fltbuf);

    for (std::map<size_t, FFT *>::iterator i = ffts.begin();
         i != ffts.end(); ++i) {
        delete i->second;
    }
}

void
RubberBandStretcher::Impl::ChannelData::reset()
{
    inbuf->reset();
    outbuf->reset();

    if (resampler) resampler->reset();

    size_t size = inbuf->getSize();

    for (size_t i = 0; i < size; ++i) {
        accumulator[i] = 0.f;
        windowAccumulator[i] = 0.f;
    }

    // Avoid dividing opening sample (which will be discarded anyway) by zero
    windowAccumulator[0] = 1.f;
    
    accumulatorFill = 0;
    prevIncrement = 0;
    chunkCount = 0;
    inCount = 0;
    inputSize = -1;
    outCount = 0;
    interpolatorScale = 0;
    unchanged = true;
    draining = false;
    outputComplete = false;
}

}
