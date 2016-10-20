#include "templatedto.h"

TemplateDTO::TemplateDTO(QString name, QString desc) {
    this->id = -1;
    this->name = name;
    this->desc = desc;
}

TemplateDTO::TemplateDTO(int id, QString name, QString desc) {
    this->id = id;
    this->name = name;
    this->desc = desc;
}

int TemplateDTO::getId() const {
    return id;
}

void TemplateDTO::setId(int value) {
    id = value;
}

QString TemplateDTO::getName() const {
    return name;
}

void TemplateDTO::setName(const QString &value) {
    name = value;
}

QString TemplateDTO::getDesc() const {
    return desc;
}

void TemplateDTO::setDesc(const QString &value) {
    desc = value;
}
