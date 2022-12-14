// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/util/Binary.proto

#ifndef PROTOBUF_rec_2futil_2fBinary_2eproto__INCLUDED
#define PROTOBUF_rec_2futil_2fBinary_2eproto__INCLUDED

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
namespace util {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rec_2futil_2fBinary_2eproto();
void protobuf_AssignDesc_rec_2futil_2fBinary_2eproto();
void protobuf_ShutdownFile_rec_2futil_2fBinary_2eproto();

class BinaryNames;

// ===================================================================

class BinaryNames : public ::google::protobuf::Message {
 public:
  BinaryNames();
  virtual ~BinaryNames();

  BinaryNames(const BinaryNames& from);

  inline BinaryNames& operator=(const BinaryNames& from) {
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
  static const BinaryNames& default_instance();

  void Swap(BinaryNames* other);

  // implements Message ----------------------------------------------

  BinaryNames* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BinaryNames& from);
  void MergeFrom(const BinaryNames& from);
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

  // repeated string name = 1;
  inline int name_size() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name(int index) const;
  inline ::std::string* mutable_name(int index);
  inline void set_name(int index, const ::std::string& value);
  inline void set_name(int index, const char* value);
  inline void set_name(int index, const char* value, size_t size);
  inline ::std::string* add_name();
  inline void add_name(const ::std::string& value);
  inline void add_name(const char* value);
  inline void add_name(const char* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& name() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_name();

  // @@protoc_insertion_point(class_scope:rec.util.BinaryNames)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::std::string> name_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2futil_2fBinary_2eproto();
  friend void protobuf_AssignDesc_rec_2futil_2fBinary_2eproto();
  friend void protobuf_ShutdownFile_rec_2futil_2fBinary_2eproto();

  void InitAsDefaultInstance();
  static BinaryNames* default_instance_;
};
// ===================================================================


// ===================================================================

// BinaryNames

// repeated string name = 1;
inline int BinaryNames::name_size() const {
  return name_.size();
}
inline void BinaryNames::clear_name() {
  name_.Clear();
}
inline const ::std::string& BinaryNames::name(int index) const {
  return name_.Get(index);
}
inline ::std::string* BinaryNames::mutable_name(int index) {
  return name_.Mutable(index);
}
inline void BinaryNames::set_name(int index, const ::std::string& value) {
  name_.Mutable(index)->assign(value);
}
inline void BinaryNames::set_name(int index, const char* value) {
  name_.Mutable(index)->assign(value);
}
inline void BinaryNames::set_name(int index, const char* value, size_t size) {
  name_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* BinaryNames::add_name() {
  return name_.Add();
}
inline void BinaryNames::add_name(const ::std::string& value) {
  name_.Add()->assign(value);
}
inline void BinaryNames::add_name(const char* value) {
  name_.Add()->assign(value);
}
inline void BinaryNames::add_name(const char* value, size_t size) {
  name_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
BinaryNames::name() const {
  return name_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
BinaryNames::mutable_name() {
  return &name_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace util
}  // namespace rec

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_rec_2futil_2fBinary_2eproto__INCLUDED
