#include "rec/data/Address.h"
#include "rec/data/Editable.h"
#include "rec/data/Value.h"
#include "rec/data/Operation.pb.h"

namespace rec {
namespace data {

namespace {

typedef Operation::Command Command;

Operation* newOp(Command c, const Address& a) {
  Operation* op = new Operation();
  op->set_command(c);
  op->mutable_address()->CopyFrom(a);
  return op;
}

Operation* valueOp(Command c, const Address& a, const Value& value) {
  Operation* op = newOp(c, a);
  op->add_value()->CopyFrom(value);
  return op;
}

void setOp(Editable* setter, Operation* oper, bool undoable) {
  ptr<Operation> op(oper);
  ptr<Operations> list(new Operations);
  list->add_operation()->CopyFrom(*op);
  list->set_undoable(undoable);
  setter->applyLater(list.transfer());
}

}  // namespace

void Editable::append(const Value& value, const Address& address) {
  setOp(this, valueOp(Operation::APPEND, address, value), true);
}

void setValue(Editable* e, const Value& value, const Address& address,
              bool undoable) {
  setOp(e, valueOp(Operation::SET, address, value), undoable);
}

}  // namespace data
}  // namespace rec

