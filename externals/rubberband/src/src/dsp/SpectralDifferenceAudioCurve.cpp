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

#include "SpectralDifferenceAudioCurve.h"

#include "system/Allocators.h"
#include "system/VectorOps.h"

namespace RubberBand
{


SpectralDifferenceAudioCurve::SpectralDifferenceAudioCurve(Parameters parameters) :
    AudioCurveCalculator(parameters)
{
    m_mag = allocate<double>(m_lastPerceivedBin + 1);
    m_tmpbuf = allocate<double>(m_lastPerceivedBin + 1);
    v_zero(m_mag, m_lastPerceivedBin + 1);
}

SpectralDifferenceAudioCurve::~SpectralDifferenceAudioCurve()
{
    deallocate(m_mag);
    deallocate(m_tmpbuf);
}

void
SpectralDifferenceAudioCurve::reset()
{
    v_zero(m_mag, m_lastPerceivedBin + 1);
}

void
SpectralDifferenceAudioCurve::setFftSize(int newSize)
{
    deallocate(m_tmpbuf);
    deallocate(m_mag);
    AudioCurveCalculator::setFftSize(newSize);
    m_mag = allocate<double>(m_lastPerceivedBin + 1);
    m_tmpbuf = allocate<double>(m_lastPerceivedBin + 1);
    reset();
}

float
SpectralDifferenceAudioCurve::processFloat(const float *R__ mag, int increment)
{
    double result = 0.0;

    const int hs1 = m_lastPerceivedBin + 1;

    v_convert(m_tmpbuf, mag, hs1);
    v_square(m_tmpbuf, hs1);
    v_subtract(m_mag, m_tmpbuf, hs1);
    v_abs(m_mag, hs1);
    v_sqrt(m_mag, hs1);
    
    for (int i = 0; i < hs1; ++i) {
        result += m_mag[i];
    }

    v_copy(m_mag, m_tmpbuf, hs1);
    return result;
}

double
SpectralDifferenceAudioCurve::processDouble(const double *R__ mag, int increment)
{
    double result = 0.0;

    const int hs1 = m_lastPerceivedBin + 1;

    v_convert(m_tmpbuf, mag, hs1);
    v_square(m_tmpbuf, hs1);
    v_subtract(m_mag, m_tmpbuf, hs1);
    v_abs(m_mag, hs1);
    v_sqrt(m_mag, hs1);
    
    for (int i = 0; i < hs1; ++i) {
        result += m_mag[i];
    }

    v_copy(m_mag, m_tmpbuf, hs1);
    return result;
}

}

