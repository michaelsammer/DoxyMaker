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
    QString msg = QString("Do you realy want to remove template %1?").arg(ui->cboTemplate->currentText());
    if (QMessageBox::question(this, "Remove template", msg) == QMessageBox::Yes) {
        mngr->deleteTemplate(ui->cboTemplate->currentData().toInt());
        refreshTemplates();
    }
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
    curTmplId = ui->cboTemplate->currentData().toInt();

    data = mngr->loadTemplateContent(curTmplId);

    writeContent(TEMPLATE_TYPE_HEADER, ui->txtHeader);
    writeContent(TEMPLATE_TYPE_ENUM, ui->txtEnum);
    writeContent(TEMPLATE_TYPE_STRUCT, ui->txtStruct);
    writeContent(TEMPLATE_TYPE_CLASS, ui->txtClass);
    writeContent(TEMPLATE_TYPE_METHOD, ui->txtMethod);

}

void DlgTemplates::contentChanged() {
    bool modified = false;

    modified = modified || checkChangedContent(TEMPLATE_TYPE_HEADER, ui->txtHeader);
    modified = modified || checkChangedContent(TEMPLATE_TYPE_ENUM, ui->txtEnum);
    modified = modified || checkChangedContent(TEMPLATE_TYPE_STRUCT, ui->txtStruct);
    modified = modified || checkChangedContent(TEMPLATE_TYPE_CLASS, ui->txtClass);
    modified = modified || checkChangedContent(TEMPLATE_TYPE_METHOD, ui->txtMethod);

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

void DlgTemplates::writeContent(TemplateType type, QTextEdit *txt) {
    if (data.content.contains(type))
        txt->setText(data.content.value(type)->getContent());
    else
        txt->setText("");
}

bool DlgTemplates::checkChangedContent(TemplateType type, QTextEdit *txt) {
    if (txt->document()->isModified()) {
        if (!data.content.contains(type))
            data.content.insert(type, new TemplateContentDTO(curTmplId, (int)type, txt->document()->toPlainText()));
        else
            data.content.value(type)->setContent(txt->document()->toPlainText());
        return true;
    }
    return false;
}
