#include "templatedao.h"

TemplateDAO::TemplateDAO() {

}

TemplateDTO *TemplateDAO::findTemplateById(int id) {
    TemplateDTO *dto;

    QSqlQuery sql;
    sql.prepare("SELECT name, description FROM template WHERE id = :id");
    sql.bindValue(":id", id);
    sql.exec();

    if (sql.next())
        dto = new TemplateDTO(id, sql.value(0).toString(), sql.value(1).toString());
    else
        dto = NULL;

    return dto;
}

QList<TemplateDTO *> TemplateDAO::findAllTemplates() {
    QList<TemplateDTO *> ret;

    QSqlQuery sql;
    sql.prepare("SELECT id, name, description FROM template");
    sql.exec();

    while (sql.next())
        ret.append(new TemplateDTO(sql.value(0).toInt(), sql.value(1).toString(), sql.value(2).toString()));

    return ret;
}

void TemplateDAO::saveTemplate(TemplateDTO &dto)
{

}

void TemplateDAO::removeTemplate(TemplateDTO dto)
{

}

TemplateContentDTO *TemplateDAO::findContentById(int templId, TemplateType type) {
    TemplateContentDTO *dto;

    QSqlQuery sql;
    sql.prepare("SELECT content FROM template_content WHERE templ_id = :templ_id AND type_id = :type_id");
    sql.bindValue(":templ_id", templId);
    sql.bindValue(":type_id", (int)type);
    sql.exec();

    if (sql.next())
        dto = new TemplateContentDTO(templId, (int)type, sql.value(0).toString());
    else
        dto = NULL;

    return dto;
}

QList<TemplateContentDTO *> TemplateDAO::findContentsForTemplate(int templId) {
    QList<TemplateContentDTO *> ret;

    QSqlQuery sql;
    sql.prepare("SELECT type_id, content FROM template_content WHERE templ_id = :templ_id");
    sql.bindValue(":templ_id", templId);
    sql.exec();

    while (sql.next())
        ret.append(new TemplateContentDTO(templId, sql.value(0).toInt(), sql.value(1).toString()));

    return ret;
}

void TemplateDAO::saveTemplateContent(TemplateContentDTO &dto)
{

}

void TemplateDAO::removeTemplateContent(TemplateContentDTO dto)
{

}
