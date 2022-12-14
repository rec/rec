#include "rec/gui/proto/Component.h"

#include "rec/util/Disableable.h"
#include "rec/util/DisableMap.h"
#include "rec/gui/proto/Button.h"
#include "rec/gui/proto/ComboBox.h"
#include "rec/gui/proto/Component.pb.h"
#include "rec/gui/proto/Constants.h"
#include "rec/gui/proto/Context.h"
#include "rec/gui/proto/Custom.h"
#include "rec/gui/proto/Help.h"
#include "rec/gui/proto/Label.h"
#include "rec/gui/proto/Layout.h"
#include "rec/gui/proto/LevelMeter.h"
#include "rec/gui/proto/Panel.h"
#include "rec/gui/proto/Resizer.h"
#include "rec/gui/proto/Slider.h"
#include "rec/gui/proto/Switcher.h"
#include "rec/gui/proto/Text.h"
#include "rec/gui/proto/Time.h"
#include "rec/gui/proto/TimeDial.h"
#include "rec/gui/proto/ToggleButton.h"
#include "rec/program/JuceModel.h"

namespace rec {
namespace gui {

namespace {

using ComponentMaker = std::unique_ptr<Component> (*)(const Context&);

ComponentMaker make(const ComponentProto& c) {
    if (c.has_button())
        return &makeButton;

    if (c.has_combo_box())
        return &makeComboBox;

    if (c.has_custom())
        return &makeCustom;

    if (c.has_help())
        return &makeHelp;

    if (c.has_label())
        return &makeLabel;

    if (c.has_layout())
        return &makeLayoutComp;

    if (c.has_level_meter())
        return &makeLevelMeter;

    if (c.has_resizer())
        return &makeSimpleResizer;

    if (c.has_full_resizer())
        return &makeResizer;

    if (c.has_slider())
        return &makeSlider;

    if (c.has_switcher())
        return &makeSwitcher;

    if (c.has_text())
        return &makeText;

    if (c.has_time())
        return &makeTime;

    if (c.has_time_dial())
        return &makeTimeDial;

    if (c.has_toggle_button())
        return &makeToggleButton;

    return nullptr;
}

}  // namespace

std::unique_ptr<Component> makeComponent(const Context& context) {
    auto& comp = context.component_;
    std::unique_ptr<Component> component;
    if (ComponentMaker maker = make(comp)) {
        component = maker(context);
        const string* name = &comp.name();
        if (name->empty())
            name = &comp.layout();
        if (name->empty())
            name = &comp.resizer();

        DCHECK(not name->empty()) << comp.ShortDebugString();
        component->setName(str(*name));
        Component* c = component.get();
        if (SettableTooltipClient* tt = dynamic_cast<SettableTooltipClient*>(c))
            tt->setTooltip(comp.tooltip());

        if (Disableable* dc = dynamic_cast<Disableable*>(c)) {
            dc->addDisableProperties(comp.disabled());
            program::juceModel()->addComponent(dc);
            dc->disable(dc->getDisabledFromProperties());
        } else {
            LOG(DFATAL) << comp.ShortDebugString() << " !!! " << component->getName();
        }
    } else {
        LOG(DFATAL) << "No component in " << comp.ShortDebugString();
    }

    DCHECK(component->getName().length()) << comp.ShortDebugString();
    return std::move(component);
}

}  // namespace gui
}  // namespace rec
