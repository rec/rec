#ifndef __REC_AUDIO_FORMAT_MPG123_REPLACE_READER__
#define __REC_AUDIO_FORMAT_MPG123_REPLACE_READER__

#include <stdlib.h>
#include <sys/types.h>

#include "rec/audio/format/mpg123/NewHandle.h"

#if !JUCE_MAC
#pragma warning(disable: 4706)
#endif

namespace rec {
namespace audio {
namespace format {
namespace mpg123 {

namespace {

ssize_t read(void *inputStream, void *buf, size_t nbytes) {
    return static_cast<InputStream*>(inputStream)->read(buf, nbytes);
}

off_t seek(void *inputStream, off_t off, int32 whence) {
    int64 offset = off;
    InputStream* in = static_cast<InputStream*>(inputStream);

    if (whence == SEEK_CUR)
        offset += in->getPosition();

    else if (whence == SEEK_END)
        offset += in->getTotalLength();

    else if (whence != SEEK_SET)
        offset = -1;

    return static_cast<off_t>((offset >= 0) && in->setPosition(offset) ? offset
                              : -1);
}

}  // namespace

Error newHandle(InputStream* in, mpg123_handle** result) {
    Error e;
    mpg123_handle* mh = nullptr;

    if (!(e = initializeOnce()) &&
        (mh = mpg123_new(nullptr, &e)) &&
        !(e = mpg123_replace_reader_handle(mh, read, seek, nullptr)) &&
        !(e = mpg123_open_handle(mh, in))) {
        *result = mh;
    } else {
        mpg123_delete(mh);
    }

    return e;
}

}  // namespace mpg123
}  // namespace format
}  // namespace audio
}  // namespace rec

#endif  // __REC_AUDIO_FORMAT_MPG123_REPLACE_READER__
