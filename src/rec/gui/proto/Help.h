#pragma once

#include "rec/gui/GetHelpText.h"

namespace rec {
namespace gui {

class ComponentProto;
class Constants;
class Context;

std::unique_ptr<Component> makeHelp(const Context&);

}  // namespace gui
}  // namespace rec
