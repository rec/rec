#ifndef __REC_SLOW_PERSISTENTDATA__
#define __REC_SLOW_PERSISTENTDATA__

#include "rec/audio/stretch/Stretch.pb.h"
#include "rec/data/persist/Persist.h"
#include "rec/util/LoopPoint.pb.h"
#include "rec/widget/waveform/Zoom.pb.h"

namespace rec {
namespace slow {

struct PersistentData {
  persist::Data<LoopPointList>* loopPointList_;
  persist::Data<audio::stretch::Stretch>* stretch_;
  persist::Data<widget::waveform::ZoomProto>* zoomProto_;

  PersistentData();
  void setFile(const VirtualFile* file);
};

}  // namespace slow
}  // namespace rec

#endif  // __REC_SLOW_PERSISTENTDATA__
