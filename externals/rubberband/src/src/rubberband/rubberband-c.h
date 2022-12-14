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

#ifndef _RUBBERBAND_C_API_H_
#define _RUBBERBAND_C_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#define RUBBERBAND_VERSION "1.7"
#define RUBBERBAND_API_MAJOR_VERSION 2
#define RUBBERBAND_API_MINOR_VERSION 5

/**
 * This is a C-linkage interface to the Rubber Band time stretcher.
 * 
 * This is a wrapper interface: the primary interface is in C++ and is
 * defined and documented in RubberBandStretcher.h.  The library
 * itself is implemented in C++, and requires C++ standard library
 * support even when using the C-linkage API.
 *
 * Please see RubberBandStretcher.h for documentation.
 *
 * If you are writing to the C++ API, do not include this header.
 */

enum RubberBandOption {

    RubberBandOptionProcessOffline       = 0x00000000,
    RubberBandOptionProcessRealTime      = 0x00000001,

    RubberBandOptionStretchElastic       = 0x00000000,
    RubberBandOptionStretchPrecise       = 0x00000010,
    
    RubberBandOptionTransientsCrisp      = 0x00000000,
    RubberBandOptionTransientsMixed      = 0x00000100,
    RubberBandOptionTransientsSmooth     = 0x00000200,

    RubberBandOptionDetectorCompound     = 0x00000000,
    RubberBandOptionDetectorPercussive   = 0x00000400,
    RubberBandOptionDetectorSoft         = 0x00000800,

    RubberBandOptionPhaseLaminar         = 0x00000000,
    RubberBandOptionPhaseIndependent     = 0x00002000,
    
    RubberBandOptionThreadingAuto        = 0x00000000,
    RubberBandOptionThreadingNever       = 0x00010000,
    RubberBandOptionThreadingAlways      = 0x00020000,

    RubberBandOptionWindowStandard       = 0x00000000,
    RubberBandOptionWindowShort          = 0x00100000,
    RubberBandOptionWindowLong           = 0x00200000,

    RubberBandOptionSmoothingOff         = 0x00000000,
    RubberBandOptionSmoothingOn          = 0x00800000,

    RubberBandOptionFormantShifted       = 0x00000000,
    RubberBandOptionFormantPreserved     = 0x01000000,

    RubberBandOptionPitchHighQuality     = 0x00000000,
    RubberBandOptionPitchHighSpeed       = 0x02000000,
    RubberBandOptionPitchHighConsistency = 0x04000000,

    RubberBandOptionChannelsApart        = 0x00000000,
    RubberBandOptionChannelsTogether     = 0x10000000,
};

typedef int RubberBandOptions;

struct RubberBandState_;
typedef struct RubberBandState_ *RubberBandState;

extern RubberBandState rubberband_new(unsigned int sampleRate,
                                      unsigned int channels,
                                      RubberBandOptions options,
                                      double initialTimeRatio,
                                      double initialPitchScale);

extern void rubberband_delete(RubberBandState);

extern void rubberband_reset(RubberBandState);

extern void rubberband_set_time_ratio(RubberBandState, double ratio);
extern void rubberband_set_pitch_scale(RubberBandState, double scale);

extern double rubberband_get_time_ratio(const RubberBandState);
extern double rubberband_get_pitch_scale(const RubberBandState);

extern unsigned int rubberband_get_latency(const RubberBandState);

extern void rubberband_set_transients_option(RubberBandState, RubberBandOptions options);
extern void rubberband_set_detector_option(RubberBandState, RubberBandOptions options);
extern void rubberband_set_phase_option(RubberBandState, RubberBandOptions options);
extern void rubberband_set_formant_option(RubberBandState, RubberBandOptions options);
extern void rubberband_set_pitch_option(RubberBandState, RubberBandOptions options);

extern void rubberband_set_expected_input_duration(RubberBandState, unsigned int samples);

extern unsigned int rubberband_get_samples_required(const RubberBandState);

extern void rubberband_set_max_process_size(RubberBandState, unsigned int samples);
extern void rubberband_set_key_frame_map(RubberBandState, unsigned int keyframecount, unsigned int *from, unsigned int *to);

extern void rubberband_study(RubberBandState, const float *const *input, unsigned int samples, int final);
extern void rubberband_process(RubberBandState, const float *const *input, unsigned int samples, int final);

extern int rubberband_available(const RubberBandState);
extern unsigned int rubberband_retrieve(const RubberBandState, float *const *output, unsigned int samples);

extern unsigned int rubberband_get_channel_count(const RubberBandState);

extern void rubberband_calculate_stretch(RubberBandState);

extern void rubberband_set_debug_level(RubberBandState, int level);
extern void rubberband_set_default_debug_level(int level);

#ifdef __cplusplus
}
#endif

#endif
