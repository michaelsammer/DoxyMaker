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
        setPlainText(in.readAll());
        QApplication::restoreOverrideCursor();

        setCurrentFile(fileName);

        connect(document(), SIGNAL(contentsChanged()),
                this, SLOT(documentWasModified()));

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


