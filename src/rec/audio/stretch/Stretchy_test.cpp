#ifdef FIX_TESTS

#include <gtest/gtest.h>

#include "rec/audio/source/Stretchy.h"
#include "rec/audio/source/Testy.h"
#include "rec/audio/stretch/Stretch.pb.h"

namespace rec {
namespace audio {
namespace stretch {

TEST(RecAudioSource, Stretchy) {
    std::unique_ptr<Stretchy> stretchy(Stretchy::create(new Testy()));
    Testy::expectNear(stretchy.get(), 0.0086, 2);
}

}  // namespace stretch
}  // namespace audio
}  // namespace rec

#endif  // FIX_TESTS
