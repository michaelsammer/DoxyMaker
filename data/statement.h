#ifndef STATEMENT_H
#define STATEMENT_H

#include <QString>

enum StatementType {
    USING,
    NAMESPACE,
    ENUM,
    STRUCT,
    CLASS
};

class Statement {

public:
    Statement(int row, StatementType type, QString name, int level);

    int getRow() const;
    void setRow(int value);

    StatementType getType() const;
    void setType(const StatementType &value);

    QString getName() const;
    void setName(const QString &value);

    int getLevel() const;
    void setLevel(int value);

private:
    int row;
    StatementType type;
    QString name;
    int level;

};

#endif // STATEMENT_H
