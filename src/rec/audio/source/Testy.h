#pragma once

#include <gtest/gtest.h>

#include "rec/base/base.h"

using namespace juce;

namespace rec {
namespace audio {
namespace source {

class Testy : public PositionableAudioSource {
  public:
    static const int SIZE = 128;
    Testy() : position_(0) {}

    virtual void getNextAudioBlock(const AudioSourceChannelInfo& i) {
        for (int c = 0; c < i.buffer->getNumChannels(); ++c) {
            for (int s = 0; s < i.numSamples; ++s) {
                *i.buffer->getWritePointer(c, s + i.startSample) =
                        getSample(position_ + s);
            }
        }
        position_ += i.numSamples;
    }

    static float getSample(int64 p) { return (p % SIZE) / (1.0 * SIZE); }

    virtual int64 getTotalLength() const { return SIZE; }

    virtual int64 getNextReadPosition() const { return position_; }
    virtual void setNextReadPosition(int64 p) { position_ = p; }

    virtual bool isLooping() const { return true; }
    virtual void setLooping(bool looping) {}
    virtual void prepareToPlay(int64 s, double r) {}
    virtual void prepareToPlay(int s, double r) {}  // why this?
    virtual void releaseResources() {}

    int64 position_;

    static float expectNear(PositionableAudioSource* s,
                            float delta,
                            int channels) {
        Testy t;
        return expectNear(s, &t, delta, channels);
    }

    static float expectNear(PositionableAudioSource* s0,
                            PositionableAudioSource* s1,
                            float delta,
                            int channels) {
        int64 length = std::min(s0->getTotalLength(), s1->getTotalLength());
        EXPECT_EQ(s0->getTotalLength(), s1->getTotalLength());

        float maxDelta = 0.0;

        std::unique_ptr<AudioSampleBuffer> buffer[2];

        for (int i = 0; i < 2; ++i) {
            buffer[i].reset(new AudioSampleBuffer(channels, length));

            AudioSourceChannelInfo info;
            info.numSamples = length;
            info.startSample = 0;
            info.buffer = buffer[i].get();

            (i ? s1 : s0)->getNextAudioBlock(info);
        }

        for (int c = 0; c < channels; ++c) {
            for (int i = 0; i < length; ++i) {
                float samples[] = { *buffer[0]->getReadPointer(c, i),
                    *buffer[1]->getReadPointer(c, i) };
                EXPECT_NEAR(samples[0], samples[1], delta)
                << "At sample " << i << " channel " << c;
                maxDelta = std::max(maxDelta, fabsf(samples[0] - samples[1]));
            }
        }

        EXPECT_LT(maxDelta, delta);
        return maxDelta;
    }
};

}  // namespace source
}  // namespace audio
}  // namespace rec
