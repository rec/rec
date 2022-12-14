#pragma once

#include "rec/base/base.h"

namespace rec {
namespace util {

template <typename Type>
class Switcher {
  public:
    Switcher() {}

    Type* current() { return current_.get(); }
    Type* next() { return next_.get(); }

    void setNext(Type* n) {
        if (next_) {
            LOG(DFATAL) << "Tried to set next before switch";
            delete n;
        } else {
            next_.reset(n);
        }
    }

    void switchIfNext() {
        if (next_) {
            current_.swap(next_);
            next_.reset();
        }
    }

  private:
    std::unique_ptr<Type> current_, next_;

    DISALLOW_COPY_ASSIGN_AND_LEAKS(Switcher);
};

}  // namespace util
}  // namespace rec
