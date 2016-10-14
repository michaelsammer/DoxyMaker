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

void TemplateMngr::addTemplate(QString name, QString desc)
{

}

void TemplateMngr::saveTemplate(TemplateDTO dto)
{

}

void TemplateMngr::deleteTemplate(TemplateDTO dto)
{

}

void TemplateMngr::saveContent(TemplateData content)
{

}
