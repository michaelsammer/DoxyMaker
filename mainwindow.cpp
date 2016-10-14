#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), dlgTemplates(Q_NULLPTR) {
    ui->setupUi(this);

    db::connect();
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
    activeMdiChild()->writeHeader("This is a test for a commecnt.\nNow a line break should be done.");
}

void MainWindow::settings() {
    if (dlgTemplates == Q_NULLPTR)
        dlgTemplates = new DlgTemplates(this);

    dlgTemplates->show();
}

MdiTextChild *MainWindow::createMdiChild() {
    MdiTextChild *child = new MdiTextChild();
    ui->mdiArea->addSubWindow(child);

    return child;
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

void MainWindow::updateDocList() {
    ui->lstDocs->clear();
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiTextChild *mdiChild = qobject_cast<MdiTextChild *>(window->widget());
        ui->lstDocs->addItem(mdiChild->userFriendlyCurrentFile());
    }
}
