#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // obiekt controlera
    a = new ControllerXML();
    //combobox znazwami obiektow
    ui->comboBox->addItems(a->getNames());
    // niektywny przycisk doMagic
    ui->pushButton_2->setEnabled(false);
    // ustalamy scene
    ui->graphicsView->setScene(&scene);
    // czarny kolor polprzeŸroczysty
    // fajny bylby pattern jak jest w fotoszopie, szachownica bia³o-szara
    scene.setBackgroundBrush(QColor(0, 0, 0, 127));
}
//kasuje kontlorera
MainWindow::~MainWindow()
{
    delete ui;
    //delete image;
    delete a;
   // delete scene;
}
// pierdoly
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

// ustawiam edity 4 kolejno
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
// otiweranie obrazka - wywalic
void MainWindow::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());
    if (!fileName.isEmpty())
    {
        image.load(fileName);
        if (image.isNull())
        {
            QMessageBox::information(this, tr("Image Viewer"),tr("Cannot load %1.").arg(fileName));
        }
        else
        {
        clearScene();
          scene.addPixmap(QPixmap::fromImage(image));

          ui->lineEdit->setText(fileName);
              ui->pushButton_2->setEnabled(true);
        }
    }
}

// beczka i poduszka
void MainWindow::doMagic()
{

    //qreal *b = a->getParams(ui->comboBox->currentText());
    // pobera z etitow wstawione wartosci
    QVariant z1(ui->lineEdit_2->text());
    QVariant z2(ui->lineEdit_3->text());
    QVariant z3(ui->lineEdit_4->text());
    QVariant z4(ui->lineEdit_5->text());
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
                    outImg.setPixel(static_cast<int>(x),static_cast<int>(y),image.pixel(i,j));
                }
           }
       }
       // czyszcze scene
    clearScene();
    // tu jest dodawnanie na srodek. ustawienie sceny tamze. do wyjebania
   // scene.setSceneRect(ui->graphicsView->width()/2-width/2,ui->graphicsView->height()-height/2,width,height);
   // scene.setSceneRect(0,0,200,200);
    //dodaje do scene wynik
       scene.addPixmap(QPixmap::fromImage(outImg));
}
// czyszczenie takie fancy
void MainWindow::clearScene()
{

            bool itemDeleted = true;
            QList <QGraphicsItem*> itemList = scene.items();

            while (itemDeleted && !itemList.isEmpty()) {
                    int numItems = itemList.size();
                    int iItem;
                    itemDeleted = false;
                    for (iItem = 0; (iItem < numItems) && !itemDeleted; iItem++) {
                            QGraphicsItem *item = itemList.at(iItem);
                            if (item->parentItem() == NULL) {
                                    scene.removeItem(item);
                                    delete item;
                                    itemDeleted = true;
                            }
                    }
                    itemList = scene.items();
            }
            if (!itemList.isEmpty() && !itemDeleted)
                    qWarning("Problem with clear()");




    /*  ui->graphicsView->resetCachedContent();
    QList<QGraphicsItem *> list = scene.items();
           QList<QGraphicsItem *>::Iterator it = list.begin();
           for ( ; it != list.end(); ++it )
           {
                   if ( *it )
                   {
                           scene.removeItem(*it);
                           delete *it;
                   }
           }*/

         /* delete scene;

           scene = new QGraphicsScene();
           scene->setBackgroundBrush(QColor(0, 0, 0, 127));
           ui->graphicsView->setScene(scene); */
}


