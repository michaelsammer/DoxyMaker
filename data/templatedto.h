#ifndef TEMPLATEDTO_H
#define TEMPLATEDTO_H

#include <QString>

class TemplateDTO {

public:
    TemplateDTO(QString name, QString desc);
    TemplateDTO(int id, QString name, QString desc);

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getDesc() const;
    void setDesc(const QString &value);

private:
    int id;
    QString name;
    QString desc;

};

#endif // TEMPLATEDTO_H
