# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/widget/waveform/Zoom.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/widget/waveform/Zoom.proto',
  package='rec.widget.waveform',
  serialized_pb='\n\x1erec/widget/waveform/Zoom.proto\x12\x13rec.widget.waveform\"=\n\x04Zoom\x12\r\n\x05\x62\x65gin\x18\x01 \x01(\x03\x12\x0b\n\x03\x65nd\x18\x02 \x01(\x03\x12\x19\n\x11zoom_to_selection\x18\x03 \x01(\x08')




_ZOOM = _descriptor.Descriptor(
  name='Zoom',
  full_name='rec.widget.waveform.Zoom',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='begin', full_name='rec.widget.waveform.Zoom.begin', index=0,
      number=1, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='end', full_name='rec.widget.waveform.Zoom.end', index=1,
      number=2, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='zoom_to_selection', full_name='rec.widget.waveform.Zoom.zoom_to_selection', index=2,
      number=3, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
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
  serialized_start=55,
  serialized_end=116,
)

DESCRIPTOR.message_types_by_name['Zoom'] = _ZOOM

class Zoom(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _ZOOM

  # @@protoc_insertion_point(class_scope:rec.widget.waveform.Zoom)


# @@protoc_insertion_point(module_scope)
