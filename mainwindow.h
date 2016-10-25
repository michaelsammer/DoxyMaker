#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QString>
#include <QStringList>
#include <QList>
#include <QFileInfo>
#include <QFileDialog>
#include <QTableWidgetItem>

#include "dlgsettings.h"
#include "data/db.h"
#include "data/templatedto.h"
#include "mdi/mditextchild.h"
#include "tools/templatemngr.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void open();
    void save();
    void comment();
    void settings();

    MdiTextChild *createMdiChild();

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::MainWindow *ui;
    DlgSettings *dlgSettings;

    MdiTextChild *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);

    TemplateMngr *tmplMngr;

    void refreshTemplates();
    void updateDocList();

};

#endif // MAINWINDOW_H
