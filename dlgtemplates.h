#ifndef DLGTEMPLATES_H
#define DLGTEMPLATES_H

#include <QDialog>

namespace Ui {
class DlgTemplates;
}

class DlgTemplates : public QDialog
{
    Q_OBJECT

public:
    explicit DlgTemplates(QWidget *parent = 0);
    ~DlgTemplates();

private:
    Ui::DlgTemplates *ui;
};

#endif // DLGTEMPLATES_H
