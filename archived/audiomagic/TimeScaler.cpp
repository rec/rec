#include <math.h>

#include "rec/audio/stretch/TimeScaler.h"

#include "rec/audio/stretch/Stretchy.h"
#include "rec/audio/stretch/Stretch.h"
#include "rec/audio/ammf_scaler/AudioTimeScaler.h"

namespace rec {
namespace audio {
namespace stretch {

const char* Init(const Stretch &d, AudioTimeScaler* s) {
  return s->Init(timeScale(d),
                 d.sample_rate(),
                 d.channels(),
                 pitchScale(d),
                 d.bands(),
                 d.filter_overlap()) ? "error" : NULL;
}

}  // namespace stretch
}  // namespace audio
}  // namespace rec
