# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/gui/menu/RecentFiles.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import rec.music.Metadata_pb2
import rec.util.file.VirtualFile_pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/gui/menu/RecentFiles.proto',
  package='rec.gui',
  serialized_pb='\n\x1erec/gui/menu/RecentFiles.proto\x12\x07rec.gui\x1a\x18rec/music/Metadata.proto\x1a\x1frec/util/file/VirtualFile.proto\"\x89\x01\n\nRecentFile\x12\x11\n\ttimestamp\x18\x01 \x01(\x03\x12(\n\x04\x66ile\x18\x02 \x01(\x0b\x32\x1a.rec.util.file.VirtualFile\x12%\n\x08metadata\x18\x03 \x01(\x0b\x32\x13.rec.music.Metadata\x12\x17\n\x0fmetadata_string\x18\x04 \x01(\t\"i\n\x0bRecentFiles\x12!\n\x04\x66ile\x18\x03 \x03(\x0b\x32\x13.rec.gui.RecentFile\x12\x15\n\tmax_files\x18\x04 \x01(\x05:\x02\x31\x36\x12 \n\x12reload_most_recent\x18\x05 \x01(\x08:\x04true')




_RECENTFILE = _descriptor.Descriptor(
  name='RecentFile',
  full_name='rec.gui.RecentFile',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='timestamp', full_name='rec.gui.RecentFile.timestamp', index=0,
      number=1, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='file', full_name='rec.gui.RecentFile.file', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='metadata', full_name='rec.gui.RecentFile.metadata', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='metadata_string', full_name='rec.gui.RecentFile.metadata_string', index=3,
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
  serialized_start=103,
  serialized_end=240,
)


_RECENTFILES = _descriptor.Descriptor(
  name='RecentFiles',
  full_name='rec.gui.RecentFiles',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='file', full_name='rec.gui.RecentFiles.file', index=0,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='max_files', full_name='rec.gui.RecentFiles.max_files', index=1,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=16,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='reload_most_recent', full_name='rec.gui.RecentFiles.reload_most_recent', index=2,
      number=5, type=8, cpp_type=7, label=1,
      has_default_value=True, default_value=True,
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
  serialized_start=242,
  serialized_end=347,
)

_RECENTFILE.fields_by_name['file'].message_type = rec.util.file.VirtualFile_pb2._VIRTUALFILE
_RECENTFILE.fields_by_name['metadata'].message_type = rec.music.Metadata_pb2._METADATA
_RECENTFILES.fields_by_name['file'].message_type = _RECENTFILE
DESCRIPTOR.message_types_by_name['RecentFile'] = _RECENTFILE
DESCRIPTOR.message_types_by_name['RecentFiles'] = _RECENTFILES

class RecentFile(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _RECENTFILE

  # @@protoc_insertion_point(class_scope:rec.gui.RecentFile)

class RecentFiles(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _RECENTFILES

  # @@protoc_insertion_point(class_scope:rec.gui.RecentFiles)


# @@protoc_insertion_point(module_scope)
