#ifndef DB_H
#define DB_H

#include <QApplication>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QMapIterator>

class db {

public:
    static bool connect();
    static int getLastId(QSqlQuery &query);
    static QString getLastExecutedQuery(const QSqlQuery& query);

};

#endif // DB_H
