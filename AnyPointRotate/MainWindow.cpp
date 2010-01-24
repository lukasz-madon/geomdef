#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPixmap>
#include <QImage>
#include <QGraphicsScene>

#include "RotateImage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = new QImage("../bieg.jpg");

    rot = new RotateImage(*image);

    scene = new QGraphicsScene();

    connect(ui->dial,SIGNAL(valueChanged(int)),this,SLOT(dialSlot(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::dialSlot(int value) {

   const QImage *rotatedImage = rot->rotateAnyPoint(value,0,0,ui->graphicsView->width()-10,ui->graphicsView->height()-10);
   // const QImage *rotatedImage = rot->rotateCutBackground(value);
   scene->clear();
    ui->graphicsView->setScene(scene);
    scene->addPixmap(QPixmap::fromImage(*rotatedImage));
    ui->graphicsView->setScene(scene);

}
