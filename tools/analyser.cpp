#include "analyser.h"

Analyser::Analyser(QString &content) {

    runAnalyse(content);

}

QList<Statement *> Analyser::getDocElements() const {
    return docElements;
}

void Analyser::runAnalyse(QString content) {
    int curRow = 0;
    int curLevel = 0;
    int docIdx = 0;

    QStringList rows = getRows(content);

    foreach (QString row, rows) {
        curRow++;
        QList<Statement *> lst = getStatements(row, docIdx, curRow, curLevel);
        docElements.append(lst);
        docIdx += row.size() + 1;
    }
}

QStringList Analyser::getRows(QString input) {
    QStringList retList;

    retList =  input.split(QRegExp("[\r\n]"), QString::KeepEmptyParts);

    foreach (QString s, retList)
        s = s.trimmed();

    return retList;
}

QList<Statement *> Analyser::getStatements(QString row, int docIdx, int rowCnt, int &level) {
    QList<Statement *> retList;

    QStringList elems = row.split(" ");

    Statement *stmt;

    for (int i = 0; i < elems.size(); i++) {
        QString elem = elems.at(i);

        if (elem == "{")
            level++;
        if ((elem == "}") || (elem == "};"))
            level--;

        if (elem == "enum") {
            QString name = elems.at(++i);
            if (isStatementValid(name)) {
                stmt = new Statement(rowCnt, docIdx, ENUM, name, level);
                retList.append(stmt);
            }
        }

        if (elem == "struct") {
            QString name = elems.at(++i);
            if (isStatementValid(name)) {
                stmt = new Statement(rowCnt, docIdx, STRUCT, name, level);
                retList.append(stmt);
            }
        }

        if (elem == "class") {
            QString name = elems.at(++i);
            if (isStatementValid(name)) {
                stmt = new Statement(rowCnt, docIdx, CLASS, name, level);
                retList.append(stmt);
            }
        }

    }

    return retList;
}

bool Analyser::isStatementValid(QString name) {
    return !(name.indexOf(';') >= 0);
}
