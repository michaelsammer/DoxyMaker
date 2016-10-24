#include "valuesdto.h"

ValuesDTO::ValuesDTO(QString name, QString value, QString desc) {
    this->id = -1;
    this->name = name;
    this->value = value;
    this->desc = desc;
}

ValuesDTO::ValuesDTO(int id, QString name, QString value, QString desc) {
    this->id = id;
    this->name = name;
    this->value = value;
    this->desc = desc;
}

int ValuesDTO::getId() const {
    return id;
}

void ValuesDTO::setId(int value) {
    this->id = value;
}

QString ValuesDTO::getName() const {
    return name;
}

void ValuesDTO::setName(const QString &value) {
    this->name = value;
}

QString ValuesDTO::getValue() const {
    return value;
}

void ValuesDTO::setValue(const QString &value) {
    this->value = value;
}

QString ValuesDTO::getDesc() const {
    return desc;
}

void ValuesDTO::setDesc(const QString &value) {
    this->desc = value;
}
