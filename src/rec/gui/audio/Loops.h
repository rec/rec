#pragma once

#include "rec/app/LanguageListener.h"
#include "rec/data/Address.h"
#include "rec/data/DataListener.h"
#include "rec/gui/TableController.h"
#include "rec/util/Cuttable.h"
#include "rec/widget/waveform/Viewport.pb.h"

namespace rec {
namespace gui {
namespace audio {

class Loops : public TableController,
                            public DataListener<widget::waveform::Viewport>,
                            public app::LanguageListener,
                            public HasCuttable {
  public:
    Loops(const TableColumnList* desc = nullptr,
                const data::Address* partAddress = nullptr);
    virtual ~Loops();

    virtual void operator()(const widget::waveform::Viewport&);
    virtual void languageChanged();
    virtual int getNumRows();
    virtual Cuttable* cuttable() { return cuttable_.get(); }
    virtual void selectedRowsChanged(int lastRowSelected);

    void editViewport(const widget::waveform::Viewport&);
    virtual void setFieldValue(int column, int row, const String& text);
    virtual String displayText(int column, int row) const;
    virtual String getCellTooltip(int column, int row) const;
    virtual void cellDoubleClicked(int rowNumber, int columnId,
                                                                  const MouseEvent&);

    virtual bool selected(int row) const;
    virtual void setEditing(bool);

  protected:
    virtual void update();

    data::Address getAddress(int col, int row) const {
        data::Address address = partAddress_;
        address.add_part()->set_index(row);
        address.mutable_part()->MergeFrom(columns_.column(col).address().part());
        return address;
    }

  private:
    void setViewport(const widget::waveform::Viewport&);

    widget::waveform::Viewport viewport_;
    data::Address partAddress_;
    std::unique_ptr<Cuttable> cuttable_;

    DISALLOW_COPY_ASSIGN_AND_LEAKS(Loops);
};

}  // namespace rec
}  // namespace gui
}  // namespace audio
