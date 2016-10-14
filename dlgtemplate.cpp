#include "dlgtemplate.h"
#include "ui_dlgtemplate.h"

DlgTemplate::DlgTemplate(QWidget *parent) :
    QDialog(parent), ui(new Ui::DlgTemplate) {
    ui->setupUi(this);

}

DlgTemplate::~DlgTemplate() {
    delete ui;
}

void DlgTemplate::setTemplate(TemplateDTO *templ) {
    this->templ = templ;

    if (templ == 0) {
        ui->txtName->clear();
        ui->txtDesc->clear();
    } else {
        ui->txtName->setText(templ->getName());
        ui->txtDesc->setText(templ->getDesc());
    }
}

void DlgTemplate::save()
{

}
