#pragma once

#include "rec/widget/tree/NodeItem.h"

namespace rec {
namespace widget {
namespace tree {

class NodeComponent : public juce::Component {
  public:
    NodeComponent(Node* n) : Component(n->name()), node_(n) {}
    virtual void paint(juce::Graphics& g)           { node_->paint(g); }
    virtual void mouseDown(const juce::MouseEvent& e) { node_->itemClicked(e); }
    virtual void mouseUp(const juce::MouseEvent& e)   { node_->itemClicked(e); }

  private:
    Node* node_;
    DISALLOW_COPY_ASSIGN_EMPTY_AND_LEAKS(NodeComponent);
};

}  // namespace tree
}  // namespace widget
}  // namespace rec
