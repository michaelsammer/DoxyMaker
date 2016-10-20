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

void TemplateDAO::saveTemplate(TemplateDTO &dto) {
    if (dto.getId() <= 0) {
        QSqlQuery ins;

        ins.prepare("INSERT INTO template (id, name, description) VALUES (NULL, :name, :desc)");
        ins.bindValue(":name", dto.getName());
        ins.bindValue(":desc", dto.getDesc());
        ins.exec();

        dto.setId(ins.lastInsertId().toInt());
    } else {
        QSqlQuery upd;

        upd.prepare("UPDATE template SET name = :name, description = :desc WHERE id = :id");
        upd.bindValue(":name", dto.getName());
        upd.bindValue(":desc", dto.getDesc());
        upd.bindValue(":id", dto.getId());
        upd.exec();
    }
}

void TemplateDAO::removeTemplate(int tmplId) {
    QSqlQuery del;

    // first remove any content
    removeContentForTemplate(tmplId);

    del.prepare("DELETE FROM template WHERE id = :id");
    del.bindValue(":id", tmplId);

    del.exec();
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

void TemplateDAO::saveTemplateContent(TemplateContentDTO &dto) {
    QSqlQuery sql;

    if (findContentById(dto.getTemplId(),(TemplateType)dto.getTypeId()) == NULL)
        sql.prepare("INSERT INTO template_content (templ_id, type_id, content) VALUES (:templ_id, :type_id, :content)");
    else
        sql.prepare("UPDATE template_content SET content = :content WHERE templ_id = :templ_id AND type_id = :type_id");

    sql.bindValue(":templ_id", dto.getTemplId());
    sql.bindValue(":type_id", dto.getTypeId());
    sql.bindValue(":content", dto.getContent());
    sql.exec();
}

void TemplateDAO::removeTemplateContent(TemplateContentDTO dto) {
    QSqlQuery del;

    del.prepare("DELETE FROM template_content WHERE templ_id = :templ_id AND type_id = :type_id");
    del.bindValue(":templ_id", dto.getTemplId());
    del.bindValue(":type_id", dto.getTypeId());

    del.exec();
}

void TemplateDAO::removeContentForTemplate(int tmplId) {
    QSqlQuery del;

    del.prepare("DELETE FROM template_content WHERE templ_id = :templ_id");
    del.bindValue(":templ_id", tmplId);

    del.exec();
}
