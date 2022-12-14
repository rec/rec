#include "rec/audio/util/ProcessAudioFile.h"
#include "rec/audio/format/Manager.h"

namespace rec {
namespace audio {
namespace util {

void processAudioFile(const File& in, const File& out,
                      SourceFilter filter) {
    CHECK(in.exists()) << "File " << str(in) << " doesn't exist";
    std::unique_ptr<AudioFormatReader> reader(format::createReader(in));
    std::unique_ptr<PositionableAudioSource> src(
            new AudioFormatReaderSource(reader.get(), false));

    if (out.exists())
        out.deleteFile();
    OutputStream* stream = out.createOutputStream();
    CHECK(stream) << "Couldn't create file " << str(out);

    AudioFormat* f = format::getWriterAudioFormatManager()->
        findFormatForFileExtension(out.getFileExtension());
    CHECK(f) << "Couldn't find format for file " << str(out);

    std::unique_ptr<AudioFormatWriter> writer(
            f->createWriterFor(stream,
                               reader->sampleRate,
                               reader->numChannels,
                               reader->bitsPerSample,
                               StringPairArray(),
                               0));
    CHECK(writer) << "Couldn't create writer for " << str(out);

    src.reset(filter(src.release()));
    writer->writeFromAudioSource(*src,
                                 static_cast<int>(src->getTotalLength()), 4096);
}

using SourceAndWriter = std::pair<Source*, AudioFormatWriter*>;

SourceAndWriter makeSourceAndWriter(const File& in, const File& out) {
    CHECK(in.exists()) << "File " << str(in) << " doesn't exist";
    std::unique_ptr<AudioFormatReader> reader(format::createReader(in));

    if (out.exists())
        out.deleteFile();
    OutputStream* stream = out.createOutputStream();
    CHECK(stream) << "Couldn't create file " << str(out);

    AudioFormat* f = format::getWriterAudioFormatManager()->
        findFormatForFileExtension(out.getFileExtension());
    CHECK(f) << "Couldn't find format for file " << str(out);

    std::unique_ptr<AudioFormatWriter> writer(
            f->createWriterFor(stream,
                                                  reader->sampleRate,
                                                  reader->numChannels,
                                                  reader->bitsPerSample,
                                                  StringPairArray(),
                                                  0));
    CHECK(writer) << "Couldn't create writer for " << str(out);

    return std::make_pair(new AudioFormatReaderSource(reader.release(), true),
                                                writer.release());
}



}  // namespace util
}  // namespace audio
}  // namespace rec
