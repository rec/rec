# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/gui/Color.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/gui/Color.proto',
  package='rec.gui',
  serialized_pb='\n\x13rec/gui/Color.proto\x12\x07rec.gui\"\x86\x01\n\x05\x43olor\x12\x0e\n\x03rgb\x18\x01 \x01(\r:\x01\x30\x12\x12\n\x05\x61lpha\x18\x02 \x01(\r:\x03\x32\x35\x35\x12\x0e\n\x03red\x18\x03 \x01(\r:\x01\x30\x12\x10\n\x05green\x18\x04 \x01(\r:\x01\x30\x12\x0f\n\x04\x62lue\x18\x05 \x01(\r:\x01\x30\x12\x18\n\x04\x61rgb\x18\x06 \x01(\r:\n4278190080\x12\x0c\n\x04name\x18\x07 \x01(\t\"\'\n\x06\x43olors\x12\x1d\n\x05\x63olor\x18\x01 \x03(\x0b\x32\x0e.rec.gui.Color')




_COLOR = _descriptor.Descriptor(
  name='Color',
  full_name='rec.gui.Color',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='rgb', full_name='rec.gui.Color.rgb', index=0,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='alpha', full_name='rec.gui.Color.alpha', index=1,
      number=2, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=255,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='red', full_name='rec.gui.Color.red', index=2,
      number=3, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='green', full_name='rec.gui.Color.green', index=3,
      number=4, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='blue', full_name='rec.gui.Color.blue', index=4,
      number=5, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='argb', full_name='rec.gui.Color.argb', index=5,
      number=6, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=4278190080,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='name', full_name='rec.gui.Color.name', index=6,
      number=7, type=9, cpp_type=9, label=1,
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
  serialized_start=33,
  serialized_end=167,
)


_COLORS = _descriptor.Descriptor(
  name='Colors',
  full_name='rec.gui.Colors',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='color', full_name='rec.gui.Colors.color', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=169,
  serialized_end=208,
)

_COLORS.fields_by_name['color'].message_type = _COLOR
DESCRIPTOR.message_types_by_name['Color'] = _COLOR
DESCRIPTOR.message_types_by_name['Colors'] = _COLORS

class Color(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _COLOR

  # @@protoc_insertion_point(class_scope:rec.gui.Color)

class Colors(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _COLORS

  # @@protoc_insertion_point(class_scope:rec.gui.Colors)


# @@protoc_insertion_point(module_scope)
