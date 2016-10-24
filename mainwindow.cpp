#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), dlgSettings(Q_NULLPTR) {
    ui->setupUi(this);

    db::connect();

    tmplMngr = new TemplateMngr();
    refreshTemplates();

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::open() {
    QFileDialog dlg(this, QString(), QString(), "Header files(*.h)");
    dlg.setFileMode(QFileDialog::ExistingFiles);

    QStringList fileNames;
    if (dlg.exec())
        fileNames = dlg.selectedFiles();

    foreach (QString fileName, fileNames) {
        if (!fileName.isEmpty()) {
            QMdiSubWindow *existing = findMdiChild(fileName);
            if (existing) {
                ui->mdiArea->setActiveSubWindow(existing);
                return;
            }

            MdiTextChild *child = createMdiChild();
            if (child->loadFile(fileName)) {
                updateDocList();

                statusBar()->showMessage(tr("File loaded"), 2000);
                child->show();
            } else {
                child->close();
            }
        }
    }
}

void MainWindow::save() {
    if (activeMdiChild() && activeMdiChild()->save())
        statusBar()->showMessage(tr("File saved"), 2000);
}

void MainWindow::comment() {
//    activeMdiChild()->writeHeader("This is a test for a commecnt.\nNow a line break should be done.");
    QString name = qgetenv("USER");
    if (name.isEmpty())
        name = qgetenv("USERNAME");

    qDebug() << QString("Username: %1").arg(name);
}

void MainWindow::settings() {
    if (dlgSettings == Q_NULLPTR)
        dlgSettings = new DlgSettings(this);

    dlgSettings->show();
}

void MainWindow::valuesChanged(QTableWidgetItem *item) {
    int row = item->row() + 1;

    if (row == ui->tblValues->rowCount()) {
        if ((ui->tblValues->item(item->row(), 0) != NULL)
         && (ui->tblValues->item(item->row(), 1) != NULL))
            ui->tblValues->setRowCount(row + 1);
    }
}

MdiTextChild *MainWindow::createMdiChild() {
    MdiTextChild *child = new MdiTextChild();
    ui->mdiArea->addSubWindow(child);

    return child;
}

void MainWindow::closeEvent(QCloseEvent *) {
    // nop
}

MdiTextChild *MainWindow::activeMdiChild() {
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiTextChild *>(activeSubWindow->widget());
    return Q_NULLPTR;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName) {
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

   foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
       MdiTextChild *mdiChild = qobject_cast<MdiTextChild *>(window->widget());
       if (mdiChild->currentFile() == canonicalFilePath)
           return window;
   }
   return Q_NULLPTR;
}

void MainWindow::refreshTemplates() {
    QList<TemplateDTO*> tmpls = tmplMngr->loadTemplates();

    foreach(TemplateDTO *tmpl, tmpls)
        ui->cboTemplate->addItem(tmpl->getName(), tmpl->getId());

}

void MainWindow::updateDocList() {
    ui->lstDocs->clear();
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiTextChild *mdiChild = qobject_cast<MdiTextChild *>(window->widget());
        ui->lstDocs->addItem(mdiChild->userFriendlyCurrentFile());
    }
}
