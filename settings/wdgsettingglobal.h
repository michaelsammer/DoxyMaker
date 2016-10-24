#ifndef WDGSETTINGGLOBAL_H
#define WDGSETTINGGLOBAL_H

#include <QWidget>

namespace Ui {
class WdgSettingGlobal;
}

class WdgSettingGlobal : public QWidget
{
    Q_OBJECT

public:
    explicit WdgSettingGlobal(QWidget *parent = 0);
    ~WdgSettingGlobal();

private:
    Ui::WdgSettingGlobal *ui;
};

#endif // WDGSETTINGGLOBAL_H
