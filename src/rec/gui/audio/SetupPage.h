#pragma once

#include "rec/base/Base.h"

namespace rec {

namespace audio { class Device; }

namespace gui {
namespace audio {

class SetupPage : public Component {
  public:
    explicit SetupPage(rec::audio::Device* device);
    void paint(Graphics& g);

    void resized();
    void show(Component* comp);

  private:
    juce::AudioDeviceSelectorComponent deviceSelector_;
    rec::audio::Device* device_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(SetupPage);
};


}  // namespace rec
}  // namespace gui
}  // namespace audio
