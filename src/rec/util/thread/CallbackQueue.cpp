#include <list>

#include "rec/util/thread/CallbackQueue.h"
#include "rec/util/STL.h"

namespace rec {
namespace util {
namespace thread {

namespace {

struct HasOwner {
    explicit HasOwner(void* owner = nullptr) : owner_(owner) {}
    bool operator()(const HasOwner* that) { return owner_ == that->owner_; }
    void* owner_;
};

struct OwnedCallback : public HasOwner {
    OwnedCallback(void* owner, Callback* cb) : HasOwner(owner), callback_(cb) {}
    std::unique_ptr<Callback> callback_;
};

}  // namespace

struct CallbackQueue::Queue {
    ~Queue() { stl::deletePointers(&list_); }

    using List = std::list<OwnedCallback*>;
    List list_;
};

CallbackQueue::CallbackQueue() : queue_(new Queue) {}
CallbackQueue::~CallbackQueue() { DCHECK(empty()) << queue_->list_.size(); }
bool CallbackQueue::empty() const { return queue_->list_.empty(); }

void CallbackQueue::queueCallback(void* owner, Callback* c) {
    Lock l(lock_);
    queue_->list_.push_front(new OwnedCallback(owner, c));
}

void CallbackQueue::removeCallbacksFor(void* owner) {
    Lock l(lock_);
    queue_->list_.remove_if(HasOwner(owner));
}

void CallbackQueue::runOneCallback() {
    Lock l(lock_);
    if (!empty()) {
        std::unique_ptr<OwnedCallback> owned(queue_->list_.back());
        (*owned->callback_)();
        queue_->list_.pop_back();
    }
}

}  // namespace thread
}  // namespace util
}  // namespace rec
