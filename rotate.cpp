#include "rotate.h"
#include "ui_rotate.h"
#include "RotateImage.h"

rotate::rotate(const QImage *img,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rotate)
{


    ui->setupUi(this);

    scene = new QGraphicsScene();
    scene->addPixmap(QPixmap::fromImage(img->scaled(QSize(200,200),Qt::KeepAspectRatio)));
    ui->graphicsView->setScene(scene);

    rimg = new RotateImage(img->scaled(QSize(200,200),Qt::KeepAspectRatio));

    connect(ui->dial,SIGNAL(valueChanged(int)),this,SLOT(rotateSlot(int)));
    this->angle=0;

}

rotate::~rotate()
{
    delete rimg;
    delete ui;
    delete scene;
}

void rotate::changeEvent(QEvent *e)
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

void rotate::rotateSlot(int alpha) {
    bool ok;
    angle = alpha;

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

    scene->addPixmap(QPixmap::fromImage(rimg->rotateAnyPoint(alpha,ui->lineEdit->text().toInt(&ok,10),ui->lineEdit_2->text().toInt(&ok,10),ui->graphicsView->width()-10,ui->graphicsView->height()-10)));
     ui->graphicsView->setScene(scene);

}
void rotate::rotateOKSlot(){

close();
    emit this->CloseSignalOK(angle);

}

void rotate::on_pushButton_clicked()
{
    close();
    emit this->CloseSignalCancel();
}

void rotate::on_dial_valueChanged(int value)
{

}
