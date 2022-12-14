#pragma once

#include "rec/util/thread/Callback0.h"
#include "rec/util/thread/Callback1.h"
#include "rec/util/thread/Callback2.h"
#include "rec/util/thread/Callback3.h"
#include "rec/util/thread/Callback4.h"
#include "rec/util/thread/Pointer.h"

namespace rec {
namespace util {
namespace thread {

// Callbacks for functions or methods which return null.

template <typename Type>
std::unique_ptr<Callback> makeCallback(Type o) {
    return std::make_unique<callback::Pointer<Type>>(o);
}

template <typename Type, typename Method>
std::unique_ptr<Callback> methodCallback(Type* o, Method m) {
    return std::make_unique<callback::Callback0<Type, Method>>(o, m);
}

template <typename Type, typename Method, typename Value>
std::unique_ptr<Callback> methodCallback(Type* o, Method m, Value v) {
    return std::make_unique<callback::Callback1<Type, Method, Value>>(o, m, v);
}

template <typename Type, typename Method, typename V1, typename V2>
std::unique_ptr<Callback> methodCallback(Type* o, Method m, V1 v1, V2 v2) {
    return std::make_unique<callback::Callback2<Type, Method, V1, V2>>(o, m, v1, v2);
}

template <typename Type, typename Method, typename V1, typename V2, typename V3>
std::unique_ptr<Callback> methodCallback(Type* o, Method m, V1 v1, V2 v2, V3 v3) {
    return std::make_unique<callback::Callback3<Type, Method, V1, V2, V3>>(o, m, v1, v2, v3);
}

template <typename Type, typename Method, typename V1, typename V2, typename V3, typename V4>
std::unique_ptr<Callback> methodCallback(Type* o, Method m, V1 v1, V2 v2, V3 v3, V4 v4) {
    return std::make_unique<callback::Callback4<Type, Method, V1, V2, V3, V4>>(o, m, v1, v2, v3, v4);
}

}  // namespace thread
}  // namespace util
}  // namespace rec
