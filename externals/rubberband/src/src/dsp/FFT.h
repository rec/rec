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

#ifndef _RUBBERBAND_FFT_H_
#define _RUBBERBAND_FFT_H_

#include "system/sysutils.h"

namespace RubberBand {

class FFTImpl;

/**
 * Provide the basic FFT computations we need, using one of a set of
 * candidate FFT implementations (depending on compile flags).
 *
 * Implements real->complex FFTs of power-of-two sizes only.  Note
 * that only the first half of the output signal is returned (the
 * complex conjugates half is omitted), so the "complex" arrays need
 * room for size/2+1 elements.
 *
 * The "interleaved" functions use the format sometimes called CCS --
 * size/2+1 real+imaginary pairs.  So, the array elements at indices 1
 * and size+1 will always be zero (since the signal is real).
 *
 * This class is reentrant but not thread safe: use a separate
 * instance per thread, or use a mutex.
 */

class FFT
{
public:
    enum Exception { InvalidSize };

    FFT(int size, int debugLevel = 0); // may throw InvalidSize
    ~FFT();

    void forward(const double *R__ realIn, double *R__ realOut, double *R__ imagOut);
    void forwardInterleaved(const double *R__ realIn, double *R__ complexOut);
    void forwardPolar(const double *R__ realIn, double *R__ magOut, double *R__ phaseOut);
    void forwardMagnitude(const double *R__ realIn, double *R__ magOut);

    void forward(const float *R__ realIn, float *R__ realOut, float *R__ imagOut);
    void forwardInterleaved(const float *R__ realIn, float *R__ complexOut);
    void forwardPolar(const float *R__ realIn, float *R__ magOut, float *R__ phaseOut);
    void forwardMagnitude(const float *R__ realIn, float *R__ magOut);

    void inverse(const double *R__ realIn, const double *R__ imagIn, double *R__ realOut);
    void inverseInterleaved(const double *R__ complexIn, double *R__ realOut);
    void inversePolar(const double *R__ magIn, const double *R__ phaseIn, double *R__ realOut);
    void inverseCepstral(const double *R__ magIn, double *R__ cepOut);

    void inverse(const float *R__ realIn, const float *R__ imagIn, float *R__ realOut);
    void inverseInterleaved(const float *R__ complexIn, float *R__ realOut);
    void inversePolar(const float *R__ magIn, const float *R__ phaseIn, float *R__ realOut);
    void inverseCepstral(const float *R__ magIn, float *R__ cepOut);

    // Calling one or both of these is optional -- if neither is
    // called, the first call to a forward or inverse method will call
    // init().  You only need call these if you don't want to risk
    // expensive allocations etc happening in forward or inverse.
    void initFloat();
    void initDouble();

    static void tune();

protected:
    FFTImpl *d;
    static int m_method;
};

}

#endif

