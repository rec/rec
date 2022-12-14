#pragma once

#include "rec/util/thread/Callback.h"
#include "rec/util/thread/Callback1.h"

namespace rec {
namespace util {
namespace thread {
namespace callback {

// Wrap any C++ callable into a Callback.
template <typename Operator>
class Pointer : public Callback {
  public:
    Pointer(Operator op) : operator_(op) {}
    virtual ~Pointer() {}
    virtual bool operator()() { (*operator_)(); return true; }

  protected:
    Operator operator_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(Pointer);
};

// A Pointer that owns its underlying callable.
template <typename Operator>
class OwnedPointer : public Pointer<Operator*> {
  public:
    explicit OwnedPointer(Operator* r) : Pointer<Operator*>(r) {
    }
    virtual ~OwnedPointer() { delete this->operator_; }

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(OwnedPointer);
};

}  // namespace callback
}  // namespace thread

template <typename Operator>
std::unique_ptr<Callback> makePointer(Operator op) {
    return std::make_unique<thread::callback::Pointer<Operator>>(op);
}

template <typename Operator, typename Value>
std::unique_ptr<Callback> makePointer(Operator op, Value v) {
    return std::make_unique<thread::callback::CallbackFunc1<Operator, Value>>(op, v);
}

}  // namespace util
}  // namespce rec
