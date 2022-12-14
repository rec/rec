#pragma once

#include "rec/util/cd/Album.h"
#include "rec/util/cd/Socket.h"
#include "rec/music/Metadata.h"

namespace rec {
namespace util {
namespace cd {

bool oneCDDBResponse(String* data, StringArray* lines);
StringArray readCDDBResponse(Socket *sock);
StringArray makeCDDBRequest(const String& req, Socket *s);
String trackOffsetString(const TrackOffsets& offset);
String getDiscId(Socket *sock, const String& trackOffsets);
StringArray getPossibleCDs(Socket* sock, const String& offsets);
StringArray getCDData(Socket* sock, const String& line);

}  // namespace cd
}  // namespace util
}  // namespace rec
