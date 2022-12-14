#include "rec/audio/format/mpg123/Tags.h"

#include "rec/audio/format/mpg123/CleanGenre.h"

using juce::StringPairArray;

namespace rec {
namespace audio {
namespace format {
namespace mpg123 {

static void setData(mpg123_text* text, int32 size, StringPairArray* data) {
    for (mpg123_text* t = text; t != text + size; ++t) {
        String name(t->id, 4);
        for (; (*data)[name] != ""; name += "+");
        data->set(name, str(string(t->text.p, t->text.fill)));
    }
}

Error getMp3Tags(mpg123_handle* mh, StringPairArray* data) {
    if (!mpg123_meta_check(mh))
        return MPG123_ERR;

    mpg123_id3v1 *v1;
    mpg123_id3v2 *v2;

    if (Error e = mpg123_id3(mh, &v1, &v2))
        return e;

    if (v2) {
        data->set("idversion", "id3v2");
        setData(v2->text, v2->texts, data);
        setData(v2->comment_list, v2->comments, data);
        setData(v2->extra, v2->extras, data);

        return MPG123_OK;
    }

    if (v1) {
        data->set("idversion", "id3v1");
        data->set("title", String(v1->title, 30));
        data->set("artist", String(v1->artist, 30));
        data->set("album", String(v1->album, 30));
        data->set("year", String(v1->year, 4));
        data->set("comment", String(v1->comment, 30));
        data->set("genre", str(cleanGenre(v1->genre)));

        return MPG123_OK;
    }

    return MPG123_ERR;
}

}  // namespace mpg123
}  // namespace format
}  // namespace audio
}  // namespace rec
