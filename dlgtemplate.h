#ifndef DLGTEMPLATE_H
#define DLGTEMPLATE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

#include "data/templatedto.h"
#include "tools/templatemngr.h"

namespace Ui {
class DlgTemplate;
}

class DlgTemplate : public QDialog {
    Q_OBJECT

public:
    DlgTemplate(QWidget *parent = 0);
    ~DlgTemplate();

    void setTemplate(TemplateDTO *templ = 0);

signals:
    void templateChanged();

public slots:
    void save();

private:
    Ui::DlgTemplate *ui;
    TemplateDTO *templ;

    TemplateMngr *mngr;
};

#endif // DLGTEMPLATE_H
