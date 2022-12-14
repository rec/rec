#ifndef __REC_WIDGET_STATUS_TIMEANDLENGTH__
#define __REC_WIDGET_STATUS_TIMEANDLENGTH__

#include "rec/widget/status/TextComponent.h"
#include "rec/gui/layout/Layout.h"
#include "rec/gui/SimpleLabel.h"
#include "rec/util/Range.h"

namespace rec {
namespace widget {
namespace status {

class TimeAndLength : public gui::Layout,
                      public Listener<const TimeSelection&> {
 public:
  TimeAndLength(const String& label,
                const time::Text& desc = time::Text::default_instance());

  void setTimeScale(double s);

  virtual void operator()(const TimeSelection&);

  void setOffset(double o) { offset_ = o; }

 private:
	gui::SimpleLabel label_;

  time::TextComponent length_, begin_, end_, time_;
  double timeScale_;
  double offset_;

  DISALLOW_COPY_ASSIGN_AND_EMPTY(TimeAndLength);
};

}  // namespace status
}  // namespace widget
}  // namespace rec

#endif  // __REC_WIDGET_STATUS_TIMEANDLENGTH__
