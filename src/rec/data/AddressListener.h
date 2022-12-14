#pragma once

#include "rec/data/Address.h"
#include "rec/data/Undoable.h"
#include "rec/data/Value.h"
#include "rec/util/Listener.h"

namespace rec {
namespace data {

class AddressListener : public Listener<const Value&> {
  public:
    AddressListener(const Address& a);
    virtual ~AddressListener();

    virtual void operator()(const Value&) = 0;

    virtual void setValue(const Value& v, Undoable undoable = CAN_UNDO) const;
    const Value getValue(const Message& m) const;
    const Value getValue() const;
    const Address& address() const { return address_; }

    void setFailOnError(bool f) { failOnError_ = f; }
    void updateCallback();

  private:
    struct UntypedListener;

    void receiveMessage(const Message&);

    std::unique_ptr<UntypedListener> untypedListener_;
    const Address address_;
    bool failOnError_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(AddressListener);
};

}  // namespace data
}  // namespace rec
