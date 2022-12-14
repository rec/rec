#pragma once

#include <string>
#include <google/protobuf/message.h>

#include "rec/base/base.h"

// A set of overloaded functions to copy "anything" to "anything else".
//
// Example: read a protocol message from a file.
//   MyProto proto;
//   if (!data::copy(File(myFileName), &proto)) {
//     // Handle error.
//   }
//
// Specific implementations exist for all pairs of:
//   std::string
//   Juce::String
//   Juce::File
//   google::protobuf::Message
//
// In the case of protobufs, we use human-readable form for the serialization
// and deserialization.

namespace rec {
namespace copy {

enum Style {COMPRESSED, READABLE, DEFAULT_STYLE = READABLE};

bool copy(const File& from, File* to, Style r = DEFAULT_STYLE);
bool copy(const File& from, const File& to, Style r = DEFAULT_STYLE);
bool copy(const File& from, MemoryBlock* to, Style r = DEFAULT_STYLE);
bool copy(const File& from, Message* to, Style r = DEFAULT_STYLE);
bool copy(const File& from, String* to, Style r = DEFAULT_STYLE);
bool copy(const File& from, string* to, Style r = DEFAULT_STYLE);

bool copy(const Message& from, File* to, Style r = DEFAULT_STYLE);
bool copy(const Message& from, const File& to, Style r = DEFAULT_STYLE);
bool copy(const Message& from, MemoryBlock* to, Style r = DEFAULT_STYLE);
bool copy(const Message& from, Message* to, Style r = DEFAULT_STYLE);
bool copy(const Message& from, String* to, Style r = DEFAULT_STYLE);
bool copy(const Message& from, string* to, Style r = DEFAULT_STYLE);

bool copy(const MemoryBlock& from, File* to, Style r = DEFAULT_STYLE);
bool copy(const MemoryBlock& from, const File& to, Style r = DEFAULT_STYLE);
bool copy(const MemoryBlock& from, MemoryBlock* to, Style r = DEFAULT_STYLE);
bool copy(const MemoryBlock& from, Message* to, Style r = DEFAULT_STYLE);
bool copy(const MemoryBlock& from, String* to, Style r = DEFAULT_STYLE);
bool copy(const MemoryBlock& from, string* to, Style r = DEFAULT_STYLE);

bool copy(const String& from, File* to, Style r = DEFAULT_STYLE);
bool copy(const String& from, const File& to, Style r = DEFAULT_STYLE);
bool copy(const String& from, MemoryBlock* to, Style r = DEFAULT_STYLE);
bool copy(const String& from, Message* to, Style r = DEFAULT_STYLE);
bool copy(const String& from, String* to, Style r = DEFAULT_STYLE);
bool copy(const String& from, string* to, Style r = DEFAULT_STYLE);

bool copy(const string& from, File* to, Style r = DEFAULT_STYLE);
bool copy(const string& from, const File& to, Style r = DEFAULT_STYLE);
bool copy(const string& from, MemoryBlock* to, Style r = DEFAULT_STYLE);
bool copy(const string& from, Message* to, Style r = DEFAULT_STYLE);
bool copy(const string& from, String* to, Style r = DEFAULT_STYLE);
bool copy(const string& from, string* to, Style r = DEFAULT_STYLE);

// Unfortunately, we can't replace these by one template declaration, because
// templates won't downcast for you (for example, to Message if you're trying
// to copy a protocol buffer).

bool merge(const string& from, Message* to, Style r = DEFAULT_STYLE);

}  // namespace copy
}  // namespace rec
