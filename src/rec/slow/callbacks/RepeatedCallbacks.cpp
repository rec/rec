#include "rec/slow/callbacks/RepeatedCallbacks.h"

#include "rec/audio/AudioSettings.pb.h"
#include "rec/data/proto/Equals.h"
#include "rec/gui/menu/RecentFiles.pb.h"
#include "rec/program/JuceModel.h"
#include "rec/program/Program.h"
#include "rec/slow/CurrentFile.h"
#include "rec/slow/CurrentTime.h"
#include "rec/slow/GuiSettings.pb.h"
#include "rec/slow/LoopSnapshot.h"
#include "rec/slow/callbacks/CallbackUtils.h"
#include "rec/slow/commands/Command.pb.h"
#include "rec/util/LoopPoint.h"
#include "rec/util/Math.h"
#include "rec/util/thread/MakeThread.h"
#include "rec/widget/waveform/Viewport.pb.h"

namespace rec {
namespace slow {

namespace {

using namespace std;
using namespace rec::command;
using namespace rec::program;

int toIndex(int position, int32 segment, int32 size) {
    int pos = (position == command::Command::FIRST) ? 0 :
        (position == command::Command::PREVIOUS) ? segment - 1 :
        (position == command::Command::CURRENT) ? segment :
        (position == command::Command::NEXT) ? segment + 1 :
        (position == command::Command::LAST) ? size - 1 :
        (position - command::Command::LAST - 1);
    return mod(pos, size);
}

using widget::waveform::Viewport;

using LoopSnapshotFunction = void (*)(LoopSnapshot*, int32);
using SelectorFunction = bool (*)(int index, int pos, bool selected, bool all);

void loop(LoopSnapshotFunction lsf, int32 pos) {
    Instance* instance = getInstance();
    LoopSnapshot snapshot(instance);
    lsf(&snapshot, pos);
    instance->setProto(snapshot.viewport_);
    instance->currentTime_->zoomToCurrentTime();
}

void select(SelectorFunction selector, int32 pos) {
    Instance* instance = getInstance();
    LoopSnapshot snap(instance);
    LoopPointList* loops = snap.loops_;
    int segment = audio::getSegment(*loops, snap.instance_->time());
    int size = loops->loop_point_size();
    int p = toIndex(pos, segment, size);
    if (p >= size) {
        LOG(ERROR) << "size too large " << p << " >= " << size;
        beep();
        return;
    }

    bool multipleSelections = (audio::getSelectionCount(*snap.loops_) > 1);

    for (int i = 0; i < size; ++i) {
        LoopPoint* lp = loops->mutable_loop_point(i);
        lp->set_selected(selector(i, p, lp->selected(), multipleSelections));
    }
    instance->setProto(snap.viewport_);
}

template <typename Function, typename X, typename Y>
void addCallback(Program* c, CommandID id, Function f, X x, Y y) {
    c->addCallback(id, thread::functionCB(f, x, y));
}

bool selectAll(int, int, bool, bool) { return true; }
bool deselectAll(int, int, bool, bool) { return false; }
bool invertLoopSelection(int, int, bool sel, bool) { return !sel; }
bool toggleWholeSongLoop(int i, int p, bool, bool al) {
    return !al || i == p;
}

}  // namespace

void addSelectionCallbacks(Program* t) {
    addCallback(t, slow::Command::DESELECT_ALL, select, deselectAll, command::Command::CURRENT);
    addCallback(t, slow::Command::SELECT_ALL, select, selectAll, command::Command::CURRENT);
    addCallback(t, slow::Command::INVERT_LOOP_SELECTION, select, invertLoopSelection,
                            command::Command::CURRENT);
    addCallback(t, slow::Command::TOGGLE_WHOLE_SONG_LOOP, select, toggleWholeSongLoop,
                            command::Command::CURRENT);
}

namespace {

using namespace rec::widget::waveform;

const RealTime MAX_JUMP_TIME = 1.0;

void setTimeFromSegment(LoopSnapshot* snapshot, int segment) {
    Viewport viewport = data::getProto<Viewport>(snapshot->instance_->file());
    snapshot->viewport_.CopyFrom(viewport);
    snapshot->loops_ = snapshot->viewport_.mutable_loop_points();
    SampleTime time = snapshot->loops_->loop_point(segment).time();
    snapshot->instance_->currentTime_->jumpToTime(time);
}

void jump(LoopSnapshot* snap, int32 pos) {
    SampleTime time = snap->instance_->time();

    int size = snap->loops_->loop_point_size();
    int segment = audio::getSegment(*snap->loops_, time);
    int p = toIndex(pos, segment, size);
    if (p >= size) {
        LOG(ERROR) << "size too large " << p << " >= " << size;
        beep();
        return;
    }


    // Special case for "jump back";
    if (pos == command::Command::PREVIOUS &&
            (time - snap->loops_->loop_point(segment).time()) >=
            SampleTime(MAX_JUMP_TIME, snap->loops_->sample_rate())) {
        p = segment;
    }

    setTimeFromSegment(snap, p);
    snap->loops_->mutable_loop_point(p)->set_selected(true);
}

bool selectAdd(int index, int pos, bool sel, bool) { return sel || index == pos; }
bool selectOnly(int index, int pos, bool, bool) { return index == pos; }
bool toggle(int index, int pos, bool sel, bool) { return sel != (index == pos); }
bool unselect(int index, int pos, bool sel, bool) { return sel && index != pos; }

// This constant must be consistent with AllCommands.def.
static const int RECENT_MENU_REPEATS = 32;
static const int RECENT_FILE_THREAD_PRIORITY = 4;

void loadRecentFile(int i) {
    gui::RecentFiles rf = data::getProto<gui::RecentFiles>();
    if (i < 0 || i >= rf.file_size()) {
        LOG(DFATAL) << "Can't load recent, i=" << i << ", size=" << rf.file_size();
        return;
    }

    thread::runInNewThread("loadRecentFile", RECENT_FILE_THREAD_PRIORITY,
                                                  getInstance()->currentFile_.get(),
                                                  &CurrentFile::setVirtualFile,
                                                  rf.file(i).file(), true);
}

void setSaveFileType(int i) {
    using audio::AudioSettings;

    AudioSettings settings = data::getProto<AudioSettings>();
    settings.set_file_type_for_save(static_cast<AudioSettings::FileType>(i));
    data::setProto(settings);
    program::menuItemsChanged();
}

void setLanguage(int i) {
    app::AppSettings inter = data::getProto<app::AppSettings>();
    inter.set_language(static_cast<Language>(i));
    data::setProto(inter);
    program::menuItemsChanged();
}

void openPreviousFile() {
    gui::RecentFiles rf = data::getProto<gui::RecentFiles>();
    int size = rf.file_size();
    if (size) {
        if (data::equals(rf.file(0).file(), getInstanceFile())) {
            if (size > 1)
                loadRecentFile(1);
        } else {
            loadRecentFile(0);
        }
    }
}

void jumpSelected(LoopSnapshot* snap, int32 pos) {
    vector<int> selected;
    const LoopPointList& loops = *snap->loops_;
    size_t s = 0;
    bool found = false;
    int selectedSegment = audio::getSegment(loops, snap->instance_->time());

    for (int i = 0; i < loops.loop_point_size(); ++i) {
        if (!audio::getSelectionCount(loops) || loops.loop_point(i).selected()) {
            if (i == selectedSegment) {
                DCHECK(!found);
                s = selected.size();
                found = true;
            }
            selected.push_back(i);
        }
    }
    int segment = 0;
    if (found) {
        if (s >= selected.size()) {
            beep();
            return;
        }
        segment = selected[toIndex(pos, s, selected.size())];
    } else if (!selected.empty()) {
        segment = selected[0];
    }

    setTimeFromSegment(snap, segment);
}

void nudgeWithinSegment(const LoopPointList& selection, bool inc) {
    Instance* i = getInstance();

    SampleTime begin = selection.loop_point(0).time();
    SampleTime end = selection.length();
    SampleTime width = end - begin;
    SampleRate rate = i->getSourceSampleRate();
    SampleTime nudge(data::getProto<audio::AudioSettings>().time_nudge(), rate);
    nudge = std::min(nudge, SampleTime(width / 2));
    SampleTime time = i->time() + (inc ? nudge : - nudge);
    while (time < begin)
        time += width;

    while (time >= end)
        time -= width;
    i->currentTime_->jumpToTime(time);
}

void nudgeTime(bool inc) {
    LoopSnapshot s(getInstance());
    LoopPointList selection = audio::getSelected(*s.loops_, true);
    if (!selection.loop_point_size())
        selection = audio::getSelected(*s.loops_, false);

    if (selection.loop_point_size() == 1)
        nudgeWithinSegment(selection, inc);
    else
        jumpSelected(&s, inc ? command::Command::NEXT : command::Command::PREVIOUS);
}

void loopNextSegment() {
    Instance* instance = getInstance();
    VirtualFile vf = instance->file();
    Viewport vp(data::getProto<Viewport>(vf));
    LoopPointList* lpl = vp.mutable_loop_points();
    uint32 size = lpl->loop_point_size();
    if (size <= 1) {
        beep();
        return;
    }

    bool isPlaying = instance->isPlaying();
    uint32 selected = audio::getSegment(*lpl, instance->time());
    uint32 next = mod(selected + 1, size);
    for (uint32 i = 0; i < size; ++i)
        lpl->mutable_loop_point(i)->set_selected(false);

    lpl->mutable_loop_point(next)->set_selected(true);
    if (isPlaying) {
        lpl->mutable_loop_point(selected)->set_selected(true);
        instance->currentTime_->setLoopingSegment(next);
    }

    data::setProto(vp, vf);
}

void addCallback(Program* c, int32 type, int32 position,
                                  SelectorFunction f) {
    addCallback(c, type + position, select, f, position);
}

void addCallback(Program* c, int32 type, int32 position,
                                  LoopSnapshotFunction f) {
    addCallback(c, type + position, loop, f, position);
}

const int MENU_COMMAND_REPEATS = 15;

}  // namespace

void addRepeatedCallbacks(Program* t, int repeat) {
    for (int32 j = 0; j < MENU_COMMAND_REPEATS; ++j) {
        addCallback(t, slow::Command::SELECT, j, selectAdd);
        addCallback(t, slow::Command::SELECT_ONLY, j, selectOnly);
        addCallback(t, slow::Command::TOGGLE_SELECTION, j, toggle);
        addCallback(t, slow::Command::UNSELECT, j, unselect);

        addCallback(t, slow::Command::JUMP_SELECTED, j, jumpSelected);
        addCallback(t, slow::Command::JUMP, j, jump);
    }

    addCallback(t, slow::Command::LOOP_NEXT_SEGMENT, loopNextSegment);

    for (int j = 0; j < RECENT_MENU_REPEATS; ++j)
        addCallback(t, slow::Command::RECENT_FILES + j, loadRecentFile, j);

    addCallback(t, slow::Command::OPEN_PREVIOUS_FILE, openPreviousFile);
    addCallback(t, slow::Command::NUDGE_BACKWARD, nudgeTime, false);
    addCallback(t, slow::Command::NUDGE_FORWARD, nudgeTime, true);
}

}  // namespace slow
}  // namespace rec
