#include "dlgtemplates.h"
#include "ui_dlgtemplates.h"

DlgTemplates::DlgTemplates(QWidget *parent) :
    QDialog(parent), ui(new Ui::DlgTemplates) {
    ui->setupUi(this);

    dlgTemplate = new DlgTemplate(this);
    connect(dlgTemplate, SIGNAL(templateChanged()), this, SLOT(templatesModified()));

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

void DlgTemplates::removeTemplate() {
    mngr->deleteTemplate(ui->cboTemplate->currentData().toInt());

    refreshTemplates();
}

void DlgTemplates::saveTemplate() {
    mngr->saveContent(data);

    // set back all document modified states
    ui->txtHeader->document()->setModified(false);
    ui->txtEnum->document()->setModified(false);
    ui->txtStruct->document()->setModified(false);
    ui->txtClass->document()->setModified(false);
    ui->txtMethod->document()->setModified(false);
}

void DlgTemplates::editTemplate() {
    int id = ui->cboTemplate->currentData().toInt();
    TemplateDTO *templ = mngr->getTemplate(id);

    dlgTemplate->setTemplate(templ);
    dlgTemplate->show();
}

void DlgTemplates::templateIdxChanged(int idx) {
    int id = ui->cboTemplate->currentData().toInt();

    data = mngr->loadTemplateContent(id);
    ui->txtHeader->setText(data.content.value(TEMPLATE_TYPE_HEADER)->getContent());
}

void DlgTemplates::contentChanged() {
    bool modified = false;

    if (ui->txtHeader->document()->isModified()) {
        data.content.value(TEMPLATE_TYPE_HEADER)->setContent(ui->txtHeader->document()->toPlainText());
        modified = true;
    }
    if (ui->txtEnum->document()->isModified()) {
        data.content.value(TEMPLATE_TYPE_ENUM)->setContent(ui->txtEnum->document()->toPlainText());
        modified = true;
    }
    if (ui->txtStruct->document()->isModified()) {
        data.content.value(TEMPLATE_TYPE_STRUCT)->setContent(ui->txtStruct->document()->toPlainText());
        modified = true;
    }
    if (ui->txtClass->document()->isModified()) {
        data.content.value(TEMPLATE_TYPE_CLASS)->setContent(ui->txtClass->document()->toPlainText());
        modified = true;
    }
    if (ui->txtMethod->document()->isModified()) {
        data.content.value(TEMPLATE_TYPE_METHOD)->setContent(ui->txtMethod->document()->toPlainText());
        modified = true;
    }

    ui->cmdSave->setEnabled(modified);

    if ((!data.modified) && modified)
        data.modified = modified;

}

void DlgTemplates::templatesModified() {
    refreshTemplates();
}

void DlgTemplates::refreshTemplates() {
    templates = mngr->loadTemplates();
    ui->cboTemplate->clear();

    foreach(TemplateDTO *dto, templates)
        ui->cboTemplate->addItem(dto->getName(), dto->getId());

}
