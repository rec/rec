// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/gui/proto/Switcher.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "rec/gui/proto/Switcher.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace rec {
namespace gui {

namespace {

const ::google::protobuf::Descriptor* SwitcherProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SwitcherProto_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_rec_2fgui_2fproto_2fSwitcher_2eproto() {
  protobuf_AddDesc_rec_2fgui_2fproto_2fSwitcher_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "rec/gui/proto/Switcher.proto");
  GOOGLE_CHECK(file != NULL);
  SwitcherProto_descriptor_ = file->message_type(0);
  static const int SwitcherProto_offsets_[1] = {
  };
  SwitcherProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SwitcherProto_descriptor_,
      SwitcherProto::default_instance_,
      SwitcherProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SwitcherProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SwitcherProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SwitcherProto));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_rec_2fgui_2fproto_2fSwitcher_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SwitcherProto_descriptor_, &SwitcherProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_rec_2fgui_2fproto_2fSwitcher_2eproto() {
  delete SwitcherProto::default_instance_;
  delete SwitcherProto_reflection_;
}

void protobuf_AddDesc_rec_2fgui_2fproto_2fSwitcher_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034rec/gui/proto/Switcher.proto\022\007rec.gui\""
    "\017\n\rSwitcherProto", 56);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "rec/gui/proto/Switcher.proto", &protobuf_RegisterTypes);
  SwitcherProto::default_instance_ = new SwitcherProto();
  SwitcherProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_rec_2fgui_2fproto_2fSwitcher_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_rec_2fgui_2fproto_2fSwitcher_2eproto {
  StaticDescriptorInitializer_rec_2fgui_2fproto_2fSwitcher_2eproto() {
    protobuf_AddDesc_rec_2fgui_2fproto_2fSwitcher_2eproto();
  }
} static_descriptor_initializer_rec_2fgui_2fproto_2fSwitcher_2eproto_;

// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

SwitcherProto::SwitcherProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SwitcherProto::InitAsDefaultInstance() {
}

SwitcherProto::SwitcherProto(const SwitcherProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SwitcherProto::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SwitcherProto::~SwitcherProto() {
  SharedDtor();
}

void SwitcherProto::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SwitcherProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SwitcherProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SwitcherProto_descriptor_;
}

const SwitcherProto& SwitcherProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rec_2fgui_2fproto_2fSwitcher_2eproto();
  return *default_instance_;
}

SwitcherProto* SwitcherProto::default_instance_ = NULL;

SwitcherProto* SwitcherProto::New() const {
  return new SwitcherProto;
}

void SwitcherProto::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SwitcherProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      return true;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
  return true;
#undef DO_
}

void SwitcherProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SwitcherProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SwitcherProto::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SwitcherProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SwitcherProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SwitcherProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SwitcherProto::MergeFrom(const SwitcherProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SwitcherProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SwitcherProto::CopyFrom(const SwitcherProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SwitcherProto::IsInitialized() const {

  return true;
}

void SwitcherProto::Swap(SwitcherProto* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SwitcherProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SwitcherProto_descriptor_;
  metadata.reflection = SwitcherProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace gui
}  // namespace rec

// @@protoc_insertion_point(global_scope)
