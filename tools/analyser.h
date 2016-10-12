#ifndef ANALYSER_H
#define ANALYSER_H

#include <QString>
#include <QStringList>
#include <QList>

#include "data/statement.h"

enum Classifier {
    PUBLIC,
    PROTECTED,
    PRIVATE
};

class Analyser {

public:
    Analyser(QString &content);

    QList<Statement *> getDocElements() const;

private:
    QList<Statement *> docElements;

    void runAnalyse(QString content);
    QStringList getRows(QString input);
    QList<Statement *> getStatements(QString row, int rowCnt, int &level);
    bool isStatementValid(QString name);
};

#endif // ANALYSER_H
