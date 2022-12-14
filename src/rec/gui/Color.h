#pragma once

#include <unordered_map>

#include "rec/base/base.h"
#include "rec/gui/Color.pb.h"

namespace rec {
namespace gui {
namespace color {

using ColourMap = std::unordered_map<string, Colour>;

Colour get(const Colors& colors, int index);

Colour makeColour(const Color&, const ColourMap&);

}  // namespace color
}  // namespace gui
}  // namespace rec
