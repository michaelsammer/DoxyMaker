#include "mditextchild.h"

#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QFont>
#include <QCloseEvent>
#include <QMessageBox>
#include <QTextStream>

#include <QDebug>

MdiTextChild::MdiTextChild() {
    setAttribute(Qt::WA_DeleteOnClose);
    setOverwriteMode(true);

}

bool MdiTextChild::loadFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QString text = in.readAll();
    setPlainText(text);
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    Analyser ana(text);
    statements = ana.getDocElements();

    qDebug() << QString("%1 statements found").arg(statements.size());
    foreach(Statement *s, statements) {
        QString type;
        if (s->getType() == ENUM) type = "enum";
        if (s->getType() == STRUCT) type = "struct";
        if (s->getType() == CLASS) type = "class";
        qDebug() << QString("%1 %2 (%3) in row %4").arg(type).arg(s->getName()).arg(s->getLevel()).arg(s->getRow());
    }

    return true;
}

bool MdiTextChild::save() {
    return saveFile(curFile);
}

bool MdiTextChild::saveFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}

void MdiTextChild::writeHeader(QString header) {
    QColor cl = textColor();
    setTextColor(Qt::darkGreen);
    QString font = fontFamily();
    qDebug() << font;
    setFontFamily("Courier");

    QTextCursor cursor = textCursor();
    cursor.setPosition(0);
    cursor.insertText(header);

    setTextColor(cl);
    setFontFamily(font);
}

QString MdiTextChild::userFriendlyCurrentFile() {
    return strippedName(curFile);
}

QString MdiTextChild::currentFile() {
    return curFile;
}

void MdiTextChild::closeEvent(QCloseEvent *event) {
    if (maybeSave())
        event->accept();
    else
        event->ignore();
}

void MdiTextChild::documentWasModified() {
    setWindowModified(document()->isModified());
}

bool MdiTextChild::maybeSave() {
    if (document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("MDI"),
                     tr("'%1' has been modified.\n"
                        "Do you want to save your changes?")
                     .arg(userFriendlyCurrentFile()),
                     QMessageBox::Save | QMessageBox::Discard
                     | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MdiTextChild::setCurrentFile(const QString &fileName) {
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QString MdiTextChild::strippedName(const QString &fullFileName) {
    return QFileInfo(fullFileName).fileName();
}


