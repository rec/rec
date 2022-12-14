#include "rec/program/SetterListener.h"

#include "rec/base/make_unique.h"
#include "rec/command/Command.pb.h"
#include "rec/program/JuceModel.h"
#include "rec/program/JuceModelImpl.h"
#include "rec/program/Program.h"
#include "rec/util/thread/Callback.h"
#include "rec/util/thread/MakeCallback.h"

using namespace rec::command;
using namespace rec::data;
using namespace rec::util::thread;

namespace rec {
namespace program {

SetterListener::SetterListener(CommandID id,
                                                              const command::Command& command,
                                                              JuceModel* model)
        : AddressListener(command.setter()), model_(model) {
    Program* p = model->program();
    if (command.setter_type() == Command::TOGGLE) {
        p->addCallback(id, methodCallback(this, &SetterListener::toggle));
    } else {
        CommandID index = id - command.id();
        p->addCallback(id, methodCallback(this, &SetterListener::select, index));
    }
}

void SetterListener::toggle() {
    {
        Lock l(lock_);
        value_.set_bool_f(not value_.bool_f());
    }
    setValue();
}

void SetterListener::select(int index) {
    {
        Lock l(lock_);
        value_.set_enum_f(index);
    }
    setValue();
}

void SetterListener::operator()(const Value& v) {
    {
        Lock l(lock_);
        value_ = v;
    }
    model_->menuItemsChanged();
}

void SetterListener::setValue() {
    AddressListener::setValue(value_);
    model_->menuItemsChanged();
}

}  // namespace program
}  // namespace rec
