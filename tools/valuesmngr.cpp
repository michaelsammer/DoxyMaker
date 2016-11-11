#include "valuesmngr.h"

ValuesMngr::ValuesMngr() {

    dao = new ValuesDAO();

    QList<ValuesDTO *> vals = dao->findAll();
    foreach(ValuesDTO *val, vals)
        values.insert(val->getName(), val);

}

QString ValuesMngr::getTextFor(QString key) {
    if (values.contains(key)) {
        return values.value(key)->getValue();
    } else
        return QString();
}

QList<ValuesDTO *> ValuesMngr::getValues() {
    return values.values();
}

void ValuesMngr::saveValue(ValuesDTO *val) {
    bool upd = (val->getId() > 0);

    dao->save(*val);

    if (upd)
        values.remove(val->getName());
    values.insert(val->getName(), val);

}

void ValuesMngr::deleteValue(ValuesDTO *dto) {
    dao->remove(dto->getId());

    values.remove(dto->getName());
}

void ValuesMngr::fillPlaceholders(QString &content) {
    // TODO fill placeholders
}
