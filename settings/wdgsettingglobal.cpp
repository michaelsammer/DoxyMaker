#include "wdgsettingglobal.h"
#include "ui_wdgsettingglobal.h"

WdgSettingGlobal::WdgSettingGlobal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WdgSettingGlobal)
{
    ui->setupUi(this);
}

WdgSettingGlobal::~WdgSettingGlobal()
{
    delete ui;
}
