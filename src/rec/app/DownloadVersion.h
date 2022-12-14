#pragma once

#include "rec/base/base.h"

namespace rec {
namespace app {

enum DownloadStatus {
    DOWNLOAD_NOT_FOUND,
    DOWNLOAD_SUCCEEDED,
    DOWNLOAD_CANCELLED_OR_FAILED
};

// Returns true if a new version was downloaded.
void downloadNewVersionIfNeeded(const String& version, const String& name);
bool downloadNewVersionIfNeededBlocking();

extern const String WOODSHED;

}  // namespace app
}  // namespace rec
