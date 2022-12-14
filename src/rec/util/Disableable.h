#pragma once

#include <unordered_map>
#include "rec/base/base.h"

namespace rec {
namespace util {

using PropertyMap = std::unordered_map<string, bool>;

class Disableable {
  public:
    Disableable() {}
    virtual ~Disableable() {}

    template <typename Type>
    void addDisableProperties(Type properties) {
        Lock l(lock_);
        for (auto& p: properties)
            propertyMap_[p] = false;
    }

    void setDisableProperty(const string& name, bool value);
    bool getDisabledFromProperties() const;
    const PropertyMap& map() const { return propertyMap_; }

    void disable(bool isDisabled);

  private:
    CriticalSection lock_;
    PropertyMap propertyMap_;

    DISALLOW_COPY_ASSIGN_AND_LEAKS(Disableable);
};

}  // namespace util
}  // namespace rec
