#ifndef TEMPLATEDAO_H
#define TEMPLATEDAO_H

#include <QString>
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "data/db.h"
#include "data/templatedto.h"
#include "data/templatecontentdto.h"

enum TemplateType {
    TEMPLATE_TYPE_HEADER = 1,
    TEMPLATE_TYPE_ENUM,
    TEMPLATE_TYPE_STRUCT,
    TEMPLATE_TYPE_CLASS,
    TEMPLATE_TYPE_METHOD,
    TEMPLATE_TYPE_VALUE
};

class TemplateDAO {

public:
    TemplateDAO();

    TemplateDTO *findTemplateById(int id);
    QList<TemplateDTO *> findAllTemplates();
    void saveTemplate(TemplateDTO &dto);
    void removeTemplate(int tmplId);

    TemplateContentDTO *findContentById(int templId, TemplateType type);
    QList<TemplateContentDTO *> findContentsForTemplate(int templId);
    void saveTemplateContent(TemplateContentDTO &dto);
    void removeTemplateContent(TemplateContentDTO dto);
    void removeContentForTemplate(int tmplId);

};

#endif // TEMPLATEDAO_H
