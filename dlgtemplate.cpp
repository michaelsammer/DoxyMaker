#include "dlgtemplate.h"
#include "ui_dlgtemplate.h"

DlgTemplate::DlgTemplate(QWidget *parent) :
    QDialog(parent), ui(new Ui::DlgTemplate) {
    ui->setupUi(this);

    mngr = new TemplateMngr();
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

void DlgTemplate::save() {
    QString name = ui->txtName->text();

    if (name.length() <= 0)
        QMessageBox::critical(this, "Error", "Name may not be empty string!");
    else {

        if (templ == 0)
            mngr->addTemplate(name, ui->txtDesc->document()->toPlainText());
        else {
            templ->setName(name);
            templ->setDesc(ui->txtDesc->document()->toPlainText());
            mngr->saveTemplate(templ);
        }

        emit templateChanged();
    }
}
