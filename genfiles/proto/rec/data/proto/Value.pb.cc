// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: rec/data/proto/Value.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "rec/data/proto/Value.pb.h"

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
namespace data {

namespace {

const ::google::protobuf::Descriptor* ValueProto_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ValueProto_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_rec_2fdata_2fproto_2fValue_2eproto() {
  protobuf_AddDesc_rec_2fdata_2fproto_2fValue_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "rec/data/proto/Value.proto");
  GOOGLE_CHECK(file != NULL);
  ValueProto_descriptor_ = file->message_type(0);
  static const int ValueProto_offsets_[18] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, double_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, float_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, int64_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, uint64_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, int32_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, fixed64_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, fixed32_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, bool_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, string_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, group_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, message_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, bytes_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, uint32_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, enum_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, sfixed32_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, sfixed64_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, sint32_f_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, sint64_f_),
  };
  ValueProto_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ValueProto_descriptor_,
      ValueProto::default_instance_,
      ValueProto_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ValueProto, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ValueProto));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_rec_2fdata_2fproto_2fValue_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ValueProto_descriptor_, &ValueProto::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_rec_2fdata_2fproto_2fValue_2eproto() {
  delete ValueProto::default_instance_;
  delete ValueProto_reflection_;
}

void protobuf_AddDesc_rec_2fdata_2fproto_2fValue_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\032rec/data/proto/Value.proto\022\010rec.data\"\316"
    "\002\n\nValueProto\022\020\n\010double_f\030\001 \001(\001\022\017\n\007float"
    "_f\030\002 \001(\002\022\017\n\007int64_f\030\003 \001(\003\022\020\n\010uint64_f\030\004 "
    "\001(\004\022\017\n\007int32_f\030\005 \001(\005\022\021\n\tfixed64_f\030\006 \001(\006\022"
    "\021\n\tfixed32_f\030\007 \001(\007\022\016\n\006bool_f\030\010 \001(\010\022\020\n\010st"
    "ring_f\030\t \001(\t\022\017\n\007group_f\030\n \001(\014\022\021\n\tmessage"
    "_f\030\013 \001(\014\022\017\n\007bytes_f\030\014 \001(\014\022\020\n\010uint32_f\030\r "
    "\001(\r\022\016\n\006enum_f\030\016 \001(\005\022\022\n\nsfixed32_f\030\017 \001(\017\022"
    "\022\n\nsfixed64_f\030\020 \001(\020\022\020\n\010sint32_f\030\021 \001(\021\022\020\n"
    "\010sint64_f\030\022 \001(\022", 375);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "rec/data/proto/Value.proto", &protobuf_RegisterTypes);
  ValueProto::default_instance_ = new ValueProto();
  ValueProto::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_rec_2fdata_2fproto_2fValue_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_rec_2fdata_2fproto_2fValue_2eproto {
  StaticDescriptorInitializer_rec_2fdata_2fproto_2fValue_2eproto() {
    protobuf_AddDesc_rec_2fdata_2fproto_2fValue_2eproto();
  }
} static_descriptor_initializer_rec_2fdata_2fproto_2fValue_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ValueProto::kDoubleFFieldNumber;
const int ValueProto::kFloatFFieldNumber;
const int ValueProto::kInt64FFieldNumber;
const int ValueProto::kUint64FFieldNumber;
const int ValueProto::kInt32FFieldNumber;
const int ValueProto::kFixed64FFieldNumber;
const int ValueProto::kFixed32FFieldNumber;
const int ValueProto::kBoolFFieldNumber;
const int ValueProto::kStringFFieldNumber;
const int ValueProto::kGroupFFieldNumber;
const int ValueProto::kMessageFFieldNumber;
const int ValueProto::kBytesFFieldNumber;
const int ValueProto::kUint32FFieldNumber;
const int ValueProto::kEnumFFieldNumber;
const int ValueProto::kSfixed32FFieldNumber;
const int ValueProto::kSfixed64FFieldNumber;
const int ValueProto::kSint32FFieldNumber;
const int ValueProto::kSint64FFieldNumber;
#endif  // !_MSC_VER

ValueProto::ValueProto()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ValueProto::InitAsDefaultInstance() {
}

ValueProto::ValueProto(const ValueProto& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ValueProto::SharedCtor() {
  _cached_size_ = 0;
  double_f_ = 0;
  float_f_ = 0;
  int64_f_ = GOOGLE_LONGLONG(0);
  uint64_f_ = GOOGLE_ULONGLONG(0);
  int32_f_ = 0;
  fixed64_f_ = GOOGLE_ULONGLONG(0);
  fixed32_f_ = 0u;
  bool_f_ = false;
  string_f_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  group_f_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  message_f_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  bytes_f_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  uint32_f_ = 0u;
  enum_f_ = 0;
  sfixed32_f_ = 0;
  sfixed64_f_ = GOOGLE_LONGLONG(0);
  sint32_f_ = 0;
  sint64_f_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ValueProto::~ValueProto() {
  SharedDtor();
}

void ValueProto::SharedDtor() {
  if (string_f_ != &::google::protobuf::internal::kEmptyString) {
    delete string_f_;
  }
  if (group_f_ != &::google::protobuf::internal::kEmptyString) {
    delete group_f_;
  }
  if (message_f_ != &::google::protobuf::internal::kEmptyString) {
    delete message_f_;
  }
  if (bytes_f_ != &::google::protobuf::internal::kEmptyString) {
    delete bytes_f_;
  }
  if (this != default_instance_) {
  }
}

void ValueProto::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ValueProto::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ValueProto_descriptor_;
}

const ValueProto& ValueProto::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_rec_2fdata_2fproto_2fValue_2eproto();
  return *default_instance_;
}

ValueProto* ValueProto::default_instance_ = NULL;

ValueProto* ValueProto::New() const {
  return new ValueProto;
}

void ValueProto::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    double_f_ = 0;
    float_f_ = 0;
    int64_f_ = GOOGLE_LONGLONG(0);
    uint64_f_ = GOOGLE_ULONGLONG(0);
    int32_f_ = 0;
    fixed64_f_ = GOOGLE_ULONGLONG(0);
    fixed32_f_ = 0u;
    bool_f_ = false;
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (has_string_f()) {
      if (string_f_ != &::google::protobuf::internal::kEmptyString) {
        string_f_->clear();
      }
    }
    if (has_group_f()) {
      if (group_f_ != &::google::protobuf::internal::kEmptyString) {
        group_f_->clear();
      }
    }
    if (has_message_f()) {
      if (message_f_ != &::google::protobuf::internal::kEmptyString) {
        message_f_->clear();
      }
    }
    if (has_bytes_f()) {
      if (bytes_f_ != &::google::protobuf::internal::kEmptyString) {
        bytes_f_->clear();
      }
    }
    uint32_f_ = 0u;
    enum_f_ = 0;
    sfixed32_f_ = 0;
    sfixed64_f_ = GOOGLE_LONGLONG(0);
  }
  if (_has_bits_[16 / 32] & (0xffu << (16 % 32))) {
    sint32_f_ = 0;
    sint64_f_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ValueProto::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double double_f = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &double_f_)));
          set_has_double_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(21)) goto parse_float_f;
        break;
      }

      // optional float float_f = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_float_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &float_f_)));
          set_has_float_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_int64_f;
        break;
      }

      // optional int64 int64_f = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_int64_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &int64_f_)));
          set_has_int64_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_uint64_f;
        break;
      }

      // optional uint64 uint64_f = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_uint64_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &uint64_f_)));
          set_has_uint64_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_int32_f;
        break;
      }

      // optional int32 int32_f = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_int32_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &int32_f_)));
          set_has_int32_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(49)) goto parse_fixed64_f;
        break;
      }

      // optional fixed64 fixed64_f = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_fixed64_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &fixed64_f_)));
          set_has_fixed64_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(61)) goto parse_fixed32_f;
        break;
      }

      // optional fixed32 fixed32_f = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_fixed32_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &fixed32_f_)));
          set_has_fixed32_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_bool_f;
        break;
      }

      // optional bool bool_f = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bool_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &bool_f_)));
          set_has_bool_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(74)) goto parse_string_f;
        break;
      }

      // optional string string_f = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_string_f:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_string_f()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->string_f().data(), this->string_f().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(82)) goto parse_group_f;
        break;
      }

      // optional bytes group_f = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_group_f:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_group_f()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(90)) goto parse_message_f;
        break;
      }

      // optional bytes message_f = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_message_f:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_message_f()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(98)) goto parse_bytes_f;
        break;
      }

      // optional bytes bytes_f = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_bytes_f:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_bytes_f()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(104)) goto parse_uint32_f;
        break;
      }

      // optional uint32 uint32_f = 13;
      case 13: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_uint32_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &uint32_f_)));
          set_has_uint32_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(112)) goto parse_enum_f;
        break;
      }

      // optional int32 enum_f = 14;
      case 14: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_enum_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &enum_f_)));
          set_has_enum_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(125)) goto parse_sfixed32_f;
        break;
      }

      // optional sfixed32 sfixed32_f = 15;
      case 15: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED32) {
         parse_sfixed32_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED32>(
                 input, &sfixed32_f_)));
          set_has_sfixed32_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(129)) goto parse_sfixed64_f;
        break;
      }

      // optional sfixed64 sfixed64_f = 16;
      case 16: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_sfixed64_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SFIXED64>(
                 input, &sfixed64_f_)));
          set_has_sfixed64_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(136)) goto parse_sint32_f;
        break;
      }

      // optional sint32 sint32_f = 17;
      case 17: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_sint32_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &sint32_f_)));
          set_has_sint32_f();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(144)) goto parse_sint64_f;
        break;
      }

      // optional sint64 sint64_f = 18;
      case 18: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_sint64_f:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_SINT64>(
                 input, &sint64_f_)));
          set_has_sint64_f();
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

void ValueProto::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional double double_f = 1;
  if (has_double_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->double_f(), output);
  }

  // optional float float_f = 2;
  if (has_float_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->float_f(), output);
  }

  // optional int64 int64_f = 3;
  if (has_int64_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->int64_f(), output);
  }

  // optional uint64 uint64_f = 4;
  if (has_uint64_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(4, this->uint64_f(), output);
  }

  // optional int32 int32_f = 5;
  if (has_int32_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->int32_f(), output);
  }

  // optional fixed64 fixed64_f = 6;
  if (has_fixed64_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(6, this->fixed64_f(), output);
  }

  // optional fixed32 fixed32_f = 7;
  if (has_fixed32_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(7, this->fixed32_f(), output);
  }

  // optional bool bool_f = 8;
  if (has_bool_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->bool_f(), output);
  }

  // optional string string_f = 9;
  if (has_string_f()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->string_f().data(), this->string_f().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      9, this->string_f(), output);
  }

  // optional bytes group_f = 10;
  if (has_group_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      10, this->group_f(), output);
  }

  // optional bytes message_f = 11;
  if (has_message_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      11, this->message_f(), output);
  }

  // optional bytes bytes_f = 12;
  if (has_bytes_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      12, this->bytes_f(), output);
  }

  // optional uint32 uint32_f = 13;
  if (has_uint32_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(13, this->uint32_f(), output);
  }

  // optional int32 enum_f = 14;
  if (has_enum_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(14, this->enum_f(), output);
  }

  // optional sfixed32 sfixed32_f = 15;
  if (has_sfixed32_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed32(15, this->sfixed32_f(), output);
  }

  // optional sfixed64 sfixed64_f = 16;
  if (has_sfixed64_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteSFixed64(16, this->sfixed64_f(), output);
  }

  // optional sint32 sint32_f = 17;
  if (has_sint32_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(17, this->sint32_f(), output);
  }

  // optional sint64 sint64_f = 18;
  if (has_sint64_f()) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt64(18, this->sint64_f(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ValueProto::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional double double_f = 1;
  if (has_double_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->double_f(), target);
  }

  // optional float float_f = 2;
  if (has_float_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->float_f(), target);
  }

  // optional int64 int64_f = 3;
  if (has_int64_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->int64_f(), target);
  }

  // optional uint64 uint64_f = 4;
  if (has_uint64_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(4, this->uint64_f(), target);
  }

  // optional int32 int32_f = 5;
  if (has_int32_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->int32_f(), target);
  }

  // optional fixed64 fixed64_f = 6;
  if (has_fixed64_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(6, this->fixed64_f(), target);
  }

  // optional fixed32 fixed32_f = 7;
  if (has_fixed32_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(7, this->fixed32_f(), target);
  }

  // optional bool bool_f = 8;
  if (has_bool_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->bool_f(), target);
  }

  // optional string string_f = 9;
  if (has_string_f()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->string_f().data(), this->string_f().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        9, this->string_f(), target);
  }

  // optional bytes group_f = 10;
  if (has_group_f()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        10, this->group_f(), target);
  }

  // optional bytes message_f = 11;
  if (has_message_f()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        11, this->message_f(), target);
  }

  // optional bytes bytes_f = 12;
  if (has_bytes_f()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        12, this->bytes_f(), target);
  }

  // optional uint32 uint32_f = 13;
  if (has_uint32_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(13, this->uint32_f(), target);
  }

  // optional int32 enum_f = 14;
  if (has_enum_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(14, this->enum_f(), target);
  }

  // optional sfixed32 sfixed32_f = 15;
  if (has_sfixed32_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSFixed32ToArray(15, this->sfixed32_f(), target);
  }

  // optional sfixed64 sfixed64_f = 16;
  if (has_sfixed64_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSFixed64ToArray(16, this->sfixed64_f(), target);
  }

  // optional sint32 sint32_f = 17;
  if (has_sint32_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(17, this->sint32_f(), target);
  }

  // optional sint64 sint64_f = 18;
  if (has_sint64_f()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt64ToArray(18, this->sint64_f(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ValueProto::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional double double_f = 1;
    if (has_double_f()) {
      total_size += 1 + 8;
    }

    // optional float float_f = 2;
    if (has_float_f()) {
      total_size += 1 + 4;
    }

    // optional int64 int64_f = 3;
    if (has_int64_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->int64_f());
    }

    // optional uint64 uint64_f = 4;
    if (has_uint64_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->uint64_f());
    }

    // optional int32 int32_f = 5;
    if (has_int32_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->int32_f());
    }

    // optional fixed64 fixed64_f = 6;
    if (has_fixed64_f()) {
      total_size += 1 + 8;
    }

    // optional fixed32 fixed32_f = 7;
    if (has_fixed32_f()) {
      total_size += 1 + 4;
    }

    // optional bool bool_f = 8;
    if (has_bool_f()) {
      total_size += 1 + 1;
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional string string_f = 9;
    if (has_string_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->string_f());
    }

    // optional bytes group_f = 10;
    if (has_group_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->group_f());
    }

    // optional bytes message_f = 11;
    if (has_message_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->message_f());
    }

    // optional bytes bytes_f = 12;
    if (has_bytes_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->bytes_f());
    }

    // optional uint32 uint32_f = 13;
    if (has_uint32_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->uint32_f());
    }

    // optional int32 enum_f = 14;
    if (has_enum_f()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->enum_f());
    }

    // optional sfixed32 sfixed32_f = 15;
    if (has_sfixed32_f()) {
      total_size += 1 + 4;
    }

    // optional sfixed64 sfixed64_f = 16;
    if (has_sfixed64_f()) {
      total_size += 2 + 8;
    }

  }
  if (_has_bits_[16 / 32] & (0xffu << (16 % 32))) {
    // optional sint32 sint32_f = 17;
    if (has_sint32_f()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::SInt32Size(
          this->sint32_f());
    }

    // optional sint64 sint64_f = 18;
    if (has_sint64_f()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::SInt64Size(
          this->sint64_f());
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

void ValueProto::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ValueProto* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ValueProto*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ValueProto::MergeFrom(const ValueProto& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_double_f()) {
      set_double_f(from.double_f());
    }
    if (from.has_float_f()) {
      set_float_f(from.float_f());
    }
    if (from.has_int64_f()) {
      set_int64_f(from.int64_f());
    }
    if (from.has_uint64_f()) {
      set_uint64_f(from.uint64_f());
    }
    if (from.has_int32_f()) {
      set_int32_f(from.int32_f());
    }
    if (from.has_fixed64_f()) {
      set_fixed64_f(from.fixed64_f());
    }
    if (from.has_fixed32_f()) {
      set_fixed32_f(from.fixed32_f());
    }
    if (from.has_bool_f()) {
      set_bool_f(from.bool_f());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_string_f()) {
      set_string_f(from.string_f());
    }
    if (from.has_group_f()) {
      set_group_f(from.group_f());
    }
    if (from.has_message_f()) {
      set_message_f(from.message_f());
    }
    if (from.has_bytes_f()) {
      set_bytes_f(from.bytes_f());
    }
    if (from.has_uint32_f()) {
      set_uint32_f(from.uint32_f());
    }
    if (from.has_enum_f()) {
      set_enum_f(from.enum_f());
    }
    if (from.has_sfixed32_f()) {
      set_sfixed32_f(from.sfixed32_f());
    }
    if (from.has_sfixed64_f()) {
      set_sfixed64_f(from.sfixed64_f());
    }
  }
  if (from._has_bits_[16 / 32] & (0xffu << (16 % 32))) {
    if (from.has_sint32_f()) {
      set_sint32_f(from.sint32_f());
    }
    if (from.has_sint64_f()) {
      set_sint64_f(from.sint64_f());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ValueProto::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ValueProto::CopyFrom(const ValueProto& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ValueProto::IsInitialized() const {

  return true;
}

void ValueProto::Swap(ValueProto* other) {
  if (other != this) {
    std::swap(double_f_, other->double_f_);
    std::swap(float_f_, other->float_f_);
    std::swap(int64_f_, other->int64_f_);
    std::swap(uint64_f_, other->uint64_f_);
    std::swap(int32_f_, other->int32_f_);
    std::swap(fixed64_f_, other->fixed64_f_);
    std::swap(fixed32_f_, other->fixed32_f_);
    std::swap(bool_f_, other->bool_f_);
    std::swap(string_f_, other->string_f_);
    std::swap(group_f_, other->group_f_);
    std::swap(message_f_, other->message_f_);
    std::swap(bytes_f_, other->bytes_f_);
    std::swap(uint32_f_, other->uint32_f_);
    std::swap(enum_f_, other->enum_f_);
    std::swap(sfixed32_f_, other->sfixed32_f_);
    std::swap(sfixed64_f_, other->sfixed64_f_);
    std::swap(sint32_f_, other->sint32_f_);
    std::swap(sint64_f_, other->sint64_f_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ValueProto::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ValueProto_descriptor_;
  metadata.reflection = ValueProto_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace data
}  // namespace rec

// @@protoc_insertion_point(global_scope)
