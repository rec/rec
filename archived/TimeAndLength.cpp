#include "rec/widget/status/TimeAndLength.h"

namespace rec {
namespace widget {
namespace status {

TimeAndLength::TimeAndLength(const String& label, const time::Text& desc)
    : Layout("TimeAndLength", VERTICAL),
      label_(label),
      length_(desc),
      time_(desc),
      timeScale_(1.0),
      offset_(0.0) {
  label_.setJustificationType(juce::Justification::centred);
  addToLayout(&label_);
  addToLayout(&length_);
  addToLayout(&begin_);
  addToLayout(&end_);
  addToLayout(&time_);
}

void TimeAndLength::setTimeScale(double s) {
  s = juce::jmax(s, SMALLEST_TIME);
  double scale = s / timeScale_;
  time_.setTime(scale * time_.getTime());
  length_.setTime(scale * length_.getTime());
  begin_.setTime(scale * begin_.getTime());
  end_.setTime(scale * end_.getTime());

  timeScale_ = s;
}

void TimeAndLength::operator()(const TimeSelection& s) {
  Range<RealTime> range(s);

  begin_.setTime(range.begin_ + offset_);
  end_.setTime(range.end_ + offset_);
}

}  // namespace status
}  // namespace widget
}  // namespace rec
