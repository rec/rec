// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/widget/status/Time.proto

#ifndef PROTOBUF_rec_2fwidget_2fstatus_2fTime_2eproto__INCLUDED
#define PROTOBUF_rec_2fwidget_2fstatus_2fTime_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "rec/gui/Color.pb.h"
#include "rec/widget/Widget.pb.h"
// @@protoc_insertion_point(includes)

namespace rec {
namespace widget {
namespace status {
namespace time {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
void protobuf_AssignDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
void protobuf_ShutdownFile_rec_2fwidget_2fstatus_2fTime_2eproto();

class Text;
class Text_Separator;
class Text_Fields;
class Dial;

enum Dial_Direction {
  Dial_Direction_CLOCKWISE = 1,
  Dial_Direction_COUNTER_CLOCKWISE = 2
};
bool Dial_Direction_IsValid(int value);
const Dial_Direction Dial_Direction_Direction_MIN = Dial_Direction_CLOCKWISE;
const Dial_Direction Dial_Direction_Direction_MAX = Dial_Direction_COUNTER_CLOCKWISE;
const int Dial_Direction_Direction_ARRAYSIZE = Dial_Direction_Direction_MAX + 1;

const ::google::protobuf::EnumDescriptor* Dial_Direction_descriptor();
inline const ::std::string& Dial_Direction_Name(Dial_Direction value) {
  return ::google::protobuf::internal::NameOfEnum(
    Dial_Direction_descriptor(), value);
}
inline bool Dial_Direction_Parse(
    const ::std::string& name, Dial_Direction* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Dial_Direction>(
    Dial_Direction_descriptor(), name, value);
}
// ===================================================================

class Text_Separator : public ::google::protobuf::Message {
 public:
  Text_Separator();
  virtual ~Text_Separator();

  Text_Separator(const Text_Separator& from);

  inline Text_Separator& operator=(const Text_Separator& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Text_Separator& default_instance();

  void Swap(Text_Separator* other);

  // implements Message ----------------------------------------------

  Text_Separator* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Text_Separator& from);
  void MergeFrom(const Text_Separator& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string separator = 1;
  inline bool has_separator() const;
  inline void clear_separator();
  static const int kSeparatorFieldNumber = 1;
  inline const ::std::string& separator() const;
  inline void set_separator(const ::std::string& value);
  inline void set_separator(const char* value);
  inline void set_separator(const char* value, size_t size);
  inline ::std::string* mutable_separator();
  inline ::std::string* release_separator();
  inline void set_allocated_separator(::std::string* separator);

  // optional uint32 width = 2;
  inline bool has_width() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 2;
  inline ::google::protobuf::uint32 width() const;
  inline void set_width(::google::protobuf::uint32 value);

  // optional bool flash = 3 [default = false];
  inline bool has_flash() const;
  inline void clear_flash();
  static const int kFlashFieldNumber = 3;
  inline bool flash() const;
  inline void set_flash(bool value);

  // optional bool display_ms = 4 [default = true];
  inline bool has_display_ms() const;
  inline void clear_display_ms();
  static const int kDisplayMsFieldNumber = 4;
  inline bool display_ms() const;
  inline void set_display_ms(bool value);

  // @@protoc_insertion_point(class_scope:rec.widget.status.time.Text.Separator)
 private:
  inline void set_has_separator();
  inline void clear_has_separator();
  inline void set_has_width();
  inline void clear_has_width();
  inline void set_has_flash();
  inline void clear_has_flash();
  inline void set_has_display_ms();
  inline void clear_has_display_ms();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* separator_;
  ::google::protobuf::uint32 width_;
  bool flash_;
  bool display_ms_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_AssignDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_ShutdownFile_rec_2fwidget_2fstatus_2fTime_2eproto();

  void InitAsDefaultInstance();
  static Text_Separator* default_instance_;
};
// -------------------------------------------------------------------

class Text_Fields : public ::google::protobuf::Message {
 public:
  Text_Fields();
  virtual ~Text_Fields();

  Text_Fields(const Text_Fields& from);

  inline Text_Fields& operator=(const Text_Fields& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Text_Fields& default_instance();

  void Swap(Text_Fields* other);

  // implements Message ----------------------------------------------

  Text_Fields* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Text_Fields& from);
  void MergeFrom(const Text_Fields& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bool hours = 1 [default = false];
  inline bool has_hours() const;
  inline void clear_hours();
  static const int kHoursFieldNumber = 1;
  inline bool hours() const;
  inline void set_hours(bool value);

  // optional bool minutes = 2 [default = true];
  inline bool has_minutes() const;
  inline void clear_minutes();
  static const int kMinutesFieldNumber = 2;
  inline bool minutes() const;
  inline void set_minutes(bool value);

  // optional bool seconds = 3 [default = true];
  inline bool has_seconds() const;
  inline void clear_seconds();
  static const int kSecondsFieldNumber = 3;
  inline bool seconds() const;
  inline void set_seconds(bool value);

  // optional bool milliseconds = 4 [default = true];
  inline bool has_milliseconds() const;
  inline void clear_milliseconds();
  static const int kMillisecondsFieldNumber = 4;
  inline bool milliseconds() const;
  inline void set_milliseconds(bool value);

  // optional bool frames = 5 [default = false];
  inline bool has_frames() const;
  inline void clear_frames();
  static const int kFramesFieldNumber = 5;
  inline bool frames() const;
  inline void set_frames(bool value);

  // @@protoc_insertion_point(class_scope:rec.widget.status.time.Text.Fields)
 private:
  inline void set_has_hours();
  inline void clear_has_hours();
  inline void set_has_minutes();
  inline void clear_has_minutes();
  inline void set_has_seconds();
  inline void clear_has_seconds();
  inline void set_has_milliseconds();
  inline void clear_has_milliseconds();
  inline void set_has_frames();
  inline void clear_has_frames();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  bool hours_;
  bool minutes_;
  bool seconds_;
  bool milliseconds_;
  bool frames_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(5 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_AssignDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_ShutdownFile_rec_2fwidget_2fstatus_2fTime_2eproto();

  void InitAsDefaultInstance();
  static Text_Fields* default_instance_;
};
// -------------------------------------------------------------------

class Text : public ::google::protobuf::Message {
 public:
  Text();
  virtual ~Text();

  Text(const Text& from);

  inline Text& operator=(const Text& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Text& default_instance();

  void Swap(Text* other);

  // implements Message ----------------------------------------------

  Text* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Text& from);
  void MergeFrom(const Text& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Text_Separator Separator;
  typedef Text_Fields Fields;

  // accessors -------------------------------------------------------

  // optional .rec.widget.Widget widget = 1;
  inline bool has_widget() const;
  inline void clear_widget();
  static const int kWidgetFieldNumber = 1;
  inline const ::rec::widget::Widget& widget() const;
  inline ::rec::widget::Widget* mutable_widget();
  inline ::rec::widget::Widget* release_widget();
  inline void set_allocated_widget(::rec::widget::Widget* widget);

  // optional .rec.widget.status.time.Text.Separator separator = 2;
  inline bool has_separator() const;
  inline void clear_separator();
  static const int kSeparatorFieldNumber = 2;
  inline const ::rec::widget::status::time::Text_Separator& separator() const;
  inline ::rec::widget::status::time::Text_Separator* mutable_separator();
  inline ::rec::widget::status::time::Text_Separator* release_separator();
  inline void set_allocated_separator(::rec::widget::status::time::Text_Separator* separator);

  // optional .rec.widget.status.time.Text.Fields fields = 3;
  inline bool has_fields() const;
  inline void clear_fields();
  static const int kFieldsFieldNumber = 3;
  inline const ::rec::widget::status::time::Text_Fields& fields() const;
  inline ::rec::widget::status::time::Text_Fields* mutable_fields();
  inline ::rec::widget::status::time::Text_Fields* release_fields();
  inline void set_allocated_fields(::rec::widget::status::time::Text_Fields* fields);

  // optional bool use_global_clock = 4 [default = true];
  inline bool has_use_global_clock() const;
  inline void clear_use_global_clock();
  static const int kUseGlobalClockFieldNumber = 4;
  inline bool use_global_clock() const;
  inline void set_use_global_clock(bool value);

  // @@protoc_insertion_point(class_scope:rec.widget.status.time.Text)
 private:
  inline void set_has_widget();
  inline void clear_has_widget();
  inline void set_has_separator();
  inline void clear_has_separator();
  inline void set_has_fields();
  inline void clear_has_fields();
  inline void set_has_use_global_clock();
  inline void clear_has_use_global_clock();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::rec::widget::Widget* widget_;
  ::rec::widget::status::time::Text_Separator* separator_;
  ::rec::widget::status::time::Text_Fields* fields_;
  bool use_global_clock_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_AssignDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_ShutdownFile_rec_2fwidget_2fstatus_2fTime_2eproto();

  void InitAsDefaultInstance();
  static Text* default_instance_;
};
// -------------------------------------------------------------------

class Dial : public ::google::protobuf::Message {
 public:
  Dial();
  virtual ~Dial();

  Dial(const Dial& from);

  inline Dial& operator=(const Dial& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Dial& default_instance();

  void Swap(Dial* other);

  // implements Message ----------------------------------------------

  Dial* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Dial& from);
  void MergeFrom(const Dial& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Dial_Direction Direction;
  static const Direction CLOCKWISE = Dial_Direction_CLOCKWISE;
  static const Direction COUNTER_CLOCKWISE = Dial_Direction_COUNTER_CLOCKWISE;
  static inline bool Direction_IsValid(int value) {
    return Dial_Direction_IsValid(value);
  }
  static const Direction Direction_MIN =
    Dial_Direction_Direction_MIN;
  static const Direction Direction_MAX =
    Dial_Direction_Direction_MAX;
  static const int Direction_ARRAYSIZE =
    Dial_Direction_Direction_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Direction_descriptor() {
    return Dial_Direction_descriptor();
  }
  static inline const ::std::string& Direction_Name(Direction value) {
    return Dial_Direction_Name(value);
  }
  static inline bool Direction_Parse(const ::std::string& name,
      Direction* value) {
    return Dial_Direction_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional .rec.widget.Widget widget = 1;
  inline bool has_widget() const;
  inline void clear_widget();
  static const int kWidgetFieldNumber = 1;
  inline const ::rec::widget::Widget& widget() const;
  inline ::rec::widget::Widget* mutable_widget();
  inline ::rec::widget::Widget* release_widget();
  inline void set_allocated_widget(::rec::widget::Widget* widget);

  // optional uint32 outline = 2;
  inline bool has_outline() const;
  inline void clear_outline();
  static const int kOutlineFieldNumber = 2;
  inline ::google::protobuf::uint32 outline() const;
  inline void set_outline(::google::protobuf::uint32 value);

  // optional .rec.widget.status.time.Dial.Direction direction = 3 [default = CLOCKWISE];
  inline bool has_direction() const;
  inline void clear_direction();
  static const int kDirectionFieldNumber = 3;
  inline ::rec::widget::status::time::Dial_Direction direction() const;
  inline void set_direction(::rec::widget::status::time::Dial_Direction value);

  // optional bool display_lap_count = 4;
  inline bool has_display_lap_count() const;
  inline void clear_display_lap_count();
  static const int kDisplayLapCountFieldNumber = 4;
  inline bool display_lap_count() const;
  inline void set_display_lap_count(bool value);

  // optional double zero_point = 7;
  inline bool has_zero_point() const;
  inline void clear_zero_point();
  static const int kZeroPointFieldNumber = 7;
  inline double zero_point() const;
  inline void set_zero_point(double value);

  // optional bool empty_on_zero = 8 [default = true];
  inline bool has_empty_on_zero() const;
  inline void clear_empty_on_zero();
  static const int kEmptyOnZeroFieldNumber = 8;
  inline bool empty_on_zero() const;
  inline void set_empty_on_zero(bool value);

  // optional .rec.gui.Color from_color = 9;
  inline bool has_from_color() const;
  inline void clear_from_color();
  static const int kFromColorFieldNumber = 9;
  inline const ::rec::gui::Color& from_color() const;
  inline ::rec::gui::Color* mutable_from_color();
  inline ::rec::gui::Color* release_from_color();
  inline void set_allocated_from_color(::rec::gui::Color* from_color);

  // optional .rec.gui.Color to_color = 10;
  inline bool has_to_color() const;
  inline void clear_to_color();
  static const int kToColorFieldNumber = 10;
  inline const ::rec::gui::Color& to_color() const;
  inline ::rec::gui::Color* mutable_to_color();
  inline ::rec::gui::Color* release_to_color();
  inline void set_allocated_to_color(::rec::gui::Color* to_color);

  // optional bool use_global_clock = 11 [default = true];
  inline bool has_use_global_clock() const;
  inline void clear_use_global_clock();
  static const int kUseGlobalClockFieldNumber = 11;
  inline bool use_global_clock() const;
  inline void set_use_global_clock(bool value);

  // @@protoc_insertion_point(class_scope:rec.widget.status.time.Dial)
 private:
  inline void set_has_widget();
  inline void clear_has_widget();
  inline void set_has_outline();
  inline void clear_has_outline();
  inline void set_has_direction();
  inline void clear_has_direction();
  inline void set_has_display_lap_count();
  inline void clear_has_display_lap_count();
  inline void set_has_zero_point();
  inline void clear_has_zero_point();
  inline void set_has_empty_on_zero();
  inline void clear_has_empty_on_zero();
  inline void set_has_from_color();
  inline void clear_has_from_color();
  inline void set_has_to_color();
  inline void clear_has_to_color();
  inline void set_has_use_global_clock();
  inline void clear_has_use_global_clock();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::rec::widget::Widget* widget_;
  ::google::protobuf::uint32 outline_;
  int direction_;
  double zero_point_;
  ::rec::gui::Color* from_color_;
  ::rec::gui::Color* to_color_;
  bool display_lap_count_;
  bool empty_on_zero_;
  bool use_global_clock_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(9 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_AssignDesc_rec_2fwidget_2fstatus_2fTime_2eproto();
  friend void protobuf_ShutdownFile_rec_2fwidget_2fstatus_2fTime_2eproto();

  void InitAsDefaultInstance();
  static Dial* default_instance_;
};
// ===================================================================


// ===================================================================

// Text_Separator

// optional string separator = 1;
inline bool Text_Separator::has_separator() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Text_Separator::set_has_separator() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Text_Separator::clear_has_separator() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Text_Separator::clear_separator() {
  if (separator_ != &::google::protobuf::internal::kEmptyString) {
    separator_->clear();
  }
  clear_has_separator();
}
inline const ::std::string& Text_Separator::separator() const {
  return *separator_;
}
inline void Text_Separator::set_separator(const ::std::string& value) {
  set_has_separator();
  if (separator_ == &::google::protobuf::internal::kEmptyString) {
    separator_ = new ::std::string;
  }
  separator_->assign(value);
}
inline void Text_Separator::set_separator(const char* value) {
  set_has_separator();
  if (separator_ == &::google::protobuf::internal::kEmptyString) {
    separator_ = new ::std::string;
  }
  separator_->assign(value);
}
inline void Text_Separator::set_separator(const char* value, size_t size) {
  set_has_separator();
  if (separator_ == &::google::protobuf::internal::kEmptyString) {
    separator_ = new ::std::string;
  }
  separator_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Text_Separator::mutable_separator() {
  set_has_separator();
  if (separator_ == &::google::protobuf::internal::kEmptyString) {
    separator_ = new ::std::string;
  }
  return separator_;
}
inline ::std::string* Text_Separator::release_separator() {
  clear_has_separator();
  if (separator_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = separator_;
    separator_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Text_Separator::set_allocated_separator(::std::string* separator) {
  if (separator_ != &::google::protobuf::internal::kEmptyString) {
    delete separator_;
  }
  if (separator) {
    set_has_separator();
    separator_ = separator;
  } else {
    clear_has_separator();
    separator_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional uint32 width = 2;
inline bool Text_Separator::has_width() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Text_Separator::set_has_width() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Text_Separator::clear_has_width() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Text_Separator::clear_width() {
  width_ = 0u;
  clear_has_width();
}
inline ::google::protobuf::uint32 Text_Separator::width() const {
  return width_;
}
inline void Text_Separator::set_width(::google::protobuf::uint32 value) {
  set_has_width();
  width_ = value;
}

// optional bool flash = 3 [default = false];
inline bool Text_Separator::has_flash() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Text_Separator::set_has_flash() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Text_Separator::clear_has_flash() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Text_Separator::clear_flash() {
  flash_ = false;
  clear_has_flash();
}
inline bool Text_Separator::flash() const {
  return flash_;
}
inline void Text_Separator::set_flash(bool value) {
  set_has_flash();
  flash_ = value;
}

// optional bool display_ms = 4 [default = true];
inline bool Text_Separator::has_display_ms() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Text_Separator::set_has_display_ms() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Text_Separator::clear_has_display_ms() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Text_Separator::clear_display_ms() {
  display_ms_ = true;
  clear_has_display_ms();
}
inline bool Text_Separator::display_ms() const {
  return display_ms_;
}
inline void Text_Separator::set_display_ms(bool value) {
  set_has_display_ms();
  display_ms_ = value;
}

// -------------------------------------------------------------------

// Text_Fields

// optional bool hours = 1 [default = false];
inline bool Text_Fields::has_hours() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Text_Fields::set_has_hours() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Text_Fields::clear_has_hours() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Text_Fields::clear_hours() {
  hours_ = false;
  clear_has_hours();
}
inline bool Text_Fields::hours() const {
  return hours_;
}
inline void Text_Fields::set_hours(bool value) {
  set_has_hours();
  hours_ = value;
}

// optional bool minutes = 2 [default = true];
inline bool Text_Fields::has_minutes() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Text_Fields::set_has_minutes() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Text_Fields::clear_has_minutes() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Text_Fields::clear_minutes() {
  minutes_ = true;
  clear_has_minutes();
}
inline bool Text_Fields::minutes() const {
  return minutes_;
}
inline void Text_Fields::set_minutes(bool value) {
  set_has_minutes();
  minutes_ = value;
}

// optional bool seconds = 3 [default = true];
inline bool Text_Fields::has_seconds() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Text_Fields::set_has_seconds() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Text_Fields::clear_has_seconds() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Text_Fields::clear_seconds() {
  seconds_ = true;
  clear_has_seconds();
}
inline bool Text_Fields::seconds() const {
  return seconds_;
}
inline void Text_Fields::set_seconds(bool value) {
  set_has_seconds();
  seconds_ = value;
}

// optional bool milliseconds = 4 [default = true];
inline bool Text_Fields::has_milliseconds() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Text_Fields::set_has_milliseconds() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Text_Fields::clear_has_milliseconds() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Text_Fields::clear_milliseconds() {
  milliseconds_ = true;
  clear_has_milliseconds();
}
inline bool Text_Fields::milliseconds() const {
  return milliseconds_;
}
inline void Text_Fields::set_milliseconds(bool value) {
  set_has_milliseconds();
  milliseconds_ = value;
}

// optional bool frames = 5 [default = false];
inline bool Text_Fields::has_frames() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Text_Fields::set_has_frames() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Text_Fields::clear_has_frames() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Text_Fields::clear_frames() {
  frames_ = false;
  clear_has_frames();
}
inline bool Text_Fields::frames() const {
  return frames_;
}
inline void Text_Fields::set_frames(bool value) {
  set_has_frames();
  frames_ = value;
}

// -------------------------------------------------------------------

// Text

// optional .rec.widget.Widget widget = 1;
inline bool Text::has_widget() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Text::set_has_widget() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Text::clear_has_widget() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Text::clear_widget() {
  if (widget_ != NULL) widget_->::rec::widget::Widget::Clear();
  clear_has_widget();
}
inline const ::rec::widget::Widget& Text::widget() const {
  return widget_ != NULL ? *widget_ : *default_instance_->widget_;
}
inline ::rec::widget::Widget* Text::mutable_widget() {
  set_has_widget();
  if (widget_ == NULL) widget_ = new ::rec::widget::Widget;
  return widget_;
}
inline ::rec::widget::Widget* Text::release_widget() {
  clear_has_widget();
  ::rec::widget::Widget* temp = widget_;
  widget_ = NULL;
  return temp;
}
inline void Text::set_allocated_widget(::rec::widget::Widget* widget) {
  delete widget_;
  widget_ = widget;
  if (widget) {
    set_has_widget();
  } else {
    clear_has_widget();
  }
}

// optional .rec.widget.status.time.Text.Separator separator = 2;
inline bool Text::has_separator() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Text::set_has_separator() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Text::clear_has_separator() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Text::clear_separator() {
  if (separator_ != NULL) separator_->::rec::widget::status::time::Text_Separator::Clear();
  clear_has_separator();
}
inline const ::rec::widget::status::time::Text_Separator& Text::separator() const {
  return separator_ != NULL ? *separator_ : *default_instance_->separator_;
}
inline ::rec::widget::status::time::Text_Separator* Text::mutable_separator() {
  set_has_separator();
  if (separator_ == NULL) separator_ = new ::rec::widget::status::time::Text_Separator;
  return separator_;
}
inline ::rec::widget::status::time::Text_Separator* Text::release_separator() {
  clear_has_separator();
  ::rec::widget::status::time::Text_Separator* temp = separator_;
  separator_ = NULL;
  return temp;
}
inline void Text::set_allocated_separator(::rec::widget::status::time::Text_Separator* separator) {
  delete separator_;
  separator_ = separator;
  if (separator) {
    set_has_separator();
  } else {
    clear_has_separator();
  }
}

// optional .rec.widget.status.time.Text.Fields fields = 3;
inline bool Text::has_fields() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Text::set_has_fields() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Text::clear_has_fields() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Text::clear_fields() {
  if (fields_ != NULL) fields_->::rec::widget::status::time::Text_Fields::Clear();
  clear_has_fields();
}
inline const ::rec::widget::status::time::Text_Fields& Text::fields() const {
  return fields_ != NULL ? *fields_ : *default_instance_->fields_;
}
inline ::rec::widget::status::time::Text_Fields* Text::mutable_fields() {
  set_has_fields();
  if (fields_ == NULL) fields_ = new ::rec::widget::status::time::Text_Fields;
  return fields_;
}
inline ::rec::widget::status::time::Text_Fields* Text::release_fields() {
  clear_has_fields();
  ::rec::widget::status::time::Text_Fields* temp = fields_;
  fields_ = NULL;
  return temp;
}
inline void Text::set_allocated_fields(::rec::widget::status::time::Text_Fields* fields) {
  delete fields_;
  fields_ = fields;
  if (fields) {
    set_has_fields();
  } else {
    clear_has_fields();
  }
}

// optional bool use_global_clock = 4 [default = true];
inline bool Text::has_use_global_clock() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Text::set_has_use_global_clock() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Text::clear_has_use_global_clock() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Text::clear_use_global_clock() {
  use_global_clock_ = true;
  clear_has_use_global_clock();
}
inline bool Text::use_global_clock() const {
  return use_global_clock_;
}
inline void Text::set_use_global_clock(bool value) {
  set_has_use_global_clock();
  use_global_clock_ = value;
}

// -------------------------------------------------------------------

// Dial

// optional .rec.widget.Widget widget = 1;
inline bool Dial::has_widget() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Dial::set_has_widget() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Dial::clear_has_widget() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Dial::clear_widget() {
  if (widget_ != NULL) widget_->::rec::widget::Widget::Clear();
  clear_has_widget();
}
inline const ::rec::widget::Widget& Dial::widget() const {
  return widget_ != NULL ? *widget_ : *default_instance_->widget_;
}
inline ::rec::widget::Widget* Dial::mutable_widget() {
  set_has_widget();
  if (widget_ == NULL) widget_ = new ::rec::widget::Widget;
  return widget_;
}
inline ::rec::widget::Widget* Dial::release_widget() {
  clear_has_widget();
  ::rec::widget::Widget* temp = widget_;
  widget_ = NULL;
  return temp;
}
inline void Dial::set_allocated_widget(::rec::widget::Widget* widget) {
  delete widget_;
  widget_ = widget;
  if (widget) {
    set_has_widget();
  } else {
    clear_has_widget();
  }
}

// optional uint32 outline = 2;
inline bool Dial::has_outline() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Dial::set_has_outline() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Dial::clear_has_outline() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Dial::clear_outline() {
  outline_ = 0u;
  clear_has_outline();
}
inline ::google::protobuf::uint32 Dial::outline() const {
  return outline_;
}
inline void Dial::set_outline(::google::protobuf::uint32 value) {
  set_has_outline();
  outline_ = value;
}

// optional .rec.widget.status.time.Dial.Direction direction = 3 [default = CLOCKWISE];
inline bool Dial::has_direction() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Dial::set_has_direction() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Dial::clear_has_direction() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Dial::clear_direction() {
  direction_ = 1;
  clear_has_direction();
}
inline ::rec::widget::status::time::Dial_Direction Dial::direction() const {
  return static_cast< ::rec::widget::status::time::Dial_Direction >(direction_);
}
inline void Dial::set_direction(::rec::widget::status::time::Dial_Direction value) {
  assert(::rec::widget::status::time::Dial_Direction_IsValid(value));
  set_has_direction();
  direction_ = value;
}

// optional bool display_lap_count = 4;
inline bool Dial::has_display_lap_count() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Dial::set_has_display_lap_count() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Dial::clear_has_display_lap_count() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Dial::clear_display_lap_count() {
  display_lap_count_ = false;
  clear_has_display_lap_count();
}
inline bool Dial::display_lap_count() const {
  return display_lap_count_;
}
inline void Dial::set_display_lap_count(bool value) {
  set_has_display_lap_count();
  display_lap_count_ = value;
}

// optional double zero_point = 7;
inline bool Dial::has_zero_point() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Dial::set_has_zero_point() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Dial::clear_has_zero_point() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Dial::clear_zero_point() {
  zero_point_ = 0;
  clear_has_zero_point();
}
inline double Dial::zero_point() const {
  return zero_point_;
}
inline void Dial::set_zero_point(double value) {
  set_has_zero_point();
  zero_point_ = value;
}

// optional bool empty_on_zero = 8 [default = true];
inline bool Dial::has_empty_on_zero() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Dial::set_has_empty_on_zero() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Dial::clear_has_empty_on_zero() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Dial::clear_empty_on_zero() {
  empty_on_zero_ = true;
  clear_has_empty_on_zero();
}
inline bool Dial::empty_on_zero() const {
  return empty_on_zero_;
}
inline void Dial::set_empty_on_zero(bool value) {
  set_has_empty_on_zero();
  empty_on_zero_ = value;
}

// optional .rec.gui.Color from_color = 9;
inline bool Dial::has_from_color() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Dial::set_has_from_color() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Dial::clear_has_from_color() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Dial::clear_from_color() {
  if (from_color_ != NULL) from_color_->::rec::gui::Color::Clear();
  clear_has_from_color();
}
inline const ::rec::gui::Color& Dial::from_color() const {
  return from_color_ != NULL ? *from_color_ : *default_instance_->from_color_;
}
inline ::rec::gui::Color* Dial::mutable_from_color() {
  set_has_from_color();
  if (from_color_ == NULL) from_color_ = new ::rec::gui::Color;
  return from_color_;
}
inline ::rec::gui::Color* Dial::release_from_color() {
  clear_has_from_color();
  ::rec::gui::Color* temp = from_color_;
  from_color_ = NULL;
  return temp;
}
inline void Dial::set_allocated_from_color(::rec::gui::Color* from_color) {
  delete from_color_;
  from_color_ = from_color;
  if (from_color) {
    set_has_from_color();
  } else {
    clear_has_from_color();
  }
}

// optional .rec.gui.Color to_color = 10;
inline bool Dial::has_to_color() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Dial::set_has_to_color() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Dial::clear_has_to_color() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Dial::clear_to_color() {
  if (to_color_ != NULL) to_color_->::rec::gui::Color::Clear();
  clear_has_to_color();
}
inline const ::rec::gui::Color& Dial::to_color() const {
  return to_color_ != NULL ? *to_color_ : *default_instance_->to_color_;
}
inline ::rec::gui::Color* Dial::mutable_to_color() {
  set_has_to_color();
  if (to_color_ == NULL) to_color_ = new ::rec::gui::Color;
  return to_color_;
}
inline ::rec::gui::Color* Dial::release_to_color() {
  clear_has_to_color();
  ::rec::gui::Color* temp = to_color_;
  to_color_ = NULL;
  return temp;
}
inline void Dial::set_allocated_to_color(::rec::gui::Color* to_color) {
  delete to_color_;
  to_color_ = to_color;
  if (to_color) {
    set_has_to_color();
  } else {
    clear_has_to_color();
  }
}

// optional bool use_global_clock = 11 [default = true];
inline bool Dial::has_use_global_clock() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Dial::set_has_use_global_clock() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Dial::clear_has_use_global_clock() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Dial::clear_use_global_clock() {
  use_global_clock_ = true;
  clear_has_use_global_clock();
}
inline bool Dial::use_global_clock() const {
  return use_global_clock_;
}
inline void Dial::set_use_global_clock(bool value) {
  set_has_use_global_clock();
  use_global_clock_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace time
}  // namespace status
}  // namespace widget
}  // namespace rec

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::rec::widget::status::time::Dial_Direction>() {
  return ::rec::widget::status::time::Dial_Direction_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rec_2fwidget_2fstatus_2fTime_2eproto__INCLUDED
