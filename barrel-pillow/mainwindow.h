#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include "ControllerXML.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
   void slot1();
   void openImage();
   void doMagic();

private:
    void clearScene();
    Ui::MainWindow *ui;
    ControllerXML *a;
    QImage image;
    QGraphicsScene scene;
};

#endif // MAINWINDOW_H
