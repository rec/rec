# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/data/proto/Value.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/data/proto/Value.proto',
  package='rec.data',
  serialized_pb='\n\x1arec/data/proto/Value.proto\x12\x08rec.data\"\xce\x02\n\nValueProto\x12\x10\n\x08\x64ouble_f\x18\x01 \x01(\x01\x12\x0f\n\x07\x66loat_f\x18\x02 \x01(\x02\x12\x0f\n\x07int64_f\x18\x03 \x01(\x03\x12\x10\n\x08uint64_f\x18\x04 \x01(\x04\x12\x0f\n\x07int32_f\x18\x05 \x01(\x05\x12\x11\n\tfixed64_f\x18\x06 \x01(\x06\x12\x11\n\tfixed32_f\x18\x07 \x01(\x07\x12\x0e\n\x06\x62ool_f\x18\x08 \x01(\x08\x12\x10\n\x08string_f\x18\t \x01(\t\x12\x0f\n\x07group_f\x18\n \x01(\x0c\x12\x11\n\tmessage_f\x18\x0b \x01(\x0c\x12\x0f\n\x07\x62ytes_f\x18\x0c \x01(\x0c\x12\x10\n\x08uint32_f\x18\r \x01(\r\x12\x0e\n\x06\x65num_f\x18\x0e \x01(\x05\x12\x12\n\nsfixed32_f\x18\x0f \x01(\x0f\x12\x12\n\nsfixed64_f\x18\x10 \x01(\x10\x12\x10\n\x08sint32_f\x18\x11 \x01(\x11\x12\x10\n\x08sint64_f\x18\x12 \x01(\x12')




_VALUEPROTO = _descriptor.Descriptor(
  name='ValueProto',
  full_name='rec.data.ValueProto',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='double_f', full_name='rec.data.ValueProto.double_f', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='float_f', full_name='rec.data.ValueProto.float_f', index=1,
      number=2, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='int64_f', full_name='rec.data.ValueProto.int64_f', index=2,
      number=3, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='uint64_f', full_name='rec.data.ValueProto.uint64_f', index=3,
      number=4, type=4, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='int32_f', full_name='rec.data.ValueProto.int32_f', index=4,
      number=5, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='fixed64_f', full_name='rec.data.ValueProto.fixed64_f', index=5,
      number=6, type=6, cpp_type=4, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='fixed32_f', full_name='rec.data.ValueProto.fixed32_f', index=6,
      number=7, type=7, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='bool_f', full_name='rec.data.ValueProto.bool_f', index=7,
      number=8, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='string_f', full_name='rec.data.ValueProto.string_f', index=8,
      number=9, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='group_f', full_name='rec.data.ValueProto.group_f', index=9,
      number=10, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value="",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='message_f', full_name='rec.data.ValueProto.message_f', index=10,
      number=11, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value="",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='bytes_f', full_name='rec.data.ValueProto.bytes_f', index=11,
      number=12, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value="",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='uint32_f', full_name='rec.data.ValueProto.uint32_f', index=12,
      number=13, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='enum_f', full_name='rec.data.ValueProto.enum_f', index=13,
      number=14, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sfixed32_f', full_name='rec.data.ValueProto.sfixed32_f', index=14,
      number=15, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sfixed64_f', full_name='rec.data.ValueProto.sfixed64_f', index=15,
      number=16, type=16, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sint32_f', full_name='rec.data.ValueProto.sint32_f', index=16,
      number=17, type=17, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sint64_f', full_name='rec.data.ValueProto.sint64_f', index=17,
      number=18, type=18, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=41,
  serialized_end=375,
)

DESCRIPTOR.message_types_by_name['ValueProto'] = _VALUEPROTO

class ValueProto(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _VALUEPROTO

  # @@protoc_insertion_point(class_scope:rec.data.ValueProto)


# @@protoc_insertion_point(module_scope)
