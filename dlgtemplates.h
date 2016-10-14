#ifndef DLGTEMPLATES_H
#define DLGTEMPLATES_H

#include <QDialog>

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
    void templateChanged(int idx);

private:
    Ui::DlgTemplates *ui;
    DlgTemplate *dlgTemplate;

    TemplateMngr *mngr;

    QList<TemplateDTO *> templates;
    TemplateData data;

    void refreshTemplates();

};

#endif // DLGTEMPLATES_H
