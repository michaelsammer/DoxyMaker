#ifndef MDITEXTCHILD_H
#define MDITEXTCHILD_H

#include <QObject>
#include <QString>
#include <QTextEdit>
#include <QList>

#include "tools/analyser.h"
#include "tools/valuesmngr.h"

class MdiTextChild : public QTextEdit {
    Q_OBJECT

public:
    MdiTextChild();

    bool loadFile(const QString &fileName);
    bool save();
    bool saveFile(const QString &fileName);

    void writeHeader(QString header);
    void writeClass(ValuesMngr *valMngr, QString content);

    QString userFriendlyCurrentFile();
    QString currentFile();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();

private:
    Analyser *analyser;
    QList<Statement *> statements;

    QString curFile;
    bool isUntitled;

    void writeTextAt(QString text, int idx);

    bool maybeSave();
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

};

#endif // MDITEXTCHILD_H
