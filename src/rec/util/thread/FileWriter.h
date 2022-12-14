#pragma once

#include "rec/util/thread/Trash.h"

namespace rec {
namespace util {
namespace thread {

class FileWriter : public Thread {
  public:
    FileWriter(const File& file) : Thread("FileWriter"), file_(file) {}
    MemoryBlock* memory() { return &memory_; }

    virtual void run() {
        string file = str(file_.getFullPathName());
        if (!file_.getParentDirectory().createDirectory()) {
            LOG(DFATAL) << "Can't make dir " << file;

        } else if (!file_.deleteFile()) {
            LOG(DFATAL) << "Can't delete file " << file;

        } else {
            ::std::unique_ptr<OutputStream> out(file_.createOutputStream());
            if (out) {
                (*out) << memory_;
                VLOG(1) << "Saved to file " << file;
            } else {
                LOG(DFATAL) << "Can't create file " << file;
            }
        }

        trash::discard(this);
    }

  private:
    MemoryBlock memory_;
    const File file_;

    DISALLOW_COPY_ASSIGN_AND_LEAKS(FileWriter);
};


}  // namespace thread
}  // namespace util
}  // namespace rec
