#include "rec/audio/util/ConvertSample.h"

namespace rec {
namespace audio {

namespace {

enum : long long {
    bit8 = 0x100LL,
    bit16 = bit8 * bit8,
    bit24 = bit8 * bit16,
    bit32 = bit8 * bit24,
    bit40 = bit8 * bit32,
    bit48 = bit8 * bit40,
    bit56 = bit8 * bit48
};

}  // namespace

template <> void convertSample<int8, int8>(int8 f, int8 *t) {
    *t = f;
}

template <> void convertSample<int8, int16>(int8 f, int16 *t) {
    *t = f * bit8;
}

template <> void convertSample<int8, int24>(int8 f, int24 *t) {
    *t = f * bit16;
}

template <> void convertSample<int8, int32>(int8 f, int32 *t) {
    *t = static_cast<int32>(f * bit24);
}

template <> void convertSample<int8, int64>(int8 f, int64 *t) {
    *t = f * bit56;
}


template <> void convertSample<int16, int8>(int16 f, int8 *t) {
    *t = static_cast<int8>(f / bit8);
}

template <> void convertSample<int16, int16>(int16 f, int16 *t) {
    *t = f;
}

template <> void convertSample<int16, int24>(int16 f, int24 *t) {
    *t = f * bit8;
}

template <> void convertSample<int16, int32>(int16 f, int32 *t) {
    *t = static_cast<int16>(f * bit16);
}

template <> void convertSample<int16, int64>(int16 f, int64 *t) {
    *t = f * bit48;
}


template <> void convertSample<int24, int8>(int24 f, int8 *t) {
    *t = static_cast<int8>(f / bit16);
}

template <> void convertSample<int24, int16>(int24 f, int16 *t) {
    *t = static_cast<int16>(f / bit8);
}

template <> void convertSample<int24, int24>(int24 f, int24 *t) {
    *t = f;
}

template <> void convertSample<int24, int32>(int24 f, int32 *t) {
    *t = static_cast<int32>(f * bit8);
}

template <> void convertSample<int24, int64>(int24 f, int64 *t) {
    *t = f * bit40;
}


template <> void convertSample<int32, int8>(int32 f, int8 *t) {
    *t = static_cast<int8>(f / bit24);
}

template <> void convertSample<int32, int16>(int32 f, int16 *t) {
    *t = static_cast<int16>(f / bit16);
}

template <> void convertSample<int32, int24>(int32 f, int24 *t) {
    *t = static_cast<int32>(f / bit8);
}

template <> void convertSample<int32, int32>(int32 f, int32 *t) {
    *t = f;
}

template <> void convertSample<int32, int64>(int32 f, int64 *t) {
    *t = f * bit32;
}


template <> void convertSample<int64, int8>(int64 f, int8 *t) {
    *t = static_cast<int8>(f / bit56);
}

template <> void convertSample<int64, int16>(int64 f, int16 *t) {
    *t = static_cast<int16>(f / bit48);
}

template <> void convertSample<int64, int24>(int64 f, int24 *t) {
    *t = f / bit40;
}

template <> void convertSample<int64, int32>(int64 f, int32 *t) {
    *t = static_cast<int32>(f / bit32);
}

template <> void convertSample<int64, int64>(int64 f, int64 *t) {
    *t = f;
}

static const float HALF_SHORT_RANGE = 32768.0f;
static const float FULL_SHORT_RANGE = (2.0f * HALF_SHORT_RANGE - 1.0f);

template <> void convertSample<short, float>(const short from, float* to) {
    *to = (from + HALF_SHORT_RANGE) / FULL_SHORT_RANGE * 2.0f - 1.0f;
}

template <> void convertSample<float, short>(const float from, short* to) {
    float f = FULL_SHORT_RANGE * (1.0f + from) / 2.0f - HALF_SHORT_RANGE;
    *to = static_cast<short>(std::min(floorf(f), HALF_SHORT_RANGE - 1.0f));
}

static const int32 MAX_VALUE = 0x7fffffff;;
static const double DIVIDER = 1.0 + MAX_VALUE;

template <> void convertSample<int32, float>(const int32 from, float* to) {
    *to = static_cast<float>(from / DIVIDER);
}

template <> void convertSample<float, int32>(const float from, int32* to) {
    *to = static_cast<int32>(from * MAX_VALUE);
}

template <> void convertSample<float, float>(float f, float *t) {
    *t = f;
}

template <> void convertSample<double, double>(double f, double *t) {
    *t = f;
}

template <> void convertSample<double, float>(double f, float *t) {
    *t = static_cast<float>(f);
}

template <> void convertSample<float, double>(float f, double *t) {
    *t = f;
}

}  // namespace audio
}  // namespace rec
