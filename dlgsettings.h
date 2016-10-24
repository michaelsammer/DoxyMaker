#ifndef DLGSETTINGS_H
#define DLGSETTINGS_H

#include <QMainWindow>

#include "settings/wdgsettingglobal.h"
#include "settings/wdgsettingstemplates.h"
#include "settings/wdgsettingsvalues.h"

namespace Ui {
class DlgSettings;
}

class DlgSettings : public QMainWindow {
    Q_OBJECT

public:
    explicit DlgSettings(QWidget *parent = 0);
    ~DlgSettings();

public slots:
    void menuItemChanged();

private:
    Ui::DlgSettings *ui;
    WdgSettingGlobal *wdgSettingsGlobal;
    WdgSettingsTemplates *wdgSettingsTemplates;
    WdgSettingsValues *wdgSettingsValues;

};

#endif // DLGSETTINGS_H
