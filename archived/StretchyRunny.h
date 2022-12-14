#ifndef __REC_AUDIO_SOURCE_STRETCHYRUNNY__
#define __REC_AUDIO_SOURCE_STRETCHYRUNNY__

#include "rec/base/base.h"
#include "rec/audio/source/Stretchy.h"

namespace rec {
namespace audio {
namespace source {

class ThreadedSource;
class RunnyProto;

ThreadedSource* stretchyRunny(const RunnyProto& desc,
                              const stretch::StretchLoop& loop,
                              int pos, PositionableAudioSource* s);

}  // namespace source
}  // namespace audio
}  // namespace rec

#endif  // __REC_AUDIO_SOURCE_STRETCHYRUNNY__
