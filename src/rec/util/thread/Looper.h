#pragma once

#include "rec/util/thread/Result.h"

namespace rec {
namespace util {
namespace thread {

class Looper : public Thread {
  public:
    using Function = int32 (*)(Thread*);

    explicit Looper(const string& name, Function f, uint32 period)
            : Thread(str(name)), function_(f), period_(period) {
    }

    void run() override {
        while (!threadShouldExit()) {
            int32 r = function_(this);
            switch (r) {
                case thread::CONTINUE:  wait(period_); break;
                case thread::YIELD:     yield(); break;
                case thread::DONE:      return;
                default:                wait(static_cast<int>(r)); break;
            }
        }
    }

  private:
    Function const function_;
    int32 const period_;
};


}  // namespace thread
}  // namespace util
}  // namespace rec
