#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "axisrotate.h"
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    image = new QImage("../bieg.jpg");

    ar = new AxisRotate(*image,400,400);

    scene = new QGraphicsScene();

    connect(ui->hSlider,SIGNAL(valueChanged(int)),this,SLOT(setXAxis(int)));
    connect(ui->hSlider2,SIGNAL(valueChanged(int)),this,SLOT(setYAxis(int)));
    connect(ui->hSlider3,SIGNAL(valueChanged(int)),this,SLOT(setZAxis(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    if(ar != NULL) {
        delete ar;
        ar = NULL;
    }
    if(scene != NULL) {
        delete scene;
        scene = NULL;
    }
    if(image != NULL) {
        delete image;
        image = NULL;
    }
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::setXAxis(int x) {
QImage *rotatedImage = ar->setX(x);
scene->clear();
ui->graphicsView->setScene(scene);

scene->addPixmap(QPixmap::fromImage(*rotatedImage));
ui->graphicsView->setScene(scene);
}

void MainWindow::setYAxis(int y) {
QImage *rotatedImage = ar->setY(y);
ar->setY(y);
scene->clear();
ui->graphicsView->setScene(scene);
scene->addPixmap(QPixmap::fromImage(*rotatedImage));
ui->graphicsView->setScene(scene);
}

void MainWindow::setZAxis(int z) {
QImage *rotatedImage = ar->setZ(z);
    ar->setZ(z);
scene->clear();
ui->graphicsView->setScene(scene);
scene->addPixmap(QPixmap::fromImage(*rotatedImage));
ui->graphicsView->setScene(scene);
}
