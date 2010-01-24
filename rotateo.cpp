#include "rotateo.h"
#include "ui_rotateo.h"
#include "rotate.h"
#include "ui_rotate.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "axisrotate.h"

#include <cmath>


////////////////////////////////////////////////////////////////////////////////////////////////
rotateo::rotateo(QImage* img, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rotateo)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    QImage tmp = img->scaled(QSize(200,200),Qt::KeepAspectRatio);
   int diagonal = sqrt( (tmp.height()*tmp.height()) + (tmp.width()*tmp.width()) );
  this->rimg = new AxisRotate(tmp,diagonal, diagonal);

  scene->addPixmap(QPixmap::fromImage(tmp));
    ui->graphicsView->setScene(scene);
  rimg->xp=0;
  rimg->zp=0;
  rimg->yp=0;

}

////////////////////////////////////////////////////////////////////////////////////////////////
rotateo::~rotateo()
{
    delete ui;
    delete rimg;
     delete scene;
}

////////////////////////////////////////////////////////////////////////////////////////////////
void rotateo::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
void rotateo::on_pushButton_clicked()
{
    close();
    emit CloseSignalCancel();
}

////////////////////////////////////////////////////////////////////////////////////////////////
void rotateo::on_dial_valueChanged(int value)
{
     clearScene();

    scene->addPixmap(QPixmap::fromImage(rimg->setX(value)));
     ui->graphicsView->setScene(scene);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void rotateo::on_dial_2_valueChanged(int value)
{
    clearScene();
    scene->addPixmap(QPixmap::fromImage(rimg->setY(value)));
     ui->graphicsView->setScene(scene);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void rotateo::on_dial_3_valueChanged(int value)
{
    clearScene();
    scene->addPixmap(QPixmap::fromImage(rimg->setZ(value)));
     ui->graphicsView->setScene(scene);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void rotateo::on_pushButton_3_clicked()
{

    close();
    emit CloseSignalOK(rimg->xp,rimg->yp, rimg->zp);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void rotateo::clearScene(){

    QList<QGraphicsItem *> list = scene->items();
           QList<QGraphicsItem *>::Iterator it = list.begin();
           for ( ; it != list.end(); ++it )
           {
                   if ( *it )
                   {
                           scene->removeItem(*it);
                           delete *it;
                   }
           }
delete scene;
scene = new QGraphicsScene();

}
