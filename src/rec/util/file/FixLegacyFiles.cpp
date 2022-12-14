#include "rec/util/file/FixLegacyFiles.h"

#include "rec/command/Command.pb.h"
#include "rec/command/map/CommandMap.pb.h"
#include "rec/data/DataOps.h"
#include "rec/util/Copy.h"
#include "rec/util/file/MoveFile.h"
#include "rec/util/file/TypeMap.h"

namespace rec {
namespace util {
namespace file {

namespace {

using namespace rec::command;
using namespace rec::data;

CommandMapEntry* newEntry(CommandID id, KeyStrokeCommandMapProto* map) {
    CommandMapEntry* entry = map->mutable_map()->add_entry();
    entry->set_id(id);
    return entry;
}

void portKeyboardFile() {
    File f = keyboardFile().getChildFile(str(getTypeName<Commands>()));
    if (f.exists()) {
        Commands commands;
        bool copied = copy::copy(f, &commands);
        DCHECK(copied) << str(f);
        if (copied) {
            KeyStrokeCommandMapProto keyMap;
            for (int i = 0; i < commands.command_size(); ++i) {
                const Command& command = commands.command(i);
                CommandID type = command.id();
                // TODO: https://github.com/rec/rec/issues/621
                if (false) { // command.has_start_index()) {
                    int32 index = 0; // command.start_index();
                    for (int j = 0; j < command.keypress_size(); ++j, ++index) {
                        CommandMapEntry* entry = newEntry(type, &keyMap);
                        entry->set_index(index);
                        entry->add_key(command.keypress(j));
                    }
                } else {
                    CommandMapEntry* entry = newEntry(type, &keyMap);
                    for (int j = 0; j < command.keypress_size(); ++j)
                        entry->add_key(command.keypress(j));
                }
            }
            data::setProto(keyMap, data::global());
            File parent = f.getParentDirectory();
            bool deleted = f.deleteFile();
            DCHECK(deleted) << str(f);
            deleted = parent.deleteFile();
            DCHECK(deleted) << str(parent);
        }
    }
}

void moveOldAbsoluteDirectoriesToTypeRelative() {
    const TypeMap& map = getTypeMap();
    for (TypeMap::const_iterator i = map.begin(); i != map.end(); ++i)
        moveTypeDirectory(i->first, i->second.first);
    moveGlobalFiles();
    moveKeyboardFile();
}

template <typename OLD, typename NEW, typename CONVERTER>
void moveGlobalData(CONVERTER converter) {
    Data* newData = data::getData<NEW>(data::global());
    if (newData->fileReadSuccess())
        return;

    Data* oldData = data::getData<OLD>(data::global());
    if (not oldData->fileReadSuccess())
        return;

    data::Opener<NEW> opener(newData, CANT_UNDO);
    converter(data::getProto<OLD>(oldData), opener.get());
}

}  // namespace

void fixLegacyFiles() {
    moveOldAbsoluteDirectoriesToTypeRelative();
    portKeyboardFile();
}

}  // namespace file
}  // namespace util
}  // namespace rec
