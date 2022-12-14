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

#include "StretcherImpl.h"

namespace RubberBand {


RubberBandStretcher::RubberBandStretcher(size_t sampleRate,
                                         size_t channels,
                                         Options options,
                                         double initialTimeRatio,
                                         double initialPitchScale) :
    m_d(new Impl(sampleRate, channels, options,
                 initialTimeRatio, initialPitchScale))
{
}

RubberBandStretcher::~RubberBandStretcher()
{
    delete m_d;
}

void
RubberBandStretcher::reset()
{
    m_d->reset();
}

void
RubberBandStretcher::setTimeRatio(double ratio)
{
    m_d->setTimeRatio(ratio);
}

void
RubberBandStretcher::setPitchScale(double scale)
{
    m_d->setPitchScale(scale);
}

double
RubberBandStretcher::getTimeRatio() const
{
    return m_d->getTimeRatio();
}

double
RubberBandStretcher::getPitchScale() const
{
    return m_d->getPitchScale();
}

size_t
RubberBandStretcher::getLatency() const
{
    return m_d->getLatency();
}

void
RubberBandStretcher::setTransientsOption(Options options) 
{
    m_d->setTransientsOption(options);
}

void
RubberBandStretcher::setDetectorOption(Options options) 
{
    m_d->setDetectorOption(options);
}

void
RubberBandStretcher::setPhaseOption(Options options) 
{
    m_d->setPhaseOption(options);
}

void
RubberBandStretcher::setFormantOption(Options options)
{
    m_d->setFormantOption(options);
}

void
RubberBandStretcher::setPitchOption(Options options)
{
    m_d->setPitchOption(options);
}

void
RubberBandStretcher::setExpectedInputDuration(size_t samples) 
{
    m_d->setExpectedInputDuration(samples);
}

void
RubberBandStretcher::setMaxProcessSize(size_t samples)
{
    m_d->setMaxProcessSize(samples);
}

void
RubberBandStretcher::setKeyFrameMap(const std::map<size_t, size_t> &mapping)
{
    m_d->setKeyFrameMap(mapping);
}

size_t
RubberBandStretcher::getSamplesRequired() const
{
    return m_d->getSamplesRequired();
}

void
RubberBandStretcher::study(const float *const *input, size_t samples,
                           bool final)
{
    m_d->study(input, samples, final);
}

void
RubberBandStretcher::process(const float *const *input, size_t samples,
                             bool final)
{
    m_d->process(input, samples, final);
}

int
RubberBandStretcher::available() const
{
    return m_d->available();
}

size_t
RubberBandStretcher::retrieve(float *const *output, size_t samples) const
{
    return m_d->retrieve(output, samples);
}

float
RubberBandStretcher::getFrequencyCutoff(int n) const
{
    return m_d->getFrequencyCutoff(n);
}

void
RubberBandStretcher::setFrequencyCutoff(int n, float f) 
{
    m_d->setFrequencyCutoff(n, f);
}

size_t
RubberBandStretcher::getInputIncrement() const
{
    return m_d->getInputIncrement();
}

std::vector<int>
RubberBandStretcher::getOutputIncrements() const
{
    return m_d->getOutputIncrements();
}

std::vector<float>
RubberBandStretcher::getPhaseResetCurve() const
{
    return m_d->getPhaseResetCurve();
}

std::vector<int>
RubberBandStretcher::getExactTimePoints() const
{
    return m_d->getExactTimePoints();
}

size_t
RubberBandStretcher::getChannelCount() const
{
    return m_d->getChannelCount();
}

void
RubberBandStretcher::calculateStretch()
{
    m_d->calculateStretch();
}

void
RubberBandStretcher::setDebugLevel(int level)
{
    m_d->setDebugLevel(level);
}

void
RubberBandStretcher::setDefaultDebugLevel(int level)
{
    Impl::setDefaultDebugLevel(level);
}

}

