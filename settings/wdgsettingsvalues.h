#ifndef WDGSETTINGSVALUES_H
#define WDGSETTINGSVALUES_H

#include <QWidget>
#include <QList>
#include <QString>

#include "data/valuesdto.h"
#include "tools/valuesmngr.h"

namespace Ui {
class WdgSettingsValues;
}

class WdgSettingsValues : public QWidget {
    Q_OBJECT

public:
    explicit WdgSettingsValues(QWidget *parent = 0);
    ~WdgSettingsValues();

public slots:
    void addValue();
    void saveValue();
    void removeValue();
    void selectionChanged();

private:
    Ui::WdgSettingsValues *ui;

    ValuesMngr *mngr;

    QList<ValuesDTO *> data;

    void refresh();
};

#endif // WDGSETTINGSVALUES_H
