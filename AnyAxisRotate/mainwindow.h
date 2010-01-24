#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class AxisRotate;
class QGraphicsScene;
class QImage;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    AxisRotate *ar;

      QGraphicsScene *scene;
      QImage *image;

private slots:
    void setXAxis(int);
    void setYAxis(int);
    void setZAxis(int);
};

#endif // MAINWINDOW_H
