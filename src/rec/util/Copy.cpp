#include <google/protobuf/text_format.h>

#include "rec/base/base.h"
#include "rec/util/Copy.h"
#include "glog/logging.h"

using google::protobuf::TextFormat;
using namespace juce;

namespace rec {
namespace copy {

namespace {

// Copy using assignment.
template <typename Type>
bool assign(const Type& from, Type* to, Style /* readable */) {
    *to = from;
    return true;
}

// Copy using the one-argument copy() function.
bool strcopy(const String& from, string* to, Style /* readable */) {
    *to = str(from);
    return true;
}

// Copy using the one-argument copy() function.
bool strcopy(const string& from, String* to, Style /* readable */) {
    *to = str(from);
    return true;
}

// Copy through an string.
template <typename From, typename To>
bool through(const From& from, const To& to, Style readable) {
    string thr;
    return copy(from, &thr, readable) && copy(thr, to, readable);
}

// Copy through an string.
template <typename From, typename To>
bool through(const From& from, To* to, Style readable) {
    string thr;
    return copy(from, &thr, readable) && copy(thr, to, readable);
}

// Copy using googlebase::proto functions.
bool proto(const Message& f, string* t, Style readable) {
    try {
        return readable ? TextFormat::PrintToString(f, t) : f.SerializeToString(t);
    } catch (...) {
        LOG(ERROR) << "Error saving protocol buffer " << f.ShortDebugString();
        return false;
    }
}

bool proto(const string& f, Message* t, Style readable) {
    try {
        return readable ? TextFormat::ParseFromString(f, t) : t->ParseFromString(f);
    } catch (...) {
        LOG(ERROR) << "Error loading protocol buffer " << f;
        LOG(ERROR) << "Type was " << t->GetTypeName();
        return false;
    }
}

bool proto(const Message& f, Message* t, Style /* readable */) {
    try {
        t->CopyFrom(f);
        return true;
    } catch (...) {
        return false;
    }
}

#ifdef REMOVE_UNUSED
bool file(const File &f, File *t, Style /* readable */) {
    return f.copyFileTo(*t);
}
#endif

bool file(const File &f, const File& t, Style /* readable */) {
    return f.copyFileTo(t);
}

bool file(const File &file, string *s, Style /* readable */) {
    try {
        std::unique_ptr<FileInputStream> in(file.createInputStream());
        if (!in)
            return false;
        uint32 length = static_cast<uint32>(in->getTotalLength());
        s->resize(length);
        int bytesRead = in->read((void*)s->data(), length);
        LOG_IF(ERROR, bytesRead < 0) << "negative bytes read.";
        s->resize(bytesRead);

        return true;
    } catch (...) {
        return false;
    }
}

bool file(const string &from, const File &to, Style /* readable */) {
    // This could be replaced with File::replaceWithText.
    try {
        if (!to.getParentDirectory().createDirectory()) {
            LOG(DFATAL) << "Couldn't create directory for " << str(to);
            return false;
        }

        bool rename = to.exists();
        File backupFile;
        if (rename) {
            backupFile = File(to.getFullPathName() + ".bak");
            if (!to.moveFileTo(backupFile))
                LOG(DFATAL) << "Couldn't rename to backup file: " << str(backupFile);
        }

        std::unique_ptr<FileOutputStream> out(to.createOutputStream());
        if (!out)
            LOG(DFATAL) << "Couldn't make OutputStream for " << str(to);

        else if (!out->write(from.data(), from.size()))
            LOG(DFATAL) << "Couldn't write file " << str(to);

        else if (rename && !backupFile.deleteFile())
            LOG(DFATAL) << "Couldn't delete backup " << str(to);

        else
            return true;

    } catch (...) {
        LOG(DFATAL) << "We got an exception";
        // We could also log this exception here.
    }
    return false;
}

using Memory = MemoryBlock;

bool memory(const string& in, Memory* out, Style /* readable */) {
    int size = in.size();
    out->ensureSize(size);
    out->copyFrom(in.data(), 0, size);
    return true;
}

bool memory(const Memory& in, string* out, Style /* readable */) {
    int size = in.getSize();
    out->resize(size);
    in.copyTo(&((*out)[0]), 0, size);
    return true;
}

}  // namespace

bool copy(const File &f,    File *t,    Style s) { return file(f, *t, s); }
bool copy(const File &f,    Memory *t,  Style s) { return through(f, t, s); }
bool copy(const File &f,    Message *t, Style s) { return through(f, t, s); }
bool copy(const File &f,    String *t,  Style s) { return through(f, t, s); }
bool copy(const File &f,    string *t,  Style s) { return file(f, t, s); }

bool copy(const Memory &f,  File *t,    Style s) { return through(f, t, s); }
bool copy(const Memory &f,  Memory *t,  Style s) { return assign(f, t, s); }
bool copy(const Memory &f,  Message *t, Style s) { return through(f, t, s); }
bool copy(const Memory &f,  String *t,  Style s) { return through(f, t, s); }
bool copy(const Memory &f,  string *t,  Style s) { return memory(f, t, s); }

bool copy(const Message &f, File *t,    Style s) { return through(f, t, s); }
bool copy(const Message &f, Memory *t,  Style s) { return through(f, t, s); }
bool copy(const Message &f, Message *t, Style s) { return proto(f, t, s); }
bool copy(const Message &f, String *t,  Style s) { return through(f, t, s); }
bool copy(const Message &f, string *t,  Style s) { return proto(f, t, s); }

bool copy(const String &f,  File *t,    Style s) { return through(f, t, s); }
bool copy(const String &f,  Memory *t,  Style s) { return through(f, t, s); }
bool copy(const String &f,  Message *t, Style s) { return through(f, t, s); }
bool copy(const String &f,  String *t,  Style s) { return assign(f, t, s); }
bool copy(const String &f,  string *t,  Style s) { return strcopy(f, t, s); }

bool copy(const string &f,  File *t,    Style s) { return file(f, *t, s); }
bool copy(const string &f,  Memory *t,  Style s) { return memory(f, t, s); }
bool copy(const string &f,  Message *t, Style s) { return proto(f, t, s); }
bool copy(const string &f,  String *t,  Style s) { return strcopy(f, t, s); }
bool copy(const string &f,  string *t,  Style s) { return assign(f, t, s); }

bool copy(const File &f,    const File &t, Style s) { return file(f, t, s); }
bool copy(const string &f,  const File &t, Style s) { return file(f, t, s); }
bool copy(const String &f,  const File &t, Style s) { return through(f, t, s); }
bool copy(const Message &f, const File &t, Style s) { return through(f, t, s); }
bool copy(const Memory &f,  const File &t, Style s) { return through(f, t, s); }


bool merge(const string &f,  Message *t, Style s) {
    if (s)
        return TextFormat::MergeFromString(f, t);

    std::unique_ptr<Message> m(t->New());
    if (not m->ParseFromString(f))
        return false;
    t->MergeFrom(*m);
    return true;
}

}  // namespace copy
}  // namespace rec
