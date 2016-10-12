#include "statement.h"

Statement::Statement(int row, StatementType type, QString name, int level) {
    this->row = row;
    this->type = type;
    this->name = name;
    this->level = level;
}

int Statement::getRow() const {
    return row;
}

void Statement::setRow(int value)
{
    row = value;
}

StatementType Statement::getType() const
{
    return type;
}

void Statement::setType(const StatementType &value)
{
    type = value;
}

QString Statement::getName() const
{
    return name;
}

void Statement::setName(const QString &value)
{
    name = value;
}

int Statement::getLevel() const
{
    return level;
}

void Statement::setLevel(int value)
{
    level = value;
}
