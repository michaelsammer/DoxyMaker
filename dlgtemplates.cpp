#include "dlgtemplates.h"
#include "ui_dlgtemplates.h"

DlgTemplates::DlgTemplates(QWidget *parent) :
    QDialog(parent), ui(new Ui::DlgTemplates) {
    ui->setupUi(this);

    dlgTemplate = new DlgTemplate(this);

    // load templates
    mngr = new TemplateMngr();
    refreshTemplates();

}

DlgTemplates::~DlgTemplates() {
    delete ui;
}

void DlgTemplates::addTemplate() {
    dlgTemplate->setTemplate();
    dlgTemplate->show();
}

void DlgTemplates::removeTemplate()
{

}

void DlgTemplates::saveTemplate()
{

}

void DlgTemplates::editTemplate() {
    int id = ui->cboTemplate->currentData().toInt();
    TemplateDTO *templ = mngr->getTemplate(id);

    dlgTemplate->setTemplate(templ);
    dlgTemplate->show();
}

void DlgTemplates::templateChanged(int idx) {
    int id = ui->cboTemplate->currentData().toInt();

    data = mngr->loadTemplateContent(id);
    ui->txtHeader->setText(data.content.value(TEMPLATE_TYPE_HEADER)->getContent());
}

void DlgTemplates::refreshTemplates() {
    templates = mngr->loadTemplates();
    ui->cboTemplate->clear();

    foreach(TemplateDTO *dto, templates)
        ui->cboTemplate->addItem(dto->getName(), dto->getId());

}
