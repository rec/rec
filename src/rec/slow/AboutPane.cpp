#include "rec/slow/AboutPane.h"

#include "rec/base/Trans.h"
#include "rec/gui/CaptionText.h"
#include "rec/gui/Dialog.h"
#include "rec/gui/SetterToggle.h"
#include "rec/program/JuceModel.h"
#include "rec/program/Program.h"
#include "rec/slow/GuiSettings.pb.h"
#include "rec/slow/Instance.h"
#include "rec/slow/SlowWindow.h"
#include "rec/util/ews/EWS.h"

using namespace juce;
using namespace rec::app;
using namespace rec::ews;
using namespace rec::gui;

TRAN(AUTHENTICATED_TITLE, "Thank you!");
TRAN(COULDNT_AUTHENTICATE_TITLE, "Couldn't authenticate.");
TRAN(AUTHENTICATED, "Your serial number was authenticated! "
          "Thanks for supporting independent developers.");
TRAN(COULDNT_AUTHENTICATE,
          "Couldn't authenticate your name and serial number because:");
TRAN(DISPLAY_ON_STARTUP, "Display this window on startup");
TRAN(DISPLAY_ON_STARTUP_TOOLTIP, "Turn this box on if you want About Slow "
              "Gold to appear on startup.");
TRAN(DRAG_AUDIO, "Drag audio files onto the waveform.");
TRAN(CD_AUTOMATIC, "CDs will automatically appear at the top-left when you "
              "insert them.");
TRAN(PRESS_SPACE, "Press the space bar to start and stop playback.");
TRAN(DRAG_SPEED, "Drag the Speed slider to slow down or speed up.");
TRAN(CREATE_LOOPS, "Create loop points by pressing the L key.");
TRAN(DOWNLOAD_MANUAL, "Download the manual from the Help menu for many more "
              "commands.");
TRAN(CLOSE_TEXT, "Close");
TRAN(COPYRIGHT, "Copyright \xc2\xa9 %d-%d");
TRAN(REGISTERED_TO, "Registered To:");
TRAN(SERIAL_NUMBER, "Serial Number:");
TRAN(UNREGISTERED_START, "This unregistered copy expires in");
TRAN(UNREGISTERED_SINGLE, "day.");
TRAN(UNREGISTERED_PLURAL, "days.");
TRAN(EXPIRED, "This unregistered copy has expired!");
TRAN(NAME_LABEL, "Name");
TRAN(NAME_TOOLTIP, "Enter the name you want to register this program to.");
TRAN(SERIAL_NUMBER_LABEL, "Serial Number");
TRAN(SERIAL_NUMBER_TOOLTIP, "Enter the serial number exactly as in your "
          "Order Confirmation.");
TRAN(REGISTER_TEXT, "Register SlowGold");

namespace rec {
namespace slow {

namespace {

const int MARGINI = 12;
const float MARGINF = static_cast<float>(MARGINI);
const int CENTER_OFFSET = 80;
const int LEFT_OFFSET = 125;
const int BUTTON_HEIGHT = 20;
const int BUTTON_WIDTH = 250;

const int FORM_OFFSET = 108;
const int FORM_MARGIN = 12;
const int FORM_LINE_HEIGHT = 34;
const int FORM_ITEM_HEIGHT = 24;
const int BUTTON_SPACING = 35;
const int SECOND_BUTTON_WIDTH = 120;
const int SECOND_BUTTON_OFFSET = 25;
const int CAPTION_SIZE = 76;

Font aboutFont() {
    return Font("Ariel", 20, 0);
}

Font formFont() {
    return Font("Ariel", 12, 0);
}

Font serialFont() {
    return Font("Ariel", 15, 0);
}

}  // namespace

const int AboutPane::WIDTH = 700;
const int AboutPane::HEIGHT = 380;

AboutPane::AboutPane(
        const String& name, const String& versionNumber,
        ModalComponentManager::Callback* callback)
        : displayOnStartup_(new SetterToggle(
                    str(t_DISPLAY_ON_STARTUP),
                    str(t_DISPLAY_ON_STARTUP_TOOLTIP),
                    data::makeAddress<GuiSettings>("show_about_on_startup"))),
            authentication_(new Authentication),
            name_(new CaptionText(
                    t_NAME_LABEL, t_NAME_TOOLTIP, "", true, CAPTION_SIZE)),
            serialNumber_(new CaptionText(
                    t_SERIAL_NUMBER_LABEL, t_SERIAL_NUMBER_TOOLTIP, "",
                    true, CAPTION_SIZE)),
            accept_(t_REGISTER_TEXT),
            close_(t_CLOSE_TEXT),
            callback_(callback) {
    addAndMakeVisible(displayOnStartup_.get());
    displayOnStartup_->setBounds(MARGINI, HEIGHT - MARGINI - BUTTON_HEIGHT,
                                                            BUTTON_WIDTH, BUTTON_HEIGHT);

    auto font = formFont();
    name_->setFont(font);
    serialNumber_->setFont(font);
    addChildComponent(name_.get());
    name_->setBounds(FORM_MARGIN,
                                    FORM_OFFSET,
                                    WIDTH - 2 * FORM_MARGIN,
                                    FORM_ITEM_HEIGHT);
    name_->editor()->addListener(this);

    addChildComponent(serialNumber_.get());
    serialNumber_->setBounds(FORM_MARGIN,
                                                    FORM_OFFSET + FORM_LINE_HEIGHT,
                                                    WIDTH - 2 * FORM_MARGIN,
                                                    FORM_ITEM_HEIGHT);

    serialNumber_->editor()->addListener(this);

    addChildComponent(&accept_);
    auto bx = SECOND_BUTTON_OFFSET +
            (WIDTH - 2 * SECOND_BUTTON_WIDTH - BUTTON_SPACING) / 2;
    auto by = FORM_OFFSET + FORM_LINE_HEIGHT * 2;
    accept_.setBounds(bx, by, SECOND_BUTTON_WIDTH, FORM_ITEM_HEIGHT);
    accept_.setEnabled(false);
    accept_.addListener(this);

    addChildComponent(&close_);
    close_.setBounds(bx + SECOND_BUTTON_WIDTH + BUTTON_SPACING, by,
                                      SECOND_BUTTON_WIDTH, FORM_ITEM_HEIGHT);
    close_.addListener(this);

    setOpaque(true);
    displayOnStartup_->updateCallback();
}

AboutPane::~AboutPane() {
    name_->editor()->removeListener(this);
    serialNumber_->editor()->removeListener(this);
    accept_.removeListener(this);
}

bool AboutPane::expired() const {
    return authentication_->expired();
}

bool AboutPane::authenticated() const {
    return authentication_->authenticated();
}

void AboutPane::buttonClicked(Button* button) {
    if (button == &accept_) {
        auto user = name_->editor()->getText().trim();
        auto error = ews::confirmAndActivate(
                str(serialNumber_->editor()->getText().trim()), str(user));
        if (error.empty()) {
            program::juceModel()->setProperty("unauthorized", false);
            authentication_->user = user.toStdString();
            AlertWindow::showMessageBoxAsync(
                    AlertWindow::InfoIcon, t_AUTHENTICATED_TITLE, t_AUTHENTICATED, "",
                    nullptr, callback_);
        } else {
            AlertWindow::showMessageBoxAsync(
                    AlertWindow::WarningIcon, t_COULDNT_AUTHENTICATE_TITLE,
                    String(t_COULDNT_AUTHENTICATE + String("\n") + error));
        }
    } else {
        if (not expired())
            callback_->modalStateFinished(0);
    }
}

void AboutPane::textEditorTextChanged(TextEditor&) {
    auto disabled = name_->editor()->getText().isEmpty() or
            serialNumber_->editor()->getText().isEmpty();
    accept_.setEnabled(not disabled);
}

void AboutPane::paint(Graphics& g) {
    g.fillAll(Colours::white);
    g.setColour(Colours::red);
    g.drawRect(0, 0, WIDTH, HEIGHT);
    Rectangle<float> area(MARGINF, MARGINF,
                                                WIDTH - 2 * MARGINF,
                                                HEIGHT - 2 * MARGINF);
    right_.draw(g, area);

    area.setY(area.getY() + CENTER_OFFSET);
    center_.draw(g, area);

    area.setY(area.getY() + LEFT_OFFSET);
    left_.draw(g, area);
}

void AboutPane::visibilityChanged() {
    *authentication_ = testAuthenticated();
    if (not isVisible())
        return;

    auto visible = not authentication_->authenticated();
    if (visible)
        program::getProgram()->setEnabled(false);
    name_->setVisible(visible);
    serialNumber_->setVisible(visible);
    accept_.setVisible(visible);
    close_.setVisible(visible);
    close_.setEnabled(not expired());
    getRightSide();
    getLeftSide();
    displayOnStartup_->setEnabled(not visible);
}

void AboutPane::getRightSide() {
    right_.clear();
    right_.setJustification(Justification::topRight);

    center_.clear();
    center_.setJustification(Justification::centredTop);

    auto font = aboutFont();
    auto name = JUCEApplication::getInstance()->getApplicationName();
    auto version = JUCEApplication::getInstance()->getApplicationVersion();
    auto t = name + " " + version + "\nWorld Wide Woodshed Software\n" +
            String::formatted(t_COPYRIGHT, 2012, 2017) + String("\n");
    right_.append(t, font);

    auto user = String(authentication_->user);
    if (user.isEmpty()) {
        auto days = authentication_->daysToExpiration;
        if (days > 0) {
            auto& plural = (days == 1) ? t_UNREGISTERED_SINGLE : t_UNREGISTERED_PLURAL;
            right_.append(t_UNREGISTERED_START, font);
            right_.append(" ", font);
            right_.append(String(days), font, days < 10 ? Colours::red : Colours::black);
            right_.append(" ");
            right_.append(plural, font);
        } else {
            right_.append(t_EXPIRED, font, Colours::red);
        }
    } else {
          center_.append(String("\n") + t_REGISTERED_TO + " " + user + "\n\n",
                                      font);
        center_.append(t_SERIAL_NUMBER + String(" ") +
                                      authentication_->serialNumber, serialFont());
    }
}

void AboutPane::getLeftSide() {
    left_.clear();
    left_.setJustification(Justification::topLeft);
    auto s =
            str("* " + t_DRAG_AUDIO + "\n" +
                    "* " + t_CD_AUTOMATIC + "\n" +
                    "* " + t_PRESS_SPACE + "\n" +
                    "* " + t_DRAG_SPEED + "\n" +
                    "* " + t_CREATE_LOOPS + "\n" +
                    "* " + t_DOWNLOAD_MANUAL + "\n");
    left_.append(s, aboutFont());
}

}  // namespace slow
}  // namespace rec
