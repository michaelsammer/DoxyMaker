#ifndef DLGTEMPLATES_H
#define DLGTEMPLATES_H

#include <QDialog>
#include <QTextEdit>
#include <QMessageBox>

#include "dlgtemplate.h"
#include "tools/templatemngr.h"

namespace Ui {
class DlgTemplates;
}

class DlgTemplates : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTemplates(QWidget *parent = 0);
    ~DlgTemplates();

public slots:
    void addTemplate();
    void removeTemplate();
    void saveTemplate();
    void editTemplate();
    void templateIdxChanged(int idx);

    void contentChanged();

    void templatesModified();

private:
    Ui::DlgTemplates *ui;
    DlgTemplate *dlgTemplate;

    TemplateMngr *mngr;

    QList<TemplateDTO *> templates;
    TemplateData data;
    int curTmplId;

    void refreshTemplates();
    void writeContent(TemplateType type, QTextEdit *txt);
    bool checkChangedContent(TemplateType type, QTextEdit *txt);

};

#endif // DLGTEMPLATES_H
