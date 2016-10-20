#ifndef TemplateMngr_H
#define TemplateMngr_H

#include <QString>
#include <QList>
#include <QMap>

#include "data/templatedao.h"

struct TemplateData {
    QMap<TemplateType, TemplateContentDTO *> content;
    bool modified;
};

class TemplateMngr {

public:
    TemplateMngr();

    QList<TemplateDTO *> loadTemplates();
    TemplateDTO *getTemplate(int id);
    TemplateData loadTemplateContent(int templId);

    void addTemplate(QString name, QString desc);
    void saveTemplate(TemplateDTO &dto);
    void deleteTemplate(int tmplId);

    void saveContent(TemplateData content);

private:
    TemplateDAO *dao;

};

#endif // TemplateMngr_H
