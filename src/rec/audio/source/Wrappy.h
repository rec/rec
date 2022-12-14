#pragma once

#include "rec/audio/Audio.h"

namespace rec {
namespace audio {
namespace source {

class Wrappy : public PositionableAudioSource {
  public:
    explicit Wrappy(PositionableAudioSource* s = nullptr);
    virtual int64 getTotalLength() const { return source()->getTotalLength(); }

    virtual bool isLooping() const { return source()->isLooping(); }
    virtual void setLooping(bool looping) { source()->setLooping(looping); }

    virtual void prepareToPlay(int s, double r);
    virtual void releaseResources() { source()->releaseResources(); }

    SampleTime mod(SampleTime x) const;

    virtual int64 getNextReadPosition() const;
    virtual void setNextReadPosition(int64 p);
    virtual void getNextAudioBlock(const juce::AudioSourceChannelInfo& info);

    virtual PositionableAudioSource* source() const;
    virtual void setSource(PositionableAudioSource* s);
    void swap(std::unique_ptr<PositionableAudioSource>* other);

  protected:
    virtual PositionableAudioSource* getSource() const;
    CriticalSection lock_;

    SampleTime position_;
    std::unique_ptr<PositionableAudioSource> source_;

    bool prepared_;

  private:
    DISALLOW_COPY_ASSIGN_AND_LEAKS(Wrappy);
};

}  // namespace source
}  // namespace audio
}  // namespace rec
