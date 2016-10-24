#include "wdgsettingstemplates.h"
#include "ui_wdgsettingstemplates.h"

WdgSettingsTemplates::WdgSettingsTemplates(QWidget *parent) :
    QWidget(parent), ui(new Ui::WdgSettingsTemplates) {
    ui->setupUi(this);

    dlgTemplate = new DlgTemplate(this);
    connect(dlgTemplate, SIGNAL(templateChanged()), this, SLOT(templatesModified()));

    // load templates
    mngr = new TemplateMngr();
    refreshTemplates();
}

WdgSettingsTemplates::~WdgSettingsTemplates() {
    delete ui;
}

void WdgSettingsTemplates::addTemplate() {
    dlgTemplate->setTemplate();
    dlgTemplate->show();
}

void WdgSettingsTemplates::removeTemplate() {
    QString msg = QString("Do you realy want to remove template %1?").arg(ui->cboTemplate->currentText());
    if (QMessageBox::question(this, "Remove template", msg) == QMessageBox::Yes) {
        mngr->deleteTemplate(ui->cboTemplate->currentData().toInt());
        refreshTemplates();
    }
}

void WdgSettingsTemplates::saveTemplate() {
    mngr->saveContent(data);

    // set back all document modified states
    ui->txtHeader->document()->setModified(false);
    ui->txtEnum->document()->setModified(false);
    ui->txtStruct->document()->setModified(false);
    ui->txtClass->document()->setModified(false);
    ui->txtMethod->document()->setModified(false);
}

void WdgSettingsTemplates::editTemplate() {
    int id = ui->cboTemplate->currentData().toInt();
    TemplateDTO *templ = mngr->getTemplate(id);

    dlgTemplate->setTemplate(templ);
    dlgTemplate->show();
}

void WdgSettingsTemplates::templateIdxChanged(int idx) {
    curTmplId = ui->cboTemplate->currentData().toInt();

    data = mngr->loadTemplateContent(curTmplId);

    writeContent(TEMPLATE_TYPE_HEADER, ui->txtHeader);
    writeContent(TEMPLATE_TYPE_ENUM, ui->txtEnum);
    writeContent(TEMPLATE_TYPE_STRUCT, ui->txtStruct);
    writeContent(TEMPLATE_TYPE_CLASS, ui->txtClass);
    writeContent(TEMPLATE_TYPE_METHOD, ui->txtMethod);

}

void WdgSettingsTemplates::contentChanged() {
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

void WdgSettingsTemplates::templatesModified() {
    refreshTemplates();
}

void WdgSettingsTemplates::refreshTemplates() {
    templates = mngr->loadTemplates();
    ui->cboTemplate->clear();

    foreach(TemplateDTO *dto, templates)
        ui->cboTemplate->addItem(dto->getName(), dto->getId());

}

void WdgSettingsTemplates::writeContent(TemplateType type, QTextEdit *txt) {
    if (data.content.contains(type))
        txt->setText(data.content.value(type)->getContent());
    else
        txt->setText("");
}

bool WdgSettingsTemplates::checkChangedContent(TemplateType type, QTextEdit *txt) {
    if (txt->document()->isModified()) {
        if (!data.content.contains(type))
            data.content.insert(type, new TemplateContentDTO(curTmplId, (int)type, txt->document()->toPlainText()));
        else
            data.content.value(type)->setContent(txt->document()->toPlainText());
        return true;
    }
    return false;
}
