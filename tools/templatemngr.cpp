#include "templatemngr.h"

TemplateMngr::TemplateMngr() {

    dao = new TemplateDAO();
}

QList<TemplateDTO *> TemplateMngr::loadTemplates() {
    return dao->findAllTemplates();
}

TemplateDTO *TemplateMngr::getTemplate(int id) {
    return dao->findTemplateById(id);
}

TemplateData TemplateMngr::loadTemplateContent(int templId) {
    TemplateData data;

    QList<TemplateContentDTO *> lst = dao->findContentsForTemplate(templId);

    data.modified = false;
    foreach(TemplateContentDTO *cnt, lst) {
        TemplateType tt = (TemplateType)cnt->getTypeId();
        data.content.insert(tt, cnt);
    }

    return data;
}

void TemplateMngr::addTemplate(QString name, QString desc) {
    TemplateDTO *templ = new TemplateDTO(name, desc);
    dao->saveTemplate(templ);
}

void TemplateMngr::saveTemplate(TemplateDTO *dto) {
    dao->saveTemplate(dto);
}

void TemplateMngr::deleteTemplate(int tmplId) {

    dao->removeContentForTemplate(tmplId);

    dao->removeTemplate(tmplId);
}

void TemplateMngr::saveContent(TemplateData content) {

    if (content.modified) {
        dao->saveTemplateContent(content.content.value(TEMPLATE_TYPE_HEADER));
        dao->saveTemplateContent(content.content.value(TEMPLATE_TYPE_ENUM));
        dao->saveTemplateContent(content.content.value(TEMPLATE_TYPE_STRUCT));
        dao->saveTemplateContent(content.content.value(TEMPLATE_TYPE_CLASS));
        dao->saveTemplateContent(content.content.value(TEMPLATE_TYPE_METHOD));
        dao->saveTemplateContent(content.content.value(TEMPLATE_TYPE_VALUE));
    }

}
