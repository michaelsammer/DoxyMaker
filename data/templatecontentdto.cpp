#include "templatecontentdto.h"

TemplateContentDTO::TemplateContentDTO(int templId, int typeId, QString content) {
    this->templId = templId;
    this->typeId = typeId;
    this->content = content;
}

int TemplateContentDTO::getTypeId() const {
    return typeId;
}

void TemplateContentDTO::setTypeId(int value) {
    typeId = value;
}

QString TemplateContentDTO::getContent() const {
    return content;
}

void TemplateContentDTO::setContent(const QString &value) {
    content = value;
}

int TemplateContentDTO::getTemplId() const {
    return templId;
}

void TemplateContentDTO::setTemplId(int value) {
    templId = value;
}
