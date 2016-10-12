#include "dlgtemplates.h"
#include "ui_dlgtemplates.h"

DlgTemplates::DlgTemplates(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgTemplates)
{
    ui->setupUi(this);
}

DlgTemplates::~DlgTemplates()
{
    delete ui;
}
