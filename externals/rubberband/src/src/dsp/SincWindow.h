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

#ifndef _RUBBERBAND_SINC_WINDOW_H_
#define _RUBBERBAND_SINC_WINDOW_H_

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <map>

#include "system/sysutils.h"
#include "system/VectorOps.h"
#include "system/Allocators.h"

namespace RubberBand {

template <typename T>
class SincWindow
{
public:
    /**
     * Construct a sinc windower which produces a window of size n
     * containing the values of sinc(x) with x=0 at index n/2, such
     * that the distance from -pi to pi (the point at which the sinc
     * function first crosses zero, for negative and positive
     * arguments respectively) is p samples.
     */
    SincWindow(int n, int p) : m_size(n), m_p(p), m_cache(0) {
        encache();
    }
    SincWindow(const SincWindow &w) : m_size(w.m_size), m_p(w.m_p), m_cache(0) {
        encache();
    }
    SincWindow &operator=(const SincWindow &w) {
	if (&w == this) return *this;
	m_size = w.m_size;
	m_p = w.m_p;
        m_cache = 0;
	encache();
	return *this;
    }
    virtual ~SincWindow() {
        deallocate(m_cache);
    }

    /**
     * Regenerate the sinc window with the same size, but a new scale
     * (the p value is interpreted as for the argument of the same
     * name to the constructor).  If p is unchanged from the previous
     * value, do nothing (quickly).
     */
    inline void rewrite(int p) {
        if (m_p == p) return;
        m_p = p;
        encache();
    }
    
    inline void cut(T *const R__ dst) const {
        v_multiply(dst, m_cache, m_size);
    }

    inline void cut(const T *const R__ src, T *const R__ dst) const {
        v_multiply(dst, src, m_cache, m_size);
    }

    inline void add(T *const R__ dst, T scale) const {
        v_add_with_gain(dst, m_cache, m_size, scale);
    }

    inline T getArea() const { return m_area; }
    inline T getValue(int i) const { return m_cache[i]; }

    inline int getSize() const { return m_size; }
    inline int getP() const { return m_p; }

    /**
     * Write a sinc window of size n with scale p (the p value is
     * interpreted as for the argument of the same name to the
     * constructor).
     */
    static
    void write(T *const R__ dst, const int n, const int p) {
        const int half = n/2;
        writeHalf(dst, n, p);
        int target = half - 1;
        for (int i = half + 1; i < n; ++i) {
            dst[target--] = dst[i];
        }
        const T twopi = 2. * M_PI;
        T arg = T(half) * twopi / p;
        dst[0] = sin(arg) / arg;
    }

protected:
    int m_size;
    int m_p;
    T *R__ m_cache;
    T m_area;

    /**
     * Write the positive half (i.e. n/2 to n-1) of a sinc window of
     * size n with scale p (the p value is interpreted as for the
     * argument of the same name to the constructor). The negative
     * half (indices 0 to n/2-1) of dst is left unchanged.
     */
    static
    void writeHalf(T *const R__ dst, const int n, const int p) {
        const int half = n/2;
        const T twopi = 2. * M_PI;
        dst[half] = T(1.0);
        for (int i = 1; i < half; ++i) {
            T arg = T(i) * twopi / p;
            dst[half+i] = sin(arg) / arg;
        }
    }
    
    void encache() {
        if (!m_cache) {
            m_cache = allocate<T>(m_size);
        }

        write(m_cache, m_size, m_p);
	
        m_area = 0;
        for (int i = 0; i < m_size; ++i) {
            m_area += m_cache[i];
        }
        m_area /= m_size;
    }
};

}

#endif
