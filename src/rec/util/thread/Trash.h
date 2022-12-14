#pragma once

#include <set>

#include "rec/base/base.h"
#include "rec/util/STL.h"

namespace rec {
namespace util {
namespace thread {
namespace trash {

void discard(Thread* t);

template <typename ThreadClass>
void discard(std::unique_ptr<ThreadClass>* t) {
    discard(t->release());
}

Thread* add(Thread* t);
void run(Thread *t);
template <typename T> void run() { run(new T); }


void empty();
void waitForAllThreadsToExit(int timeout);
inline void discardAndEmpty(Thread* t) { discard(t); empty(); }

}  // namespace trash
}  // namespace thread


template <typename Type>
class thread_ptr : public std::unique_ptr<Type> {
public:
    explicit thread_ptr(Type* p = 0) : std::unique_ptr<Type>(p) {}

    ~thread_ptr() { reset(); }

    void reset(Type* p = nullptr) {
        if (p != this->get()) {
            thread::trash::discard(this->release());
            std::unique_ptr<Type>::reset(p);
        }
    }

    operator bool() const { return this->get(); }
    bool operator!() const { return !this->get(); }

    DISALLOW_COPY_ASSIGN_AND_LEAKS(thread_ptr);
};

}  // namespace util
}  // namespace rec
