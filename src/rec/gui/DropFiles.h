#pragma once

#include "rec/util/file/VirtualFile.pb.h"
#include "rec/base/base.h"

namespace rec {
namespace gui {

class DropFiles {
  public:
    VirtualFileList files_;
    Component* target_;
    DropFiles() {}
    DropFiles(const VirtualFileList& f, Component* t) : files_(f), target_(t) {}
};

}  // namespace gui
}  // namespace rec
