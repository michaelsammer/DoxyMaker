#ifndef TEMPLATECONTENTDTO_H
#define TEMPLATECONTENTDTO_H

#include <QString>

class TemplateContentDTO {

public:
    TemplateContentDTO(int templId, int typeId, QString content);

    int getTemplId() const;
    void setTemplId(int value);

    int getTypeId() const;
    void setTypeId(int value);

    QString getContent() const;
    void setContent(const QString &value);

private:
    int templId;
    int typeId;
    QString content;

};

#endif // TEMPLATECONTENTDTO_H
