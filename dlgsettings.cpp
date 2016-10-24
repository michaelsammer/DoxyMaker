#include "dlgsettings.h"
#include "ui_dlgsettings.h"

#include <QDebug>

DlgSettings::DlgSettings(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::DlgSettings) {
    ui->setupUi(this);

    wdgSettingsGlobal = new WdgSettingGlobal(ui->wdgContent);
    wdgSettingsTemplates = new WdgSettingsTemplates(ui->wdgContent);
    wdgSettingsValues = new WdgSettingsValues(ui->wdgContent);

    ui->lstMenu->addItems(QStringList() << "Global" << "Templates" << "Values");
    ui->lstMenu->setCurrentRow(0);
}

DlgSettings::~DlgSettings() {
    delete ui;
}

void DlgSettings::menuItemChanged() {
    int row = ui->lstMenu->currentRow();

    wdgSettingsGlobal->setVisible(row == 0);
    wdgSettingsTemplates->setVisible(row == 1);
    wdgSettingsValues->setVisible(row == 2);
}
