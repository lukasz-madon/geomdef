#include "barreldialog.h"
#include "ui_barreldialog.h"

#include <QList>
#include <QColor>

barreldialog::barreldialog(QImage *img, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::barreldialog)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    image = img->scaled(QSize(200,200),Qt::KeepAspectRatio);
    scene->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView->setScene(scene);

    cxml = new ControllerXML();
ui->comboBox->addItems(cxml->getNames());
//ui->pushButton_3->setEnabled(false);
    // QImage tmp = img->scaled(QSize(200,200),Qt::KeepAspectRatio);
scene->setBackgroundBrush(QColor(0, 0, 0, 127));

this->interp = new Interpolation(&image);
}

barreldialog::~barreldialog()
{
    delete ui;
    delete cxml;
}

void barreldialog::changeEvent(QEvent *e)
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

void barreldialog::on_pushButton_clicked()
{
        close();
        emit CloseSignalCancel();

}

void barreldialog::setParamsSlot() {

    qreal *b = cxml->getParams(ui->comboBox->currentText());
       QVariant z1(b[0]);
       ui->lineEdit->setText(z1.toString());
       QVariant z2(b[1]);
       ui->lineEdit_2->setText(z2.toString());
       QVariant z3(b[2]);
       ui->lineEdit_3->setText(z3.toString());
       QVariant z4(b[3]);
       ui->lineEdit_4->setText(z4.toString());

}

void barreldialog::clearScene(){

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
ui->graphicsView->setScene(scene);
scene->setBackgroundBrush(QColor(0, 0, 0, 127));
}

//correct
void barreldialog::on_pushButton_3_clicked()
{

    //qreal *b = a->getParams(ui->comboBox->currentText());
       // pobera z etitow wstawione wartosci
       QVariant z1(ui->lineEdit->text());
       QVariant z2(ui->lineEdit_2->text());
       QVariant z3(ui->lineEdit_3->text());
       QVariant z4(ui->lineEdit_4->text());
       // na double
       qreal b[4] = {z1.toDouble(),z2.toDouble(),z3.toDouble(),z4.toDouble()};
       qreal x, y;
       qreal rs= 0, rd =0, fi=0;

       qreal width = image.width();
       qreal height = image.height();

       qreal rmax = sqrt((width/2.0)*(width/2.0)+(height/2.0)*(height/2.0));
       //const qreal sqrt2 = 1.41421356;

       // co do interpolacji to tu chyba trzeba ARGB. nie jestem pewnien
       // wydaje mi sie ze trzeba zrobic tlo czarne dodatkowo bo graphicview jest niskopizomowo
       // catchowany zeby szybciej renderowal
          QImage outImg(width,height,QImage::Format_RGB32);
          //wywalic to jak jest tlo i interpolacja
          outImg.fill(0);

       // magia beczki i poduszki
          for(int j=0;j<height;++j)
          {
              for(int i=0;i<width;++i)
              {
                   rs = sqrt((i-width/2.0)*(i-width/2.0)+(j-height/2.0)*(j-height/2.0))/rmax;
                   rd = (b[0] * rs * rs * rs + b[1] * rs * rs + b[2] * rs + b[3]) * rs;
                                // if((i-width/2.0)!=0)
                   fi = atan2(j-height/2.0,i-width/2.0);         //std::cout << rd << std::endl;

                   x = rmax * rd * cos(fi) + width/2.0 + 0.5;
                   y = rmax * rd * sin(fi) + height/2.0 + 0.5;
                   if(x < width && y < height && x >= 0 && y >= 0 )
                   {
                      rgb = interp->getHorizontal(x,y);
                       outImg.setPixel(static_cast<int>(i),static_cast<int>(j),rgb);
                   }
              }
          }
          // czyszcze scene
       clearScene();
       // tu jest dodawnanie na srodek. ustawienie sceny tamze. do wyjebania
      // scene.setSceneRect(ui->graphicsView->width()/2-width/2,ui->graphicsView->height()-height/2,width,height);
      // scene.setSceneRect(0,0,200,200);
       //dodaje do scene wynik
          scene->addPixmap(QPixmap::fromImage(outImg));

}
//ok clicked
void barreldialog::on_pushButton_2_clicked()
{
    QVariant z1(ui->lineEdit->text());
    QVariant z2(ui->lineEdit_2->text());
    QVariant z3(ui->lineEdit_3->text());
    QVariant z4(ui->lineEdit_4->text());

    close();

    emit this->CloseSignalOk(z1.toDouble(), z2.toDouble(), z3.toDouble(), z4.toDouble() );
}
