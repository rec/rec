#pragma once

#include "rec/base/base.h"

namespace rec {
namespace util {
namespace thread {

using ModalCallback = juce::ModalComponentManager::Callback;

template <typename Type, typename Method>
class ModalCallback0 : public ModalCallback {
  public:
    ModalCallback0(Type* o, Method m) : object_(o), method_(m) {}
    virtual ~ModalCallback0() {}

    virtual void modalStateFinished(int returnValue) {
        (object_->*method_)(returnValue);
    }

  private:
    Type* object_;
    Method method_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(ModalCallback0);
};

template <typename Type, typename Method, typename Value>
class ModalCallback1 : public ModalCallback {
  public:
    ModalCallback1(Type* o, Method m, Value v) : object_(o), method_(m), value_(v) {}
    virtual ~ModalCallback1() {}

    virtual void modalStateFinished(int returnValue) {
        (object_->*method_)(value_, returnValue);
    }

  private:
    Type* object_;
    Method method_;
    Value value_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(ModalCallback1);
};

template <typename Type, typename Method, typename Value1, typename Value2>
class ModalCallback2 : public ModalCallback {
  public:
    ModalCallback2(Type* o, Method m, Value1 v1, Value2 v2)
            : object_(o), method_(m), v1_(v1), v2_(v2) {
    }
    virtual ~ModalCallback2() {}

    virtual void modalStateFinished(int returnValue) {
        (object_->*method_)(v1_, v2_, returnValue);
    }

  private:
    Type* object_;
    Method method_;
    Value1 v1_;
    Value2 v2_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(ModalCallback2);
};

template <typename Operator>
class ModalPointer0 : public ModalCallback {
  public:
    ModalPointer0(Operator op) : operator_(op) {}
    virtual ~ModalPointer0() {}
    virtual void modalStateFinished(int returnValue) {
        (*operator_)(returnValue);
    }

  private:
    Operator operator_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(ModalPointer0);
};

template <typename Operator, typename Type>
class ModalPointer1 : public ModalCallback {
  public:
    ModalPointer1(Operator op, Type value) : operator_(op), value_(value) {}
    virtual ~ModalPointer1() {}
    virtual void modalStateFinished(int returnValue) {
        (*operator_)(value_, returnValue);
    }

  private:
    Operator operator_;
    Type value_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(ModalPointer1);
};

template <typename Type, typename Method>
std::unique_ptr<ModalCallback> modalCallback(Type* o, Method m) {
    return std::make_unique<ModalCallback0<Type, Method>>(o, m);
}

template <typename Type, typename Method, typename Value>
std::unique_ptr<ModalCallback> modalCallback(Type* o, Method m, Value v) {
    return std::make_unique<ModalCallback1<Type, Method, Value>>(o, m, v);
}

template <typename Type, typename Method, typename Value1, typename Value2>
std::unique_ptr<ModalCallback> modalCallback(Type* o, Method m, Value1 v1, Value2 v2) {
    return std::make_unique<ModalCallback2<Type, Method, Value1, Value2>>(o, m, v1, v2);
}

template <typename Operator>
std::unique_ptr<ModalCallback> modalFunctionCallback(Operator op) {
    return std::make_unique<ModalPointer0<Operator>>(op);
}

template <typename Operator, typename Value>
std::unique_ptr<ModalCallback> modalFunctionCallback(Operator op, Value v) {
    return std::make_unique<ModalPointer1<Operator, Value>>(op, v);
}

}  // namespace thread
}  // namespace util
}  // namespace rec
