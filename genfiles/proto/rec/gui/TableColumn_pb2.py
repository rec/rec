# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: rec/gui/TableColumn.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import rec.data.proto.Address_pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='rec/gui/TableColumn.proto',
  package='rec.gui',
  serialized_pb='\n\x19rec/gui/TableColumn.proto\x12\x07rec.gui\x1a\x1crec/data/proto/Address.proto\"\xf4\x03\n\x0bTableColumn\x12\x0c\n\x04name\x18\x07 \x01(\t\x12\x11\n\x05width\x18\x01 \x01(\r:\x02\x36\x30\x12\x19\n\rminimum_width\x18\x02 \x01(\r:\x02\x36\x30\x12\x19\n\rmaximum_width\x18\x03 \x01(\x05:\x02-1\x12@\n\x0eproperty_flags\x18\x04 \x01(\x0e\x32\x1f.rec.gui.TableColumn.Properties:\x07\x44\x45\x46\x41ULT\x12\'\n\x07\x61\x64\x64ress\x18\x05 \x01(\x0b\x32\x16.rec.data.AddressProto\x12\'\n\x04type\x18\x06 \x01(\x0e\x32\x19.rec.gui.TableColumn.Type\"\xc3\x01\n\nProperties\x12\x0b\n\x07VISIBLE\x10\x01\x12\r\n\tRESIZABLE\x10\x02\x12\r\n\tDRAGGABLE\x10\x04\x12\x1a\n\x16\x41PPEARS_ON_COLUMN_MENU\x10\x08\x12\x0c\n\x08SORTABLE\x10\x10\x12\x13\n\x0fSORTED_FORWARDS\x10 \x12\x14\n\x10SORTED_BACKWARDS\x10@\x12\r\n\x08\x45\x44ITABLE\x10\x80\x01\x12\x0c\n\x07\x44\x45\x46\x41ULT\x10\x8f\x01\x12\x18\n\x14\x44\x45\x46\x41ULT_NOT_EDITABLE\x10\x0f\"4\n\x04Type\x12\n\n\x06STRING\x10\x01\x12\x08\n\x04TIME\x10\x02\x12\n\n\x06UINT32\x10\x03\x12\n\n\x06\x44OUBLE\x10\x04\"7\n\x0fTableColumnList\x12$\n\x06\x63olumn\x18\x01 \x03(\x0b\x32\x14.rec.gui.TableColumn')



_TABLECOLUMN_PROPERTIES = _descriptor.EnumDescriptor(
  name='Properties',
  full_name='rec.gui.TableColumn.Properties',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='VISIBLE', index=0, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='RESIZABLE', index=1, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DRAGGABLE', index=2, number=4,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='APPEARS_ON_COLUMN_MENU', index=3, number=8,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='SORTABLE', index=4, number=16,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='SORTED_FORWARDS', index=5, number=32,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='SORTED_BACKWARDS', index=6, number=64,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='EDITABLE', index=7, number=128,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEFAULT', index=8, number=143,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DEFAULT_NOT_EDITABLE', index=9, number=15,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=320,
  serialized_end=515,
)

_TABLECOLUMN_TYPE = _descriptor.EnumDescriptor(
  name='Type',
  full_name='rec.gui.TableColumn.Type',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='STRING', index=0, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='TIME', index=1, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='UINT32', index=2, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DOUBLE', index=3, number=4,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=517,
  serialized_end=569,
)


_TABLECOLUMN = _descriptor.Descriptor(
  name='TableColumn',
  full_name='rec.gui.TableColumn',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='rec.gui.TableColumn.name', index=0,
      number=7, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='width', full_name='rec.gui.TableColumn.width', index=1,
      number=1, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=60,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='minimum_width', full_name='rec.gui.TableColumn.minimum_width', index=2,
      number=2, type=13, cpp_type=3, label=1,
      has_default_value=True, default_value=60,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='maximum_width', full_name='rec.gui.TableColumn.maximum_width', index=3,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=True, default_value=-1,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='property_flags', full_name='rec.gui.TableColumn.property_flags', index=4,
      number=4, type=14, cpp_type=8, label=1,
      has_default_value=True, default_value=143,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='address', full_name='rec.gui.TableColumn.address', index=5,
      number=5, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='type', full_name='rec.gui.TableColumn.type', index=6,
      number=6, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=1,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _TABLECOLUMN_PROPERTIES,
    _TABLECOLUMN_TYPE,
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=69,
  serialized_end=569,
)


_TABLECOLUMNLIST = _descriptor.Descriptor(
  name='TableColumnList',
  full_name='rec.gui.TableColumnList',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='column', full_name='rec.gui.TableColumnList.column', index=0,
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
  serialized_start=571,
  serialized_end=626,
)

_TABLECOLUMN.fields_by_name['property_flags'].enum_type = _TABLECOLUMN_PROPERTIES
_TABLECOLUMN.fields_by_name['address'].message_type = rec.data.proto.Address_pb2._ADDRESSPROTO
_TABLECOLUMN.fields_by_name['type'].enum_type = _TABLECOLUMN_TYPE
_TABLECOLUMN_PROPERTIES.containing_type = _TABLECOLUMN;
_TABLECOLUMN_TYPE.containing_type = _TABLECOLUMN;
_TABLECOLUMNLIST.fields_by_name['column'].message_type = _TABLECOLUMN
DESCRIPTOR.message_types_by_name['TableColumn'] = _TABLECOLUMN
DESCRIPTOR.message_types_by_name['TableColumnList'] = _TABLECOLUMNLIST

class TableColumn(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _TABLECOLUMN

  # @@protoc_insertion_point(class_scope:rec.gui.TableColumn)

class TableColumnList(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _TABLECOLUMNLIST

  # @@protoc_insertion_point(class_scope:rec.gui.TableColumnList)


# @@protoc_insertion_point(module_scope)
