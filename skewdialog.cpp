#include "skewdialog.h"
#include "ui_skewdialog.h"


////////////////////////////////////////////////////////////////////////////////////////////////
skewdialog::skewdialog(QImage* img, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::skewdialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

tmp = img->scaled(QSize(200,200),Qt::KeepAspectRatio);
    simg = new Skew();
  scene->addPixmap(QPixmap::fromImage(tmp));
  ui->graphicsView->setScene(scene);
  angleX=0;
  angleY=0;

}

////////////////////////////////////////////////////////////////////////////////////////////////
skewdialog::~skewdialog()
{
    delete ui;
    delete simg;
    delete scene;
}

////////////////////////////////////////////////////////////////////////////////////////////////
void skewdialog::changeEvent(QEvent *e)
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
void skewdialog::on_dial_valueChanged(int value)
{
    clearScene();

   // tmp=;

    scene->addPixmap(QPixmap::fromImage(simg->skewImageTwo(&tmp,value,angleY)));
     ui->graphicsView->setScene(scene);
     angleX = value;

}

////////////////////////////////////////////////////////////////////////////////////////////////
void skewdialog::on_dial_2_valueChanged(int value)
{
      clearScene();
   // tmp=;
    scene->addPixmap(QPixmap::fromImage(simg->skewImageTwo(&tmp,angleX,value)));
     ui->graphicsView->setScene(scene);
     angleY = value;
}

////////////////////////////////////////////////////////////////////////////////////////////////
void skewdialog::on_pushButton_2_clicked()
{
    close();
    emit CloseSignalOK(this->angleX, this->angleY);

}

////////////////////////////////////////////////////////////////////////////////////////////////
void skewdialog::clearScene(){

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

////////////////////////////////////////////////////////////////////////////////////////////////
void skewdialog::on_pushButton_clicked()
{
    emit CloseSignalCancel();
}
