#ifndef DLGTEMPLATE_H
#define DLGTEMPLATE_H

#include <QDialog>

#include "data/templatedto.h"

namespace Ui {
class DlgTemplate;
}

class DlgTemplate : public QDialog {
    Q_OBJECT

public:
    DlgTemplate(QWidget *parent = 0);
    ~DlgTemplate();

    void setTemplate(TemplateDTO *templ = 0);

public slots:
    void save();

private:
    Ui::DlgTemplate *ui;
    TemplateDTO *templ;

};

#endif // DLGTEMPLATE_H
