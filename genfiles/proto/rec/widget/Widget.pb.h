// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/widget/Widget.proto

#ifndef PROTOBUF_rec_2fwidget_2fWidget_2eproto__INCLUDED
#define PROTOBUF_rec_2fwidget_2fWidget_2eproto__INCLUDED

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
#include "rec/gui/Font.pb.h"
#include "rec/gui/Geometry.pb.h"
// @@protoc_insertion_point(includes)

namespace rec {
namespace widget {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rec_2fwidget_2fWidget_2eproto();
void protobuf_AssignDesc_rec_2fwidget_2fWidget_2eproto();
void protobuf_ShutdownFile_rec_2fwidget_2fWidget_2eproto();

class State;
class Widget;

enum State_MouseState {
  State_MouseState_NONE = 0,
  State_MouseState_DOWN = 1,
  State_MouseState_HOVERING = 2
};
bool State_MouseState_IsValid(int value);
const State_MouseState State_MouseState_MouseState_MIN = State_MouseState_NONE;
const State_MouseState State_MouseState_MouseState_MAX = State_MouseState_HOVERING;
const int State_MouseState_MouseState_ARRAYSIZE = State_MouseState_MouseState_MAX + 1;

const ::google::protobuf::EnumDescriptor* State_MouseState_descriptor();
inline const ::std::string& State_MouseState_Name(State_MouseState value) {
  return ::google::protobuf::internal::NameOfEnum(
    State_MouseState_descriptor(), value);
}
inline bool State_MouseState_Parse(
    const ::std::string& name, State_MouseState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<State_MouseState>(
    State_MouseState_descriptor(), name, value);
}
// ===================================================================

class State : public ::google::protobuf::Message {
 public:
  State();
  virtual ~State();

  State(const State& from);

  inline State& operator=(const State& from) {
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
  static const State& default_instance();

  void Swap(State* other);

  // implements Message ----------------------------------------------

  State* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const State& from);
  void MergeFrom(const State& from);
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

  typedef State_MouseState MouseState;
  static const MouseState NONE = State_MouseState_NONE;
  static const MouseState DOWN = State_MouseState_DOWN;
  static const MouseState HOVERING = State_MouseState_HOVERING;
  static inline bool MouseState_IsValid(int value) {
    return State_MouseState_IsValid(value);
  }
  static const MouseState MouseState_MIN =
    State_MouseState_MouseState_MIN;
  static const MouseState MouseState_MAX =
    State_MouseState_MouseState_MAX;
  static const int MouseState_ARRAYSIZE =
    State_MouseState_MouseState_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  MouseState_descriptor() {
    return State_MouseState_descriptor();
  }
  static inline const ::std::string& MouseState_Name(MouseState value) {
    return State_MouseState_Name(value);
  }
  static inline bool MouseState_Parse(const ::std::string& name,
      MouseState* value) {
    return State_MouseState_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional bool selected = 1;
  inline bool has_selected() const;
  inline void clear_selected();
  static const int kSelectedFieldNumber = 1;
  inline bool selected() const;
  inline void set_selected(bool value);

  // optional .rec.widget.State.MouseState mouse = 2;
  inline bool has_mouse() const;
  inline void clear_mouse();
  static const int kMouseFieldNumber = 2;
  inline ::rec::widget::State_MouseState mouse() const;
  inline void set_mouse(::rec::widget::State_MouseState value);

  // @@protoc_insertion_point(class_scope:rec.widget.State)
 private:
  inline void set_has_selected();
  inline void clear_has_selected();
  inline void set_has_mouse();
  inline void clear_has_mouse();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  bool selected_;
  int mouse_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fwidget_2fWidget_2eproto();
  friend void protobuf_AssignDesc_rec_2fwidget_2fWidget_2eproto();
  friend void protobuf_ShutdownFile_rec_2fwidget_2fWidget_2eproto();

  void InitAsDefaultInstance();
  static State* default_instance_;
};
// -------------------------------------------------------------------

class Widget : public ::google::protobuf::Message {
 public:
  Widget();
  virtual ~Widget();

  Widget(const Widget& from);

  inline Widget& operator=(const Widget& from) {
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
  static const Widget& default_instance();

  void Swap(Widget* other);

  // implements Message ----------------------------------------------

  Widget* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Widget& from);
  void MergeFrom(const Widget& from);
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

  // optional string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional .rec.gui.Colors colors = 2;
  inline bool has_colors() const;
  inline void clear_colors();
  static const int kColorsFieldNumber = 2;
  inline const ::rec::gui::Colors& colors() const;
  inline ::rec::gui::Colors* mutable_colors();
  inline ::rec::gui::Colors* release_colors();
  inline void set_allocated_colors(::rec::gui::Colors* colors);

  // optional .rec.gui.FontDesc font = 3;
  inline bool has_font() const;
  inline void clear_font();
  static const int kFontFieldNumber = 3;
  inline const ::rec::gui::FontDesc& font() const;
  inline ::rec::gui::FontDesc* mutable_font();
  inline ::rec::gui::FontDesc* release_font();
  inline void set_allocated_font(::rec::gui::FontDesc* font);

  // optional uint32 margin = 4 [default = 2];
  inline bool has_margin() const;
  inline void clear_margin();
  static const int kMarginFieldNumber = 4;
  inline ::google::protobuf::uint32 margin() const;
  inline void set_margin(::google::protobuf::uint32 value);

  // optional bool transparent = 5;
  inline bool has_transparent() const;
  inline void clear_transparent();
  static const int kTransparentFieldNumber = 5;
  inline bool transparent() const;
  inline void set_transparent(bool value);

  // optional .rec.gui.Layer layer = 6;
  inline bool has_layer() const;
  inline void clear_layer();
  static const int kLayerFieldNumber = 6;
  inline const ::rec::gui::Layer& layer() const;
  inline ::rec::gui::Layer* mutable_layer();
  inline ::rec::gui::Layer* release_layer();
  inline void set_allocated_layer(::rec::gui::Layer* layer);

  // optional .rec.widget.State state = 7;
  inline bool has_state() const;
  inline void clear_state();
  static const int kStateFieldNumber = 7;
  inline const ::rec::widget::State& state() const;
  inline ::rec::widget::State* mutable_state();
  inline ::rec::widget::State* release_state();
  inline void set_allocated_state(::rec::widget::State* state);

  // @@protoc_insertion_point(class_scope:rec.widget.Widget)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_colors();
  inline void clear_has_colors();
  inline void set_has_font();
  inline void clear_has_font();
  inline void set_has_margin();
  inline void clear_has_margin();
  inline void set_has_transparent();
  inline void clear_has_transparent();
  inline void set_has_layer();
  inline void clear_has_layer();
  inline void set_has_state();
  inline void clear_has_state();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::rec::gui::Colors* colors_;
  ::rec::gui::FontDesc* font_;
  ::google::protobuf::uint32 margin_;
  bool transparent_;
  ::rec::gui::Layer* layer_;
  ::rec::widget::State* state_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fwidget_2fWidget_2eproto();
  friend void protobuf_AssignDesc_rec_2fwidget_2fWidget_2eproto();
  friend void protobuf_ShutdownFile_rec_2fwidget_2fWidget_2eproto();

  void InitAsDefaultInstance();
  static Widget* default_instance_;
};
// ===================================================================


// ===================================================================

// State

// optional bool selected = 1;
inline bool State::has_selected() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void State::set_has_selected() {
  _has_bits_[0] |= 0x00000001u;
}
inline void State::clear_has_selected() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void State::clear_selected() {
  selected_ = false;
  clear_has_selected();
}
inline bool State::selected() const {
  return selected_;
}
inline void State::set_selected(bool value) {
  set_has_selected();
  selected_ = value;
}

// optional .rec.widget.State.MouseState mouse = 2;
inline bool State::has_mouse() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void State::set_has_mouse() {
  _has_bits_[0] |= 0x00000002u;
}
inline void State::clear_has_mouse() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void State::clear_mouse() {
  mouse_ = 0;
  clear_has_mouse();
}
inline ::rec::widget::State_MouseState State::mouse() const {
  return static_cast< ::rec::widget::State_MouseState >(mouse_);
}
inline void State::set_mouse(::rec::widget::State_MouseState value) {
  assert(::rec::widget::State_MouseState_IsValid(value));
  set_has_mouse();
  mouse_ = value;
}

// -------------------------------------------------------------------

// Widget

// optional string name = 1;
inline bool Widget::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Widget::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Widget::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Widget::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Widget::name() const {
  return *name_;
}
inline void Widget::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Widget::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Widget::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Widget::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Widget::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void Widget::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional .rec.gui.Colors colors = 2;
inline bool Widget::has_colors() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Widget::set_has_colors() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Widget::clear_has_colors() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Widget::clear_colors() {
  if (colors_ != NULL) colors_->::rec::gui::Colors::Clear();
  clear_has_colors();
}
inline const ::rec::gui::Colors& Widget::colors() const {
  return colors_ != NULL ? *colors_ : *default_instance_->colors_;
}
inline ::rec::gui::Colors* Widget::mutable_colors() {
  set_has_colors();
  if (colors_ == NULL) colors_ = new ::rec::gui::Colors;
  return colors_;
}
inline ::rec::gui::Colors* Widget::release_colors() {
  clear_has_colors();
  ::rec::gui::Colors* temp = colors_;
  colors_ = NULL;
  return temp;
}
inline void Widget::set_allocated_colors(::rec::gui::Colors* colors) {
  delete colors_;
  colors_ = colors;
  if (colors) {
    set_has_colors();
  } else {
    clear_has_colors();
  }
}

// optional .rec.gui.FontDesc font = 3;
inline bool Widget::has_font() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Widget::set_has_font() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Widget::clear_has_font() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Widget::clear_font() {
  if (font_ != NULL) font_->::rec::gui::FontDesc::Clear();
  clear_has_font();
}
inline const ::rec::gui::FontDesc& Widget::font() const {
  return font_ != NULL ? *font_ : *default_instance_->font_;
}
inline ::rec::gui::FontDesc* Widget::mutable_font() {
  set_has_font();
  if (font_ == NULL) font_ = new ::rec::gui::FontDesc;
  return font_;
}
inline ::rec::gui::FontDesc* Widget::release_font() {
  clear_has_font();
  ::rec::gui::FontDesc* temp = font_;
  font_ = NULL;
  return temp;
}
inline void Widget::set_allocated_font(::rec::gui::FontDesc* font) {
  delete font_;
  font_ = font;
  if (font) {
    set_has_font();
  } else {
    clear_has_font();
  }
}

// optional uint32 margin = 4 [default = 2];
inline bool Widget::has_margin() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Widget::set_has_margin() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Widget::clear_has_margin() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Widget::clear_margin() {
  margin_ = 2u;
  clear_has_margin();
}
inline ::google::protobuf::uint32 Widget::margin() const {
  return margin_;
}
inline void Widget::set_margin(::google::protobuf::uint32 value) {
  set_has_margin();
  margin_ = value;
}

// optional bool transparent = 5;
inline bool Widget::has_transparent() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Widget::set_has_transparent() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Widget::clear_has_transparent() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Widget::clear_transparent() {
  transparent_ = false;
  clear_has_transparent();
}
inline bool Widget::transparent() const {
  return transparent_;
}
inline void Widget::set_transparent(bool value) {
  set_has_transparent();
  transparent_ = value;
}

// optional .rec.gui.Layer layer = 6;
inline bool Widget::has_layer() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Widget::set_has_layer() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Widget::clear_has_layer() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Widget::clear_layer() {
  if (layer_ != NULL) layer_->::rec::gui::Layer::Clear();
  clear_has_layer();
}
inline const ::rec::gui::Layer& Widget::layer() const {
  return layer_ != NULL ? *layer_ : *default_instance_->layer_;
}
inline ::rec::gui::Layer* Widget::mutable_layer() {
  set_has_layer();
  if (layer_ == NULL) layer_ = new ::rec::gui::Layer;
  return layer_;
}
inline ::rec::gui::Layer* Widget::release_layer() {
  clear_has_layer();
  ::rec::gui::Layer* temp = layer_;
  layer_ = NULL;
  return temp;
}
inline void Widget::set_allocated_layer(::rec::gui::Layer* layer) {
  delete layer_;
  layer_ = layer;
  if (layer) {
    set_has_layer();
  } else {
    clear_has_layer();
  }
}

// optional .rec.widget.State state = 7;
inline bool Widget::has_state() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Widget::set_has_state() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Widget::clear_has_state() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Widget::clear_state() {
  if (state_ != NULL) state_->::rec::widget::State::Clear();
  clear_has_state();
}
inline const ::rec::widget::State& Widget::state() const {
  return state_ != NULL ? *state_ : *default_instance_->state_;
}
inline ::rec::widget::State* Widget::mutable_state() {
  set_has_state();
  if (state_ == NULL) state_ = new ::rec::widget::State;
  return state_;
}
inline ::rec::widget::State* Widget::release_state() {
  clear_has_state();
  ::rec::widget::State* temp = state_;
  state_ = NULL;
  return temp;
}
inline void Widget::set_allocated_state(::rec::widget::State* state) {
  delete state_;
  state_ = state;
  if (state) {
    set_has_state();
  } else {
    clear_has_state();
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace widget
}  // namespace rec

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::rec::widget::State_MouseState>() {
  return ::rec::widget::State_MouseState_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rec_2fwidget_2fWidget_2eproto__INCLUDED
