#include "valuesdao.h"

ValuesDAO::ValuesDAO() {
    // nop
}

QList<ValuesDTO> ValuesDAO::findAll() {
    QList<ValuesDTO> ret;

    QSqlQuery sql;
    sql.prepare("SELECT id, name, value, desc FROM filler");
    sql.exec();

    while (sql.next())
        ret.append(ValuesDTO(sql.value(0).toInt(), sql.value(1).toString(), sql.value(2).toString(), sql.value(3).toString()));

    return ret;
}

void ValuesDAO::save(ValuesDTO &value) {
    if (value.getId() <= 0) {
        QSqlQuery ins;
        ins.prepare("INSERT INTO filler (id, name, value, desc) VALUES (NULL, :name, :value, :desc)");
        ins.bindValue(":name", value.getName());
        ins.bindValue(":value", value.getValue());
        ins.bindValue(":desc", value.getDesc());
        ins.exec();

        value.setId(ins.lastInsertId().toInt());
    } else {
        QSqlQuery upd;
        upd.prepare("UPDATE filler SET name = :name, value = :value, desc = :desc WHERE id = :id");
        upd.bindValue(":id", value.getId());
        upd.bindValue(":name", value.getName());
        upd.bindValue(":value", value.getValue());
        upd.bindValue(":desc", value.getDesc());
        upd.exec();
    }
}

void ValuesDAO::saveAll(QList<ValuesDTO> values) {
    for (int i = 0; i < values.size(); i++) {
        ValuesDTO dto = values.at(i);
        save(dto);
    }
}
