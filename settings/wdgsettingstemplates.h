#ifndef WDGSETTINGSTEMPLATES_H
#define WDGSETTINGSTEMPLATES_H

#include <QWidget>
#include <QTextEdit>
#include <QMessageBox>

#include "settings/dlgtemplate.h"
#include "tools/templatemngr.h"

namespace Ui {
class WdgSettingsTemplates;
}

class WdgSettingsTemplates : public QWidget {
    Q_OBJECT

public:
    explicit WdgSettingsTemplates(QWidget *parent = 0);
    ~WdgSettingsTemplates();

public slots:
    void addTemplate();
    void removeTemplate();
    void saveTemplate();
    void editTemplate();
    void templateIdxChanged(int idx);

    void contentChanged();

    void templatesModified();

private:
    Ui::WdgSettingsTemplates *ui;
    DlgTemplate *dlgTemplate;

    TemplateMngr *mngr;

    QList<TemplateDTO *> templates;
    TemplateData data;
    int curTmplId;

    void refreshTemplates();
    void writeContent(TemplateType type, QTextEdit *txt);
    bool checkChangedContent(TemplateType type, QTextEdit *txt);

};

#endif // WDGSETTINGSTEMPLATES_H
