#include "valuesmngr.h"

ValuesMngr::ValuesMngr() {

    dao = new ValuesDAO();

    QList<ValuesDTO> vals = dao->findAll();
    foreach(ValuesDTO val, vals)
        values.insert(val.getName(), &val);

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

void ValuesMngr::saveValues(QList<ValuesDTO> vals) {
    dao->saveAll(vals);
}
