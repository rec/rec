# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/gui/proto/Help.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import rec.gui.proto.Size_pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/gui/proto/Help.proto',
  package='rec.gui',
  serialized_pb='\n\x18rec/gui/proto/Help.proto\x12\x07rec.gui\x1a\x18rec/gui/proto/Size.proto\"R\n\tHelpProto\x12#\n\x0c\x63\x61ption_size\x18\x01 \x01(\x0b\x32\r.rec.gui.Size\x12 \n\tbody_size\x18\x02 \x01(\x0b\x32\r.rec.gui.Size')




_HELPPROTO = _descriptor.Descriptor(
  name='HelpProto',
  full_name='rec.gui.HelpProto',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='caption_size', full_name='rec.gui.HelpProto.caption_size', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='body_size', full_name='rec.gui.HelpProto.body_size', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
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
  serialized_start=63,
  serialized_end=145,
)

_HELPPROTO.fields_by_name['caption_size'].message_type = rec.gui.proto.Size_pb2._SIZE
_HELPPROTO.fields_by_name['body_size'].message_type = rec.gui.proto.Size_pb2._SIZE
DESCRIPTOR.message_types_by_name['HelpProto'] = _HELPPROTO

class HelpProto(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _HELPPROTO

  # @@protoc_insertion_point(class_scope:rec.gui.HelpProto)


# @@protoc_insertion_point(module_scope)
