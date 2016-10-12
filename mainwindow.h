#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QString>
#include <QStringList>
#include <QFileInfo>
#include <QFileDialog>

#include "mdi/mditextchild.h"
#include "dlgtemplates.h"

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

private:
    Ui::MainWindow *ui;
    DlgTemplates *dlgTemplates;

    MdiTextChild *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);

    void updateDocList();
};

#endif // MAINWINDOW_H
