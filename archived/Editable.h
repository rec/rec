#ifndef __REC_DATA_EDITABLE__
#define __REC_DATA_EDITABLE__

#include <map>
#include <set>

#include "rec/data/Address.h"
#include "rec/data/Value.h"
#include "rec/util/Proto.h"
#include "rec/util/file/VirtualFile.pb.h"

namespace rec {
namespace data {

class Address;
class AddressProto;
class Editable;
class UntypedEditable;
class Value;
class ValueProto;

typedef std::map<string, UntypedEditable*> EditableMap;
typedef std::set<UntypedEditable*> EditableSet;
typedef std::vector<Editable*> EditableList;


#if 0
 // private:
  void setValue(const Value&, const Address& a = Address::default_instance(),
                bool undoable = true);
 public:
  void append(const Value& value, const Address&);
  string toString() const { return ptr<Message>(clone())->ShortDebugString(); }

  virtual void applyLater(Operations*) = 0;
  virtual void applyOperations(const Operations& olist,
                               Operations* undoes = NULL) = 0;
  virtual void onDataChange() = 0;

  virtual const Value getValue(const Address&) const = 0;
  virtual const string getTypeName() const = 0;
  virtual const VirtualFile& virtualFile() const = 0;
  virtual bool readFromFile() const = 0;
  virtual bool writeToFile() const = 0;

  virtual bool hasValue(const Address&) const = 0;
  virtual void copyTo(Message*) const = 0;
  virtual int getSize(const Address&) const = 0;
  virtual Message* clone() const = 0;
  virtual void needsUpdate() = 0;
  virtual void updateClients() = 0;

  // Returns true if there is no actual value behind changed behind this item.
  virtual bool isEmpty() const = 0;
};

#endif

void setValue(Editable* e, const Value&,
              const Address& a = Address::default_instance(),
              bool undoable = true);

// There are more setters in archived/OldEditable.h

}  // namespace data
}  // namespace rec

#endif  // __REC_DATA_EDITABLE__
