#pragma once

#include "rec/util/HasLock.h"
#include "rec/util/thread/Callback.h"

namespace rec {
namespace util {
namespace thread {

class CallbackQueue : public HasLock {
  public:
    CallbackQueue();
    virtual ~CallbackQueue();

    void queueCallback(void* owner, Callback* c);
    void removeCallbacksFor(void* owner);
    bool empty() const;
    void runOneCallback();

  private:
    struct Queue;
    std::unique_ptr<Queue> queue_;

    DISALLOW_COPY_ASSIGN_AND_LEAKS(CallbackQueue);
};

}  // namespace thread
}  // namespace util
}  // namespace rec
