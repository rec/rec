#ifndef __REC_AUDIO_SOURCE_COMPUTED_H__
#define __REC_AUDIO_SOURCE_COMPUTED_H__

#include "JuceLibraryCode/JuceHeader.h"
#include "rec/audio/source/new/source/Buffered.h"
#include "rec/block/MergeBlockSet.h"
#include "rec/block/GetNextBlock.h"
#include "rec/block/blocks.h"

namespace rec {
namespace buffer {

// A generic callback!
class Callback {
 public:
  void operator()() = 0;
};

class Computed {
 public:
  Computed(int length, int chunkSize)
      : length_(length), chunkSize_(chunkSize), callback_(NULL) {
  }

  void request(const Block& request, Callback* callback) {
    ScopedLock l(lock_);

    nextBlock_ = request;
    callback_ = callback;
  }

  Block getNextBlock() {
    ScopedLock l(lock_);

    Block b(nextBlock_);
    BlockSet::iterator i = finishedBlocks_.upper_bound(b.second);
    if (i != finishedBlocks_.end()) {

    }
    nextBlock.first = nextBlock.second + 1;
    return b;
  }


 private:
  const int length;
  BlockSet list;
  Block nextBlock_;
  CriticalSection lock_;
  Callback* callback_;

  DISALLOW_COPY_AND_ASSIGN(Computed);
};

}  // namespace source
}  // namespace rec

#endif  // __REC_AUDIO_SOURCE_COMPUTED_H__
