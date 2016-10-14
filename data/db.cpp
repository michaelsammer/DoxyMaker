#include "db.h"

#include <QDebug>

bool db::connect() {
    QString path = qApp->applicationDirPath();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    path.append("/dm.db");
    db.setDatabaseName(path);

    if (!db.open())
        return false;

    return true;
}

int db::getLastId(QSqlQuery &query) {
    QString sql("SELECT LAST_INSERT_ID()");
    query.prepare(sql);
    query.exec();

    if (query.next())
        return query.value(0).toInt();
    else
        return 0;
}

QString db::getLastExecutedQuery(const QSqlQuery& query) {
    QString str = query.lastQuery();
    QMapIterator<QString, QVariant> it(query.boundValues());

    it.toBack();

    while (it.hasPrevious())
    {
        it.previous();
        str.replace(it.key(),it.value().toString());
    }
    return str;
}
