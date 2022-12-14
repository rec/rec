#pragma once

#include "rec/data/Data.h"
#include "rec/data/DataMaker.h"

namespace rec {
namespace data {

class UndoStack;

class DataImpl : public Data {
  public:
    DataImpl(Message*, const File&, DataUpdater*, UndoStack*, bool isEmpty,
                      const string& key);
    virtual ~DataImpl() {}

    virtual bool fileReadSuccess() const { return fileReadSuccess_; }
    const string toString() const;
    virtual const File getFile() const { Lock l(lock_); return file_; }
    virtual void update();

  private:
    virtual const string& key() const { return key_; }

    virtual void pushOnUndoStack(const Message& before);
    virtual void reportChange();
    virtual bool writeToFile();

    File file_;
    DataUpdater* dataUpdater_;
    UndoStack* undoStack_;
    const string key_;

    bool fileReadSuccess_;

    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(DataImpl);
};

}  // namespace data
}  // namespace rec
