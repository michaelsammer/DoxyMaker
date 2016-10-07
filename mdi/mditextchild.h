#ifndef MDITEXTCHILD_H
#define MDITEXTCHILD_H

#include <QObject>
#include <QString>
#include <QTextEdit>

class MdiTextChild : public QTextEdit {
    Q_OBJECT

public:
    MdiTextChild();

    bool loadFile(const QString &fileName);
    bool save();
    bool saveFile(const QString &fileName);

    void writeHeader(QString header);

    QString userFriendlyCurrentFile();
    QString currentFile();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void documentWasModified();

private:
    bool maybeSave();
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QString curFile;
    bool isUntitled;
};

#endif // MDITEXTCHILD_H