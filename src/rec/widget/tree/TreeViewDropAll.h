#pragma once

#include "rec/data/Data.h"
#include "rec/gui/DropTarget.h"
#include "rec/util/Cuttable.h"
#include "rec/util/Listener.h"

namespace rec {
namespace widget {
namespace tree {

using TreeViewDropTarget = gui::DropTarget<TreeView, gui::NullInterface>;

class TreeViewDropAll : public TreeViewDropTarget
#ifdef TREE_VIEW_IS_CUTTABLE
, public Cuttable
#endif
{
  public:
    TreeViewDropAll();
    virtual void paint(Graphics& g);

    bool isInterestedInFileDrag(const StringArray& files);
    bool isTreeDrop(const Component* c) const;

#ifdef TREE_VIEW_IS_CUTTABLE
    virtual bool canCopy() const;
    virtual bool canCut() const { return canCopy(); }
    virtual bool canPaste() const { return true; }
    virtual string copy() const;
    virtual void cut();
    virtual bool paste(const string&);
    const string cuttableName() const { return "Navigator"; }
#endif

  private:
    std::unique_ptr<Drawable> slowGoldIcon_;

    DISALLOW_COPY_ASSIGN_AND_LEAKS(TreeViewDropAll);
};

}  // namespace tree
}  // namespace widget
}  // namespace rec
