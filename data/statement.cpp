#include "statement.h"

Statement::Statement(int row, int docIdx, StatementType type, QString name, int level) {
    this->row = row;
    this->docIdx = docIdx;
    this->type = type;
    this->name = name;
    this->level = level;
}

int Statement::getRow() const {
    return row;
}

void Statement::setRow(int value) {
    row = value;
}

int Statement::getDocIdx() const {
    return docIdx;
}

void Statement::setDocIdx(int value) {
    docIdx = value;
}

StatementType Statement::getType() const {
    return type;
}

void Statement::setType(const StatementType &value) {
    type = value;
}

QString Statement::getName() const {
    return name;
}

void Statement::setName(const QString &value) {
    name = value;
}

int Statement::getLevel() const {
    return level;
}

void Statement::setLevel(int value) {
    level = value;
}
