#pragma once

#include "rec/base/RealTime.h"
#include "rec/base/SampleRate.h"

namespace rec {

struct SampleTime {
    SampleTime() {}

    // Conversion from integer types means "a sample count".
    SampleTime(int64 p) : position_(p) {}
    SampleTime(uint64 p) : position_(static_cast<int64>(p)) {}
    SampleTime(int p) : position_(p) {}
    SampleTime(uint32 p) : position_(p) {}
    SampleTime(short p) : position_(p) {}

    SampleTime(RealTime t, SampleRate rate)
            : position_(static_cast<int64>(t * rate)) {
    }

    SampleTime& operator++() { ++position_; return *this; }
    SampleTime& operator--() { --position_; return *this; }

    SampleTime operator++(int) { return position_++; }
    SampleTime operator--(int) { return position_--; }

    SampleTime& operator-=(SampleTime p) { position_ -= p; return *this; }
    SampleTime& operator+=(SampleTime p) { position_ += p; return *this; }

    const SampleTime operator+(SampleTime p) { return position_ + p; }
    const SampleTime operator-(SampleTime p) { return position_ - p; }
    const SampleTime operator+(int p) { return position_ + p; }
    const SampleTime operator-(int p) { return position_ - p; }
    const SampleTime operator+(uint32 p) { return position_ + p; }
    const SampleTime operator-(uint32 p) { return position_ - p; }
    const SampleTime operator+(int64 p) { return position_ + p; }
    const SampleTime operator-(int64 p) { return position_ - p; }
    const SampleTime operator+(uint64 p) { return position_ + p; }
    const SampleTime operator-(uint64 p) { return position_ - p; }
    const SampleTime operator-() { return -position_; }

    operator int64() const { return position_; }
    int64 get() { return position_; }

    // We shouldn't need this, but Juce sometimes wants ints.  Bug Jules!
    int toInt() const { return static_cast<int>(position_); }

  private:
    SampleTime(RealTime time);
    SampleTime(double time);

    int64 position_;

    JUCE_LEAK_DETECTOR(SampleTime);
};

}  // namespace rec
