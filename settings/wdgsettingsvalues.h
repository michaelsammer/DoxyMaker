#ifndef WDGSETTINGSVALUES_H
#define WDGSETTINGSVALUES_H

#include <QWidget>

namespace Ui {
class WdgSettingsValues;
}

class WdgSettingsValues : public QWidget
{
    Q_OBJECT

public:
    explicit WdgSettingsValues(QWidget *parent = 0);
    ~WdgSettingsValues();

private:
    Ui::WdgSettingsValues *ui;
};

#endif // WDGSETTINGSVALUES_H
