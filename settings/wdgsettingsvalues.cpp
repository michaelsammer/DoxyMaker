#include "wdgsettingsvalues.h"
#include "ui_wdgsettingsvalues.h"

WdgSettingsValues::WdgSettingsValues(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdgSettingsValues)
{
    ui->setupUi(this);
}

WdgSettingsValues::~WdgSettingsValues()
{
    delete ui;
}
