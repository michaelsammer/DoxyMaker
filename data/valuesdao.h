#ifndef VALUESDAO_H
#define VALUESDAO_H

#include <QVariant>
#include <QString>
#include <QList>
#include <QSqlQuery>

#include "data/valuesdto.h"

class ValuesDAO {

public:
    ValuesDAO();

    QList<ValuesDTO *> findAll();
    void save(ValuesDTO &value);
    void saveAll(QList<ValuesDTO> values);
    void remove(int id);

};

#endif // VALUESDAO_H
