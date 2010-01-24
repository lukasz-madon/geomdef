#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new Controller();
    ui->comboBox->addItems(a->getNames());

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::black);
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

inline int sgn(int j)
{
    if(j>0)
        return 1;
    if(j<0)
        return -1;
    else
        return 0;
}

inline int sgn(double j)
{
    if(j>0)
        return 1;
    if(j<0)
        return -1;
    else
        return 0;
}

void MainWindow::slot1()
{
    qreal *b = a->getParams(ui->comboBox->currentText());
    QVariant z1(b[0]);
    ui->lineEdit_2->setText(z1.toString());
    QVariant z2(b[1]);
    ui->lineEdit_3->setText(z2.toString());
    QVariant z3(b[2]);
    ui->lineEdit_4->setText(z3.toString());
    QVariant z4(b[3]);
    ui->lineEdit_5->setText(z4.toString());

}

void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty())
    {
        image = new QImage(fileName);
        if (image->isNull())
        {
            QMessageBox::information(this, tr("Image Viewer"),tr("Cannot load %1.").arg(fileName));
        }
        else
        {
          scene->addPixmap(QPixmap::fromImage(*image));
          ui->lineEdit->setText(fileName);
        }
    }
}


void MainWindow::doMagic()
{
    qreal *b = a->getParams(ui->comboBox->currentText());
    qreal x, y;
    qreal rs= 0, rd =0, fi=0;

    qreal width = image->width();
    qreal height = image->height();

    qreal rmax = sqrt( (width)*(width)+(height)*(height) )/2.0;
    const qreal sqrt2 = 1.41421356;

       QImage *outImg = new QImage(width,height,QImage::Format_RGB32);

    qreal co,si;

       for(qreal j=0;j<height;++j)
       {
           for(qreal i=0;i<width;++i)
           {
                /*rs = sqrt((i-width/2.0)*(i-width/2.0)+(j-height/2.0)*(j-height/2.0))/rmax;
                rd = (b[0] * rs * rs * rs + b[1] * rs * rs + b[2] * rs + b[3]) * rs;
                             // if((i-width/2.0)!=0)

                std::cout << rd << " " << rs << std::endl;

                fi = atan2(j-height/2.0,i-width/2.0);
                             //std::cout << rd << std::endl;
                x =  rmax*rd * cos(fi) + width/2.0;
                y =  rmax*rd * sin(fi) + height/2.0;
                    */
               rs = sqrt((i-width/2.0)*(i-width/2.0)+(j-height/2.0)*(j-height/2.0))/rmax;
               rd = (b[0] * rs * rs * rs + b[1] * rs * rs + b[2] * rs + b[3]) * rs;//(-b[3]+sqrt(b[3]*b[3]-4*b[2]*rs))/(2.0*b[2]);///

               co = (i-width/2.0)/rs;
               si = (j-height/2.0)/rs;

                //rd = (rs-rd)+rs;

                std::cout << rd << " " << rs << std::endl;

               x =  rd*(i-width/2.0)/rs + width/2.0;
               y =  rd*(j-height/2.0)/rs + height/2.0;

                if(x < width && y < height && x > 0 && y > 0 )
                {
                    outImg->setPixel(static_cast<int>(x),static_cast<int>(y),image->pixel(i,j));
                }
           }
       }
       scene->clear();
       scene->addPixmap(QPixmap::fromImage(*outImg));
        delete outImg;
}


