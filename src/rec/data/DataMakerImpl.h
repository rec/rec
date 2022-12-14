#pragma once

#include "rec/data/DataImpl.h"
#include "rec/data/DataMaker.h"

namespace rec {
namespace data {

class DataMakerImpl : public DataMaker {
  public:
    DataMakerImpl(DataUpdater* u, UndoStack* s)
            : dataUpdater_(u), undoStack_(s) {
    }

    virtual ~DataMakerImpl() {}

    virtual Data* makeData(Message* m, const File& file, bool isEmpty,
                                                  const string& key) const {
        return new DataImpl(m, file, dataUpdater_, undoStack_, isEmpty, key);
    }

  private:
    DataUpdater* dataUpdater_;
    UndoStack* undoStack_;

    DISALLOW_COPY_ASSIGN_AND_LEAKS(DataMakerImpl);
};

}  // namespace data
}  // namespace rec
