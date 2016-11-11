#ifndef VALUESMNGR_H
#define VALUESMNGR_H

#include <QString>
#include <QList>
#include <QMap>

#include <data/valuesdto.h>
#include <data/valuesdao.h>

class ValuesMngr {
public:
    ValuesMngr();

    QString getTextFor(QString key);
    QList<ValuesDTO *> getValues();
    void saveValue(ValuesDTO *val);
    void deleteValue(ValuesDTO *dto);

    void fillPlaceholders(QString &content);

private:
    ValuesDAO *dao;
    QMap<QString, ValuesDTO *> values;

};

#endif // VALUESMNGR_H
