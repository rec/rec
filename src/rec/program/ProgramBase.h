#pragma once

#include <unordered_map>

#include "rec/Program/Program.h"

namespace rec {
namespace program {

class ProgramBase : public Program {
  public:
    ProgramBase();
    virtual ~ProgramBase();

    void addCallback(CommandID, std::unique_ptr<Callback>) override;
    Callback* getCallback(CommandID) const override;
    CallbackMap* getCallbackMap() override { return &callbackMap_; }
    bool isEnabled() const override;
    void setEnabled(bool) override;

    thread::Looper::Function threadFunction(const string& name) const override {
        return threadFunctions_.at(name);
    }

  protected:
    CriticalSection lock_;
    std::unordered_map<string, thread::Looper::Function> threadFunctions_;

  private:
    bool enabled_;
    CallbackMap callbackMap_;
};

}  // namespace program
}  // namespace rec
