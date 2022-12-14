# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/util/LoopPoint.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/util/LoopPoint.proto',
  package='rec.util',
  serialized_pb='\n\x18rec/util/LoopPoint.proto\x12\x08rec.util\"H\n\tLoopPoint\x12\x0c\n\x04time\x18\x01 \x01(\x03\x12\x10\n\x08selected\x18\x02 \x01(\x08\x12\x0c\n\x04name\x18\x03 \x01(\t\x12\r\n\x05notes\x18\x04 \x01(\t\"]\n\rLoopPointList\x12\'\n\nloop_point\x18\x01 \x03(\x0b\x32\x13.rec.util.LoopPoint\x12\x0e\n\x06length\x18\x02 \x01(\x03\x12\x13\n\x0bsample_rate\x18\x03 \x01(\x01')




_LOOPPOINT = _descriptor.Descriptor(
  name='LoopPoint',
  full_name='rec.util.LoopPoint',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='time', full_name='rec.util.LoopPoint.time', index=0,
      number=1, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='selected', full_name='rec.util.LoopPoint.selected', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='name', full_name='rec.util.LoopPoint.name', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='notes', full_name='rec.util.LoopPoint.notes', index=3,
      number=4, type=9, cpp_type=9, label=1,
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
  serialized_start=38,
  serialized_end=110,
)


_LOOPPOINTLIST = _descriptor.Descriptor(
  name='LoopPointList',
  full_name='rec.util.LoopPointList',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='loop_point', full_name='rec.util.LoopPointList.loop_point', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='length', full_name='rec.util.LoopPointList.length', index=1,
      number=2, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='sample_rate', full_name='rec.util.LoopPointList.sample_rate', index=2,
      number=3, type=1, cpp_type=5, label=1,
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
  serialized_start=112,
  serialized_end=205,
)

_LOOPPOINTLIST.fields_by_name['loop_point'].message_type = _LOOPPOINT
DESCRIPTOR.message_types_by_name['LoopPoint'] = _LOOPPOINT
DESCRIPTOR.message_types_by_name['LoopPointList'] = _LOOPPOINTLIST

class LoopPoint(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LOOPPOINT

  # @@protoc_insertion_point(class_scope:rec.util.LoopPoint)

class LoopPointList(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LOOPPOINTLIST

  # @@protoc_insertion_point(class_scope:rec.util.LoopPointList)


# @@protoc_insertion_point(module_scope)
