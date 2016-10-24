#ifndef VALUESDTO_H
#define VALUESDTO_H

#include <QString>

class ValuesDTO
{
public:
    ValuesDTO(QString name, QString value, QString desc);
    ValuesDTO(int id, QString name, QString value, QString desc);

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getValue() const;
    void setValue(const QString &value);

    QString getDesc() const;
    void setDesc(const QString &value);

private:
    int id;
    QString name;
    QString value;
    QString desc;

};

#endif // VALUESDTO_H
