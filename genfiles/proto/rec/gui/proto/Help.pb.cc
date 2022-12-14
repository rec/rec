// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/gui/proto/Help.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "rec/gui/proto/Help.pb.h"

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

const ::google::protobuf::Descriptor* HelpProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HelpProto_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_rec_2fgui_2fproto_2fHelp_2eproto() {
  protobuf_AddDesc_rec_2fgui_2fproto_2fHelp_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "rec/gui/proto/Help.proto");
  GOOGLE_CHECK(file != NULL);
  HelpProto_descriptor_ = file->message_type(0);
  static const int HelpProto_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelpProto, caption_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelpProto, body_size_),
  };
  HelpProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HelpProto_descriptor_,
      HelpProto::default_instance_,
      HelpProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelpProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelpProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HelpProto));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_rec_2fgui_2fproto_2fHelp_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HelpProto_descriptor_, &HelpProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_rec_2fgui_2fproto_2fHelp_2eproto() {
  delete HelpProto::default_instance_;
  delete HelpProto_reflection_;
}

void protobuf_AddDesc_rec_2fgui_2fproto_2fHelp_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::rec::gui::protobuf_AddDesc_rec_2fgui_2fproto_2fSize_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\030rec/gui/proto/Help.proto\022\007rec.gui\032\030rec"
    "/gui/proto/Size.proto\"R\n\tHelpProto\022#\n\014ca"
    "ption_size\030\001 \001(\0132\r.rec.gui.Size\022 \n\tbody_"
    "size\030\002 \001(\0132\r.rec.gui.Size", 145);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "rec/gui/proto/Help.proto", &protobuf_RegisterTypes);
  HelpProto::default_instance_ = new HelpProto();
  HelpProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_rec_2fgui_2fproto_2fHelp_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_rec_2fgui_2fproto_2fHelp_2eproto {
  StaticDescriptorInitializer_rec_2fgui_2fproto_2fHelp_2eproto() {
    protobuf_AddDesc_rec_2fgui_2fproto_2fHelp_2eproto();
  }
} static_descriptor_initializer_rec_2fgui_2fproto_2fHelp_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int HelpProto::kCaptionSizeFieldNumber;
const int HelpProto::kBodySizeFieldNumber;
#endif  // !_MSC_VER

HelpProto::HelpProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void HelpProto::InitAsDefaultInstance() {
  caption_size_ = const_cast< ::rec::gui::Size*>(&::rec::gui::Size::default_instance());
  body_size_ = const_cast< ::rec::gui::Size*>(&::rec::gui::Size::default_instance());
}

HelpProto::HelpProto(const HelpProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void HelpProto::SharedCtor() {
  _cached_size_ = 0;
  caption_size_ = NULL;
  body_size_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HelpProto::~HelpProto() {
  SharedDtor();
}

void HelpProto::SharedDtor() {
  if (this != default_instance_) {
    delete caption_size_;
    delete body_size_;
  }
}

void HelpProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HelpProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HelpProto_descriptor_;
}

const HelpProto& HelpProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rec_2fgui_2fproto_2fHelp_2eproto();
  return *default_instance_;
}

HelpProto* HelpProto::default_instance_ = NULL;

HelpProto* HelpProto::New() const {
  return new HelpProto;
}

void HelpProto::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_caption_size()) {
      if (caption_size_ != NULL) caption_size_->::rec::gui::Size::Clear();
    }
    if (has_body_size()) {
      if (body_size_ != NULL) body_size_->::rec::gui::Size::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HelpProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .rec.gui.Size caption_size = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_caption_size()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_body_size;
        break;
      }

      // optional .rec.gui.Size body_size = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_body_size:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_body_size()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void HelpProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional .rec.gui.Size caption_size = 1;
  if (has_caption_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->caption_size(), output);
  }

  // optional .rec.gui.Size body_size = 2;
  if (has_body_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->body_size(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* HelpProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional .rec.gui.Size caption_size = 1;
  if (has_caption_size()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->caption_size(), target);
  }

  // optional .rec.gui.Size body_size = 2;
  if (has_body_size()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->body_size(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int HelpProto::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .rec.gui.Size caption_size = 1;
    if (has_caption_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->caption_size());
    }

    // optional .rec.gui.Size body_size = 2;
    if (has_body_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->body_size());
    }

  }
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

void HelpProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HelpProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HelpProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HelpProto::MergeFrom(const HelpProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_caption_size()) {
      mutable_caption_size()->::rec::gui::Size::MergeFrom(from.caption_size());
    }
    if (from.has_body_size()) {
      mutable_body_size()->::rec::gui::Size::MergeFrom(from.body_size());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HelpProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HelpProto::CopyFrom(const HelpProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HelpProto::IsInitialized() const {

  return true;
}

void HelpProto::Swap(HelpProto* other) {
  if (other != this) {
    std::swap(caption_size_, other->caption_size_);
    std::swap(body_size_, other->body_size_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HelpProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HelpProto_descriptor_;
  metadata.reflection = HelpProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace gui
}  // namespace rec

// @@protoc_insertion_point(global_scope)
