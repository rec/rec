#include "rec/app/GenericApplication.h"

#include "rec/app/Files.h"
#include "rec/app/Window.h"
#include "rec/audio/format/mpg123/Mpg123.h"
#include "rec/gui/Dialog.h"
#include "rec/gui/LookAndFeel.h"
#include "rec/util/Undo.h"
#include "rec/util/thread/MakeThread.h"

namespace rec {
namespace app {

GenericApplication::GenericApplication(ApplicationFunction i,
                                       ApplicationFunction s)
        : initializer_(i), shutdown_(s), enable_(ENABLE),
            autoCheckForUpdates_(true) {
}

GenericApplication::~GenericApplication() {}

void GenericApplication::initialise(const String&) {
    setApplicationName(name());

    audio::format::mpg123::initializeOnce();
    if (initializer_)
        initializer_(this);
    window_.reset(createWindow());
    window_->initialise();
    gui::LookAndFeel::getDefaultLookAndFeel().setUsingNativeAlertWindows(true);

    if (autoCheckForUpdates())
        downloadNewVersionIfNeeded(version(), name());

    thread::runInNewThread("startup thread",
                           STARTUP_THREAD_PRIORITY,
                           window_.get(),
                           &Window::startup);
    LOG(INFO) << name() << ": initialise finished.";

    // FLAGS_log_dir = str(File::getSpecialLocation(
    //     File::userApplicationDataDirectory).getChildFile("Logs"));
}

void GenericApplication::shutdown() {
    gui::dialog::shutdownDialog();
    if (window_) {
        window_->shutdown();
        window_.reset();
    }

    util::thread::trash::waitForAllThreadsToExit(1000);
    if (shutdown_)
        shutdown_(this);

    LOG(INFO) << name() << ": shutdown finished.";
}

void GenericApplication::systemRequestedQuit() {
    if (enable_ == ENABLE)
        window_->systemRequestedQuit();
}

void GenericApplication::anotherInstanceStarted(const String& s) {
    window_->anotherInstanceStarted(s);
}

}  // namespace app
}  // namespace rec
