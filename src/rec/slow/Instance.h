#pragma once

#include "rec/app/Window.h"
#include "rec/audio/Audio.h"
#include "rec/base/SampleRate.h"
#include "rec/base/SampleTime.h"
#include "rec/data/Undoable.h"
#include "rec/gui/GetHelpText.h"
#include "rec/util/thread/Trash.h"

namespace rec { namespace audio { class Device; }}
namespace rec { namespace audio { namespace source { class Player; }}}
namespace rec { namespace audio { namespace util { class BufferFiller; }}}
namespace rec { namespace audio { namespace util { class CurrentTimeBase; }}}
namespace rec { namespace command { class MidiCommandMap; }}
namespace rec { namespace gui { class LookAndFeel; }}

namespace rec {

// Test stuff!
namespace program { class JuceModel; }

namespace slow {

class Components;
class CurrentFile;
class CurrentTime;
class GuiListener;
class MouseListener;
class SlowWindow;

class SlowProgram;

// A single instance of the Slow program.  Right now there's only one per
// application but in future there might be more than one.
class Instance {
  public:
    explicit Instance(app::Window*);
    ~Instance();

    void init();
    bool startup();
    void shutdown();

    const VirtualFile file() const;
    SampleTime time() const;
    SampleTime length() const;
    bool isPlaying() const;
    void updateGui();
    bool empty() const;
    audio::Source* makeSource() const;
    SampleRate getSourceSampleRate() const;
    void setProto(const Message&, data::Undoable undoable = data::CAN_UNDO);
    void reset();

    app::Window* window_;
    CriticalSection lock_;

    std::unique_ptr<audio::Device> device_;
    std::unique_ptr<audio::util::BufferFiller> bufferFiller_;
    std::unique_ptr<CurrentFile> currentFile_;

    std::unique_ptr<audio::source::Player> player_;
    std::unique_ptr<CurrentTime> currentTime_;

    std::unique_ptr<MouseListener> mouseListener_;
    std::unique_ptr<GuiListener> guiListener_;
    thread_ptr<Thread> fillerThread_;
    std::unique_ptr<gui::LookAndFeel> lookAndFeel_;
    std::unique_ptr<command::MidiCommandMap> midiCommandMap_;
    std::unique_ptr<Components> components_;

  private:
    std::unique_ptr<SlowProgram> slowProgram_;
    std::unique_ptr<program::JuceModel> juceModel_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(Instance);
};

Instance* getInstance();
const VirtualFile getInstanceFile();

}  // namespace slow
}  // namespace rec
