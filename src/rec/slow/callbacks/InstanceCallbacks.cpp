#include "rec/slow/callbacks/InstanceCallbacks.h"

#include "rec/app/DownloadVersion.h"
#include "rec/app/Files.h"
#include "rec/app/GenericApplication.h"
#include "rec/audio/Audio.h"
#include "rec/audio/source/Player.h"
#include "rec/base/Trans.h"
#include "rec/data/Data.h"
#include "rec/data/DataOps.h"
#include "rec/data/yaml/Yaml.h"
#include "rec/gui/Dialog.h"
#include "rec/gui/audio/Loops.h"
#include "rec/gui/audio/SetupPage.h"
#include "rec/program/Program.h"
#include "rec/slow/Components.h"
#include "rec/slow/CurrentFile.h"
#include "rec/slow/CurrentTime.h"
#include "rec/slow/MouseListener.h"
#include "rec/slow/SlowWindow.h"
#include "rec/slow/callbacks/CallbackUtils.h"
#include "rec/slow/callbacks/CommandEditors.h"
#include "rec/slow/callbacks/RepeatedCallbacks.h"
#include "rec/slow/callbacks/ExportFile.h"
#include "rec/slow/commands/Command.pb.h"
#include "rec/util/LoopPoint.h"
#include "rec/util/file/VirtualFile.h"
#include "rec/util/range/MakeRange.h"
#include "rec/widget/waveform/Waveform.h"
#include "rec/widget/waveform/Viewport.h"
#include "rec/widget/waveform/Zoom.h"

TRAN(NO_DOWNLOAD_FOUND, "Your Version Of SlowGold Is Up-To-Date");
TRAN(NO_DOWNLOAD_FOUND_FULL, "Your version of SlowGold, %s, is up-to-date.");

TRAN(CONFIRM_CLEAR_ALL_SETTINGS, "Clearing All Settings For All Tracks");

TRAN(CONFIRM_CLEAR_ALL_SETTINGS_FULL, "You want to clear *all* settings, and quit "
                                                                            "SlowGold.  Is this OK?");

TRAN(CONFIRM_CLEAR_SETTINGS_FOR_THIS_TRACK, "Clearing Settings For This Track Only");

TRAN(CONFIRM_CLEAR_SETTINGS_FOR_THIS_TRACK_FULL, "You want to clear settings for this "
                                                                                                  "track only, and quit the "
                                                                                                  "program.  Is this OK?");

TRAN(CLEAR_FAILED, "Unable To Clear Settings");

TRAN(CLEAR_FAILED_FULL, "Sorry, there was an error clearing the settings. "
                                                "Please report this to support@worldwidewoodshed.com.");

namespace rec {
namespace slow {

using namespace juce;
using namespace rec::audio::util;
using namespace rec::widget::waveform;

namespace {

const bool QUIT_EVEN_IF_CLEAR_FAILS = false;
const int SELECTION_WIDTH_PORTION = 20;

void aboutThisProgram() {
    getInstance()->window_->startAboutWindow();
}

void addLoopPoint() {
    Instance* i = getInstance();
    widget::waveform::addLoopPointToViewport(i->file(),
                                                                                      i->player_->getTime());
}

void zoomOut() {
    Instance* i = getInstance();
    widget::waveform::zoomScale(i->file(), i->length(),
                                                            i->getSourceSampleRate(), -1.0);
}

void zoomOutFull() {
    Instance* i = getInstance();
    widget::waveform::zoomOutFull(i->file(), i->length());
}

void zoomToSelection() {
    Instance* i = getInstance();
    SampleRange range = rec::util::makeRange<SampleTime>(i->currentTime_->timeSelection());
    SampleTime pad(range.size() / SELECTION_WIDTH_PORTION);
    SampleTime len(i->length().get());
    if (len) {
        widget::waveform::zoomTo(i->file(),
                                                          i->length(),
                                                          i->getSourceSampleRate(),
                                                          std::max(SampleTime(0), range.begin_ - pad),
                                                          std::min(len, range.end_ + pad));
    }
}

void audioPreferences() {
    Instance* i = getInstance();
    i->device_->setupPage_->show(i->components_->topComponent());
}

void closeFile() {
    Instance* i = getInstance();
    i->currentFile_->setVirtualFile(data::noData(), false);
}

void copyFile() {
    // Instance* i = getInstance();
    // if (gui::dialog::saveVirtualFile(
}

void moveFile() {
}

void open() {
    Instance* i = getInstance();
    gui::dialog::openOneAudioFile(i->currentFile_.get());
}

void toggleStartStop() {
    Instance* i = getInstance();
    if (!i->empty())
        i->player_->toggle();
}

void checkForUpdates() {
    Instance* i = getInstance();
    LookAndFeel::getDefaultLookAndFeel().setUsingNativeAlertWindows(true);
    DCHECK(LookAndFeel::getDefaultLookAndFeel().isUsingNativeAlertWindows());

    if (!app::downloadNewVersionIfNeededBlocking()) {
        String msg = String::formatted(t_NO_DOWNLOAD_FOUND_FULL,
                                                                      c_str(i->window_->application()->version()));
        AlertWindow::showMessageBox(AlertWindow::InfoIcon, t_NO_DOWNLOAD_FOUND,
                                                                msg, t_OK);
    }
}

void deleteRecursivelyAndQuit(const File& dir, Instance* i,
                                                            const String& title, const String& msg) {
    LookAndFeel::getDefaultLookAndFeel().setUsingNativeAlertWindows(true);
    DCHECK(LookAndFeel::getDefaultLookAndFeel().isUsingNativeAlertWindows());

    if (!AlertWindow::showOkCancelBox(AlertWindow::InfoIcon, title, msg,
                                                                        t_OK, t_CANCEL)) {
        return;
    }
    closeFile();
    bool success = dir.deleteRecursively();
    if (QUIT_EVEN_IF_CLEAR_FAILS || success) {
        i->window_->application()->quit();
    } else {
        AlertWindow::showMessageBox(AlertWindow::WarningIcon, t_CLEAR_FAILED,
                                                                t_CLEAR_FAILED_FULL);
    }
}

void clearAllSettings() {
    Instance* i = getInstance();
    deleteRecursivelyAndQuit(app::getAppDirectory(), i,
                                                      t_CONFIRM_CLEAR_ALL_SETTINGS,
                                                      t_CONFIRM_CLEAR_ALL_SETTINGS_FULL);
}

void clearSettingsForThisTrack() {
    Instance* i = getInstance();
    deleteRecursivelyAndQuit(file::getShadowDirectory(i->file()), i,
                                                      t_CONFIRM_CLEAR_SETTINGS_FOR_THIS_TRACK,
                                                      t_CONFIRM_CLEAR_SETTINGS_FOR_THIS_TRACK_FULL);
}

void copyAllLoopPoints() {
    Viewport vp = data::getProto<Viewport>(getInstanceFile());
    string clipboard = yaml::write(vp.loop_points());
    SystemClipboard::copyTextToClipboard(str(clipboard));
}

void pasteOverLoopPoints() {
    string clipboard(str(SystemClipboard::getTextFromClipboard()));
    LoopPointList lpl;
    if (!yaml::read(clipboard, &lpl)) {
        beep();
        return;
    }
    const VirtualFile& vf = getInstanceFile();
    Viewport vp = data::getProto<Viewport>(vf);
    int64 length = vp.loop_points().length();
    google::protobuf::RepeatedPtrField<LoopPoint>* lp = vp.mutable_loop_points()->
        mutable_loop_point();
    lp->Clear();
    for (int i = 0; i < lpl.loop_point_size(); ++i) {
        const LoopPoint& point = lpl.loop_point(i);
        if (point.time() >= length)
            break;
        lp->Add()->CopyFrom(point);
    }

    data::setProto(vp, vf);
}

}  // namespace

using namespace rec::command;
using namespace rec::program;

void addInstanceCallbacks(Program* p) {
    using namespace rec::gui;
    using rec::gui::audio::SetupPage;
    using rec::audio::source::Player;

    addCallback(p, slow::Command::ABOUT_THIS_PROGRAM, aboutThisProgram);
    addCallback(p, slow::Command::ADD_LOOP_POINT, addLoopPoint);
    addCallback(p, slow::Command::AUDIO_PREFERENCES, audioPreferences);

    addCallback(p, slow::Command::CHECK_FOR_UPDATES, checkForUpdates);
    addCallback(p, slow::Command::CLEAR_ALL_SETTINGS, clearAllSettings);
    addCallback(p, slow::Command::CLEAR_MIDI_MAPPINGS, clearMidiMappings);
    addCallback(p, slow::Command::CLEAR_KEYBOARD_MAPPINGS, clearKeyboardMappings);

    addCallback(p, slow::Command::CLEAR_SETTINGS_FOR_THIS_TRACK,
                            clearSettingsForThisTrack);
    addCallback(p, slow::Command::CLOSE_FILE, closeFile);
    addCallback(p, slow::Command::COPY_FILE, copyFile);
    addCallback(p, slow::Command::COPY_ALL_LOOP_POINTS, copyAllLoopPoints);

    addCallback(p, slow::Command::EXPORT_FILE, exportFile);
    addCallback(p, slow::Command::EXPORT_FILE_SELECTION, exportFileSelection);

    addCallback(p, slow::Command::KEYBOARD_MAPPINGS, keyboardMappings);
    addCallback(p, slow::Command::MIDI_MAPPINGS, midiMappings);
    addCallback(p, slow::Command::MOVE_FILE, moveFile);

    addCallback(p, slow::Command::OPEN, open);

    addCallback(p, slow::Command::PASTE_OVER_LOOP_POINTS, pasteOverLoopPoints);

    addCallback(p, slow::Command::ZOOM_OUT, zoomOut);
    addCallback(p, slow::Command::ZOOM_OUT_FULL, zoomOutFull);
    addCallback(p, slow::Command::ZOOM_TO_SELECTION, zoomToSelection);
}

}  // namespace slow
}  // namespace rec
