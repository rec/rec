// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/gui/proto/Text.proto

#ifndef PROTOBUF_rec_2fgui_2fproto_2fText_2eproto__INCLUDED
#define PROTOBUF_rec_2fgui_2fproto_2fText_2eproto__INCLUDED

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace rec {
namespace gui {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rec_2fgui_2fproto_2fText_2eproto();
void protobuf_AssignDesc_rec_2fgui_2fproto_2fText_2eproto();
void protobuf_ShutdownFile_rec_2fgui_2fproto_2fText_2eproto();

class TextProto;

// ===================================================================

class TextProto : public ::google::protobuf::Message {
 public:
  TextProto();
  virtual ~TextProto();

  TextProto(const TextProto& from);

  inline TextProto& operator=(const TextProto& from) {
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
  static const TextProto& default_instance();

  void Swap(TextProto* other);

  // implements Message ----------------------------------------------

  TextProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TextProto& from);
  void MergeFrom(const TextProto& from);
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

  // optional bool multiline = 1;
  inline bool has_multiline() const;
  inline void clear_multiline();
  static const int kMultilineFieldNumber = 1;
  inline bool multiline() const;
  inline void set_multiline(bool value);

  // optional string caption = 2;
  inline bool has_caption() const;
  inline void clear_caption();
  static const int kCaptionFieldNumber = 2;
  inline const ::std::string& caption() const;
  inline void set_caption(const ::std::string& value);
  inline void set_caption(const char* value);
  inline void set_caption(const char* value, size_t size);
  inline ::std::string* mutable_caption();
  inline ::std::string* release_caption();
  inline void set_allocated_caption(::std::string* caption);

  // @@protoc_insertion_point(class_scope:rec.gui.TextProto)
 private:
  inline void set_has_multiline();
  inline void clear_has_multiline();
  inline void set_has_caption();
  inline void clear_has_caption();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* caption_;
  bool multiline_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fgui_2fproto_2fText_2eproto();
  friend void protobuf_AssignDesc_rec_2fgui_2fproto_2fText_2eproto();
  friend void protobuf_ShutdownFile_rec_2fgui_2fproto_2fText_2eproto();

  void InitAsDefaultInstance();
  static TextProto* default_instance_;
};
// ===================================================================


// ===================================================================

// TextProto

// optional bool multiline = 1;
inline bool TextProto::has_multiline() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TextProto::set_has_multiline() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TextProto::clear_has_multiline() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TextProto::clear_multiline() {
  multiline_ = false;
  clear_has_multiline();
}
inline bool TextProto::multiline() const {
  return multiline_;
}
inline void TextProto::set_multiline(bool value) {
  set_has_multiline();
  multiline_ = value;
}

// optional string caption = 2;
inline bool TextProto::has_caption() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TextProto::set_has_caption() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TextProto::clear_has_caption() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TextProto::clear_caption() {
  if (caption_ != &::google::protobuf::internal::kEmptyString) {
    caption_->clear();
  }
  clear_has_caption();
}
inline const ::std::string& TextProto::caption() const {
  return *caption_;
}
inline void TextProto::set_caption(const ::std::string& value) {
  set_has_caption();
  if (caption_ == &::google::protobuf::internal::kEmptyString) {
    caption_ = new ::std::string;
  }
  caption_->assign(value);
}
inline void TextProto::set_caption(const char* value) {
  set_has_caption();
  if (caption_ == &::google::protobuf::internal::kEmptyString) {
    caption_ = new ::std::string;
  }
  caption_->assign(value);
}
inline void TextProto::set_caption(const char* value, size_t size) {
  set_has_caption();
  if (caption_ == &::google::protobuf::internal::kEmptyString) {
    caption_ = new ::std::string;
  }
  caption_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TextProto::mutable_caption() {
  set_has_caption();
  if (caption_ == &::google::protobuf::internal::kEmptyString) {
    caption_ = new ::std::string;
  }
  return caption_;
}
inline ::std::string* TextProto::release_caption() {
  clear_has_caption();
  if (caption_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = caption_;
    caption_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TextProto::set_allocated_caption(::std::string* caption) {
  if (caption_ != &::google::protobuf::internal::kEmptyString) {
    delete caption_;
  }
  if (caption) {
    set_has_caption();
    caption_ = caption;
  } else {
    clear_has_caption();
    caption_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace gui
}  // namespace rec

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rec_2fgui_2fproto_2fText_2eproto__INCLUDED
