// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/gui/menu/RecentFiles.proto

#ifndef PROTOBUF_rec_2fgui_2fmenu_2fRecentFiles_2eproto__INCLUDED
#define PROTOBUF_rec_2fgui_2fmenu_2fRecentFiles_2eproto__INCLUDED

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
#include "rec/music/Metadata.pb.h"
#include "rec/util/file/VirtualFile.pb.h"
// @@protoc_insertion_point(includes)

namespace rec {
namespace gui {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_rec_2fgui_2fmenu_2fRecentFiles_2eproto();
void protobuf_AssignDesc_rec_2fgui_2fmenu_2fRecentFiles_2eproto();
void protobuf_ShutdownFile_rec_2fgui_2fmenu_2fRecentFiles_2eproto();

class RecentFile;
class RecentFiles;

// ===================================================================

class RecentFile : public ::google::protobuf::Message {
 public:
  RecentFile();
  virtual ~RecentFile();

  RecentFile(const RecentFile& from);

  inline RecentFile& operator=(const RecentFile& from) {
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
  static const RecentFile& default_instance();

  void Swap(RecentFile* other);

  // implements Message ----------------------------------------------

  RecentFile* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RecentFile& from);
  void MergeFrom(const RecentFile& from);
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

  // optional int64 timestamp = 1;
  inline bool has_timestamp() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  inline ::google::protobuf::int64 timestamp() const;
  inline void set_timestamp(::google::protobuf::int64 value);

  // optional .rec.util.file.VirtualFile file = 2;
  inline bool has_file() const;
  inline void clear_file();
  static const int kFileFieldNumber = 2;
  inline const ::rec::util::file::VirtualFile& file() const;
  inline ::rec::util::file::VirtualFile* mutable_file();
  inline ::rec::util::file::VirtualFile* release_file();
  inline void set_allocated_file(::rec::util::file::VirtualFile* file);

  // optional .rec.music.Metadata metadata = 3;
  inline bool has_metadata() const;
  inline void clear_metadata();
  static const int kMetadataFieldNumber = 3;
  inline const ::rec::music::Metadata& metadata() const;
  inline ::rec::music::Metadata* mutable_metadata();
  inline ::rec::music::Metadata* release_metadata();
  inline void set_allocated_metadata(::rec::music::Metadata* metadata);

  // optional string metadata_string = 4;
  inline bool has_metadata_string() const;
  inline void clear_metadata_string();
  static const int kMetadataStringFieldNumber = 4;
  inline const ::std::string& metadata_string() const;
  inline void set_metadata_string(const ::std::string& value);
  inline void set_metadata_string(const char* value);
  inline void set_metadata_string(const char* value, size_t size);
  inline ::std::string* mutable_metadata_string();
  inline ::std::string* release_metadata_string();
  inline void set_allocated_metadata_string(::std::string* metadata_string);

  // @@protoc_insertion_point(class_scope:rec.gui.RecentFile)
 private:
  inline void set_has_timestamp();
  inline void clear_has_timestamp();
  inline void set_has_file();
  inline void clear_has_file();
  inline void set_has_metadata();
  inline void clear_has_metadata();
  inline void set_has_metadata_string();
  inline void clear_has_metadata_string();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 timestamp_;
  ::rec::util::file::VirtualFile* file_;
  ::rec::music::Metadata* metadata_;
  ::std::string* metadata_string_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fgui_2fmenu_2fRecentFiles_2eproto();
  friend void protobuf_AssignDesc_rec_2fgui_2fmenu_2fRecentFiles_2eproto();
  friend void protobuf_ShutdownFile_rec_2fgui_2fmenu_2fRecentFiles_2eproto();

  void InitAsDefaultInstance();
  static RecentFile* default_instance_;
};
// -------------------------------------------------------------------

class RecentFiles : public ::google::protobuf::Message {
 public:
  RecentFiles();
  virtual ~RecentFiles();

  RecentFiles(const RecentFiles& from);

  inline RecentFiles& operator=(const RecentFiles& from) {
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
  static const RecentFiles& default_instance();

  void Swap(RecentFiles* other);

  // implements Message ----------------------------------------------

  RecentFiles* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RecentFiles& from);
  void MergeFrom(const RecentFiles& from);
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

  // repeated .rec.gui.RecentFile file = 3;
  inline int file_size() const;
  inline void clear_file();
  static const int kFileFieldNumber = 3;
  inline const ::rec::gui::RecentFile& file(int index) const;
  inline ::rec::gui::RecentFile* mutable_file(int index);
  inline ::rec::gui::RecentFile* add_file();
  inline const ::google::protobuf::RepeatedPtrField< ::rec::gui::RecentFile >&
      file() const;
  inline ::google::protobuf::RepeatedPtrField< ::rec::gui::RecentFile >*
      mutable_file();

  // optional int32 max_files = 4 [default = 16];
  inline bool has_max_files() const;
  inline void clear_max_files();
  static const int kMaxFilesFieldNumber = 4;
  inline ::google::protobuf::int32 max_files() const;
  inline void set_max_files(::google::protobuf::int32 value);

  // optional bool reload_most_recent = 5 [default = true];
  inline bool has_reload_most_recent() const;
  inline void clear_reload_most_recent();
  static const int kReloadMostRecentFieldNumber = 5;
  inline bool reload_most_recent() const;
  inline void set_reload_most_recent(bool value);

  // @@protoc_insertion_point(class_scope:rec.gui.RecentFiles)
 private:
  inline void set_has_max_files();
  inline void clear_has_max_files();
  inline void set_has_reload_most_recent();
  inline void clear_has_reload_most_recent();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::rec::gui::RecentFile > file_;
  ::google::protobuf::int32 max_files_;
  bool reload_most_recent_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_rec_2fgui_2fmenu_2fRecentFiles_2eproto();
  friend void protobuf_AssignDesc_rec_2fgui_2fmenu_2fRecentFiles_2eproto();
  friend void protobuf_ShutdownFile_rec_2fgui_2fmenu_2fRecentFiles_2eproto();

  void InitAsDefaultInstance();
  static RecentFiles* default_instance_;
};
// ===================================================================


// ===================================================================

// RecentFile

// optional int64 timestamp = 1;
inline bool RecentFile::has_timestamp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RecentFile::set_has_timestamp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RecentFile::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RecentFile::clear_timestamp() {
  timestamp_ = GOOGLE_LONGLONG(0);
  clear_has_timestamp();
}
inline ::google::protobuf::int64 RecentFile::timestamp() const {
  return timestamp_;
}
inline void RecentFile::set_timestamp(::google::protobuf::int64 value) {
  set_has_timestamp();
  timestamp_ = value;
}

// optional .rec.util.file.VirtualFile file = 2;
inline bool RecentFile::has_file() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RecentFile::set_has_file() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RecentFile::clear_has_file() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RecentFile::clear_file() {
  if (file_ != NULL) file_->::rec::util::file::VirtualFile::Clear();
  clear_has_file();
}
inline const ::rec::util::file::VirtualFile& RecentFile::file() const {
  return file_ != NULL ? *file_ : *default_instance_->file_;
}
inline ::rec::util::file::VirtualFile* RecentFile::mutable_file() {
  set_has_file();
  if (file_ == NULL) file_ = new ::rec::util::file::VirtualFile;
  return file_;
}
inline ::rec::util::file::VirtualFile* RecentFile::release_file() {
  clear_has_file();
  ::rec::util::file::VirtualFile* temp = file_;
  file_ = NULL;
  return temp;
}
inline void RecentFile::set_allocated_file(::rec::util::file::VirtualFile* file) {
  delete file_;
  file_ = file;
  if (file) {
    set_has_file();
  } else {
    clear_has_file();
  }
}

// optional .rec.music.Metadata metadata = 3;
inline bool RecentFile::has_metadata() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RecentFile::set_has_metadata() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RecentFile::clear_has_metadata() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RecentFile::clear_metadata() {
  if (metadata_ != NULL) metadata_->::rec::music::Metadata::Clear();
  clear_has_metadata();
}
inline const ::rec::music::Metadata& RecentFile::metadata() const {
  return metadata_ != NULL ? *metadata_ : *default_instance_->metadata_;
}
inline ::rec::music::Metadata* RecentFile::mutable_metadata() {
  set_has_metadata();
  if (metadata_ == NULL) metadata_ = new ::rec::music::Metadata;
  return metadata_;
}
inline ::rec::music::Metadata* RecentFile::release_metadata() {
  clear_has_metadata();
  ::rec::music::Metadata* temp = metadata_;
  metadata_ = NULL;
  return temp;
}
inline void RecentFile::set_allocated_metadata(::rec::music::Metadata* metadata) {
  delete metadata_;
  metadata_ = metadata;
  if (metadata) {
    set_has_metadata();
  } else {
    clear_has_metadata();
  }
}

// optional string metadata_string = 4;
inline bool RecentFile::has_metadata_string() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void RecentFile::set_has_metadata_string() {
  _has_bits_[0] |= 0x00000008u;
}
inline void RecentFile::clear_has_metadata_string() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void RecentFile::clear_metadata_string() {
  if (metadata_string_ != &::google::protobuf::internal::kEmptyString) {
    metadata_string_->clear();
  }
  clear_has_metadata_string();
}
inline const ::std::string& RecentFile::metadata_string() const {
  return *metadata_string_;
}
inline void RecentFile::set_metadata_string(const ::std::string& value) {
  set_has_metadata_string();
  if (metadata_string_ == &::google::protobuf::internal::kEmptyString) {
    metadata_string_ = new ::std::string;
  }
  metadata_string_->assign(value);
}
inline void RecentFile::set_metadata_string(const char* value) {
  set_has_metadata_string();
  if (metadata_string_ == &::google::protobuf::internal::kEmptyString) {
    metadata_string_ = new ::std::string;
  }
  metadata_string_->assign(value);
}
inline void RecentFile::set_metadata_string(const char* value, size_t size) {
  set_has_metadata_string();
  if (metadata_string_ == &::google::protobuf::internal::kEmptyString) {
    metadata_string_ = new ::std::string;
  }
  metadata_string_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* RecentFile::mutable_metadata_string() {
  set_has_metadata_string();
  if (metadata_string_ == &::google::protobuf::internal::kEmptyString) {
    metadata_string_ = new ::std::string;
  }
  return metadata_string_;
}
inline ::std::string* RecentFile::release_metadata_string() {
  clear_has_metadata_string();
  if (metadata_string_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = metadata_string_;
    metadata_string_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void RecentFile::set_allocated_metadata_string(::std::string* metadata_string) {
  if (metadata_string_ != &::google::protobuf::internal::kEmptyString) {
    delete metadata_string_;
  }
  if (metadata_string) {
    set_has_metadata_string();
    metadata_string_ = metadata_string;
  } else {
    clear_has_metadata_string();
    metadata_string_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// RecentFiles

// repeated .rec.gui.RecentFile file = 3;
inline int RecentFiles::file_size() const {
  return file_.size();
}
inline void RecentFiles::clear_file() {
  file_.Clear();
}
inline const ::rec::gui::RecentFile& RecentFiles::file(int index) const {
  return file_.Get(index);
}
inline ::rec::gui::RecentFile* RecentFiles::mutable_file(int index) {
  return file_.Mutable(index);
}
inline ::rec::gui::RecentFile* RecentFiles::add_file() {
  return file_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::rec::gui::RecentFile >&
RecentFiles::file() const {
  return file_;
}
inline ::google::protobuf::RepeatedPtrField< ::rec::gui::RecentFile >*
RecentFiles::mutable_file() {
  return &file_;
}

// optional int32 max_files = 4 [default = 16];
inline bool RecentFiles::has_max_files() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RecentFiles::set_has_max_files() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RecentFiles::clear_has_max_files() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RecentFiles::clear_max_files() {
  max_files_ = 16;
  clear_has_max_files();
}
inline ::google::protobuf::int32 RecentFiles::max_files() const {
  return max_files_;
}
inline void RecentFiles::set_max_files(::google::protobuf::int32 value) {
  set_has_max_files();
  max_files_ = value;
}

// optional bool reload_most_recent = 5 [default = true];
inline bool RecentFiles::has_reload_most_recent() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RecentFiles::set_has_reload_most_recent() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RecentFiles::clear_has_reload_most_recent() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RecentFiles::clear_reload_most_recent() {
  reload_most_recent_ = true;
  clear_has_reload_most_recent();
}
inline bool RecentFiles::reload_most_recent() const {
  return reload_most_recent_;
}
inline void RecentFiles::set_reload_most_recent(bool value) {
  set_has_reload_most_recent();
  reload_most_recent_ = value;
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

#endif  // PROTOBUF_rec_2fgui_2fmenu_2fRecentFiles_2eproto__INCLUDED
