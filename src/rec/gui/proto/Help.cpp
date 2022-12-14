#include "rec/gui/proto/Help.h"

#include "rec/util/StateListener.h"
#include "rec/gui/proto/Component.pb.h"
#include "rec/gui/proto/Constants.h"
#include "rec/gui/proto/Context.h"
#include "rec/gui/proto/Panel.h"
#include "rec/gui/SimpleLabel.h"
#include "rec/util/Binary.h"
#include "rec/util/Listener.h"

using namespace juce;

namespace rec {
namespace gui {

namespace {

class HelpPanel : public Panel, public StateListener<const HelpText&> {
  public:
    HelpPanel(const Context& context)
    : Panel("HelpPanel", VERTICAL),
                caption_(new SimpleLabel),
                body_(new SimpleLabel) {
        INSTANCE = this;

        auto& comp = context.component_;
        auto& constants = context.constants_;
        const HelpProto& proto = comp.help();
        auto& s1 = proto.has_caption_size() ? proto.caption_size() : comp.size();
        addToPanel(caption_, constants, s1);

        auto& s2 = proto.has_body_size() ? proto.body_size() : comp.size();
        addToPanel(body_, constants, s2);

        caption_->setColour(juce::Label::textColourId, Colours::darkgreen);
        caption_->setJustificationType(Justification::centred);
        Font font = caption_->getFont();
        font.setBold(true);
        font.setHeight(font.getHeight() + 2);
        body_->setFont(font);
        font.setHeight(font.getHeight() + 3);
        caption_->setFont(font);

        body_->setColour(juce::Label::textColourId, juce::Colours::darkgreen);
        body_->setJustificationType(Justification::topLeft);
    }

    void setTooltip(const String& tt) override {
        caption_->setTooltip(tt);
        body_->setTooltip(tt);
    }

    void operator()(const HelpText& help) override {
        caption_->setTextIfChanged(help.first, juce::dontSendNotification);
        body_->setTextIfChanged(help.second, juce::dontSendNotification);
    }

    ~HelpPanel() {
        INSTANCE = nullptr;
    }

    static HelpPanel* INSTANCE;

    SimpleLabel* caption_;
    SimpleLabel* body_;
};

HelpPanel* HelpPanel::INSTANCE = nullptr;

}  // namespace

std::unique_ptr<Component> makeHelp(const Context& context) {
    return std::unique_ptr<Component>(new HelpPanel(context));
}

}  // namespace gui
}  // namespace rec
