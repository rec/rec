# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/gui/proto/Resizer.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/gui/proto/Resizer.proto',
  package='rec.gui',
  serialized_pb='\n\x1brec/gui/proto/Resizer.proto\x12\x07rec.gui\"!\n\x0cResizerProto\x12\x11\n\tmin_value\x18\x01 \x01(\t')




_RESIZERPROTO = _descriptor.Descriptor(
  name='ResizerProto',
  full_name='rec.gui.ResizerProto',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='min_value', full_name='rec.gui.ResizerProto.min_value', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
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
  serialized_start=40,
  serialized_end=73,
)

DESCRIPTOR.message_types_by_name['ResizerProto'] = _RESIZERPROTO

class ResizerProto(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _RESIZERPROTO

  # @@protoc_insertion_point(class_scope:rec.gui.ResizerProto)


# @@protoc_insertion_point(module_scope)
