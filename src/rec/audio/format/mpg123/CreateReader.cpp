#include "rec/audio/format/mpg123/CreateReader.h"
#include "rec/audio/format/mpg123/Copier.h"
#include "rec/audio/format/mpg123/Mpg123.h"
#include "rec/audio/format/mpg123/NewHandle.h"
#include "rec/audio/format/mpg123/Reader.h"
#include "rec/audio/format/mpg123/Tags.h"

using namespace juce;

namespace rec {
namespace audio {
namespace format {
namespace mpg123 {
namespace {

Error setFormat(mpg123_handle* mh,
                OutputFormat* begin,
                OutputFormat* end) {
    if (begin == end)
        return MPG123_OK;

    if (Error e = mpg123_format_none(mh))
        return e;

    for (OutputFormat* i = begin; i != end; ++i) {
        if (auto e = mpg123_format(mh, i->rate_, i->channels_, i->encoding_))
            return e;
    }

    return MPG123_OK;
}

}  // namespace

#if !JUCE_MAC
#pragma warning(disable: 4706)
#endif

Error createReader(InputStream* in,
                   AudioFormatReader** reader,
                   OutputFormat* begin,
                   OutputFormat* end) {
    mpg123_handle *mh = nullptr;

    long sampleRate;
    int32 numChannels, encoding;
    int32 bitsPerSample;
    Copier copier;

    Error e;
    if ((e = newHandle(in, &mh)) ||
            (e = setFormat(mh, begin, end)) ||
            (e = mpg123_scan(mh)) ||
            (e = mpg123_getformat(mh, &sampleRate, &numChannels, &encoding)) ||
            !(bitsPerSample = getBitsPerSample(encoding)) ||
            !(copier = getCopier(encoding)) ||
            numChannels > MPG123_STEREO) {  // Failure.
        mpg123_delete(mh);

    } else {
        *reader = new Reader(in, getTranslatedName(), mh, copier);
        AudioFormatReader &r = **reader;
        r.bitsPerSample = bitsPerSample;
        r.sampleRate = int32(sampleRate);
        r.lengthInSamples = mpg123_length(mh);
        r.usesFloatingPointData = (encoding & MPG123_ENC_FLOAT) != 0;
        r.numChannels = numChannels;

        getMp3Tags(mh, &r.metadataValues);
    }

    return e;
}

}  // namespace mpg123
}  // namespace format
}  // namespace audio
}  // namespace rec
