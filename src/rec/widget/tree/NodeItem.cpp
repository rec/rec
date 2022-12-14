#include "rec/widget/tree/NodeItem.h"

#include "rec/base/DropDead.h"
#include "rec/data/Data.h"
#include "rec/data/DataOps.h"
#include "rec/data/proto/Equals.h"
#include "rec/music/CleanName.h"
#include "rec/widget/tree/NodeComponent.h"
#include "rec/util/file/DisplayFile.h"
#include "rec/util/file/VirtualFile.h"

namespace rec {
namespace widget {
namespace tree {

Node::Node(const NodeDesc& d, const VirtualFile& vf, const char* name)
        : desc_(d),
            virtualFile_(vf),
            icon_(nullptr),
            font_(gui::getFont(desc_.widget().font())),
            topSelection_(false),
            topLevel_(false),
            processing_(false),
            clicked_(false) {
    CHECK_DDD(7134, 1893, int64, int16);

    if (name)
        name_ = name;

    setLinesDrawnForSubItems(
#if JUCE_MAC
        false
#else
        true
#endif
        );
}

ColorName Node::getColor() const {
    if (isSelected())
        return BLACK;

    if (clicked_)
        return BORDER;

    if (processing_)
        return FOREGROUND;

    if (isCurrent())
        return SPECIAL;

    if (getVisitedFile().exists())
        return HIGHLIGHT;

    return REGULAR;
}

void Node::paint(juce::Graphics& g) const {
    Painter p(desc_.widget(), &g);
    if (icon_)
        icon_->draw(g, 1.0f);

    p.setColor(getColor());
    g.drawSingleLineText(name(), desc_.widget().margin(),
                                              static_cast<int>(font_.getAscent() +
                                                                                desc_.widget().margin()));
}

const String Node::name() const {
    if (!name_.length())
        name_ = computeName();

    return name_;
}

void Node::itemClicked(const MouseEvent& e) {
    if (!juce::ModifierKeys::getCurrentModifiers().isAnyMouseButtonDown()) {
        clicked_ = false;

    } else if (e.mods.isShiftDown()) {
        if (!(getParentItem() && getParentItem()->getParentItem()))
            setSelected(!isSelected(), false);

    } else if (isDirectory()) {
        setOpen(!isOpen());

    } else {
        clicked_ = true;
        broadcast(virtualFile_);
        getVisitedFile().create();
    }

    repaintItem();
}

void Node::refreshNode(const VirtualFile& f) {
    if (virtualFile_ == f) {
        repaintItem();
    } else {
        for (int i = 0; i < getNumSubItems(); ++i) {
            if (Node* node = dynamic_cast<Node*>(getSubItem(i)))
                node->refreshNode(f);
            else
                LOG(DFATAL) << "Found a non-Node node!";
        }
    }
}

String Node::computeName() const {
    String name = getDisplayName(virtualFile_);
    if (!isDirectory())
        name = music::cleanName(name);
    return name;
}

const gui::Rectangle Node::bounds() const {
    return desc_.widget().layer().bounds();
}

int Node::getItemWidth() const {
    return font_.getStringWidth(name()) + 2 * desc_.widget().margin();
}

int Node::getItemHeight() const {
    return static_cast<int>(font_.getHeight() + 2 * desc_.widget().margin());
}

juce::Component* Node::createItemComponent() {
    return new NodeComponent(this);
}

static const char* const VISITED_FILE = "Visited.touch";

File Node::getVisitedFile() const {
    return getShadowDirectory(virtualFile_).getChildFile(VISITED_FILE);
}

bool Node::isCurrent() const {
    return (virtualFile_ == data::getProto<VirtualFile>());
}

}  // namespace tree
}  // namespace widget
}  // namespace rec
