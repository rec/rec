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

#ifndef _MOVING_MEDIAN_H_
#define _MOVING_MEDIAN_H_

#include "SampleFilter.h"

#include "system/Allocators.h"

#include <algorithm>

namespace RubberBand
{

template <typename T>
class MovingMedian : public SampleFilter<T>
{
    typedef SampleFilter<T> P;

public:
    MovingMedian(int size, float percentile = 50.f) :
        SampleFilter<T>(size),
	m_frame(allocate_and_zero<T>(size)),
	m_sorted(allocate_and_zero<T>(size)),
	m_sortend(m_sorted + P::m_size - 1) {
        setPercentile(percentile);
    }

    ~MovingMedian() { 
	deallocate(m_frame);
	deallocate(m_sorted);
    }

    void setPercentile(float p) {
        m_index = int((P::m_size * p) / 100.f);
        if (m_index >= P::m_size) m_index = P::m_size-1;
        if (m_index < 0) m_index = 0;
    }

    void push(T value) {
	drop(m_frame[0]);
	v_move(m_frame, m_frame+1, P::m_size-1);
	m_frame[P::m_size-1] = value;
	put(value);
    }

    T get() const {
	return m_sorted[m_index];
    }

    void reset() {
	v_zero(m_frame, P::m_size);
	v_zero(m_sorted, P::m_size);
    }

private:
    T *const m_frame;
    T *const m_sorted;
    T *const m_sortend;
    int m_index;

    void put(T value) {
	// precondition: m_sorted contains m_size-1 values, packed at start
	// postcondition: m_sorted contains m_size values, one of which is value
	T *index = std::lower_bound(m_sorted, m_sortend, value);
	v_move(index + 1, index, m_sortend - index);
	*index = value;
    }

    void drop(T value) {
	// precondition: m_sorted contains m_size values, one of which is value
	// postcondition: m_sorted contains m_size-1 values, packed at start
	T *index = std::lower_bound(m_sorted, m_sortend + 1, value);
	assert(*index == value);
	v_move(index, index + 1, m_sortend - index);
	*m_sortend = T(0);
    }
};

}

#endif

