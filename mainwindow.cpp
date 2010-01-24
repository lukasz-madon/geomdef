#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "math.h"
//#include "rotate.h"
//#include "ui_rotate.h"
//#include "rotateo.h"
//#include "ui_rotateo.h"
#include "skewdialog.h"
#include "Skew.h"
//#include "ui_skewdialog.h"
#include "RotateImage.h"
#include "axisrotate.h"
#include "rotate.h"
#include "rotateo.h"
#include "about.h"


#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isImageLoaded=false;
    isModifed=false;
   scene=NULL;
   aboutWindow=NULL;


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
void MainWindow::loadFile()
        {
            QString selectedFilter;
            QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath(),
                                                            "JPEG (*.jpg *.jpeg);;BMP (*.bmp);;PNG (*.png);;XPM (*.xpm);;XBM (*.xbm);;PPM (*.ppm);;TIFF (*.tif *.tiff);;XPM (*.xpm)",
                                                            &selectedFilter);
            if (!fileName.isEmpty()) {
                image.load(fileName);
                isImageLoaded=true;                
                if (image.isNull()) {
                    QMessageBox::information(this, tr("Image Viewer"),tr("Cannot load %1.").arg(fileName));
                    return;
                }

                currentFileName =fileName;
                QString filter = selectedFilter;

                if(tr("BMP (*.bmp)") == filter){
                    currentFileType = "BMP";
                }else if(tr("PNG (*.png)") == filter){
                    currentFileType = "PNG";
                }else if(tr("JPEG (*.jpg *.jpeg)") == filter){
                    currentFileType = "JPG";
                }else if(tr("XPM (*.xpm)") == filter){
                    currentFileType = "XPM";
                }else if(tr("XBM (*.xbm)") == filter){
                    currentFileType = "XBM";
                }else if(tr("PPM (*.ppm)") == filter){
                    currentFileType = "PPM";
                }else if(tr("TIFF (*.tif *.tiff)") == filter){
                    currentFileType = "TIFF";
                }
                if(scene!=NULL) {clearScene();  delete scene; scene=NULL;}
                scene = new QGraphicsScene();


            //    scene.clear();
              //   ui->graphicsView->setScene(&scene);
                 scene->addPixmap(QPixmap::fromImage(this->image));
                  ui->graphicsView->setScene(scene);
                isImageLoaded=true;


                this->activateMenu();
                loadImage();
                std::cout<<currentFileType.toStdString()<<std::endl;
                // abc = new skewdialog(image,this);
            }
    }

void MainWindow::saveFile(){
image.save(currentFileName,currentFileType.toLocal8Bit());

}
void MainWindow::saveFileAs(){


    bool writeStat;
    QString selectedFilter;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::currentPath(),
                                                    "PNG (*.png);;BMP (*.bmp);;JPEG (*.jpg *.jpeg);;XPM (*.xpm);;XBM (*.xbm);;PPM (*.ppm);;TIFF (*.tif *.tiff);;XPM (*.xpm)",
                                                    &selectedFilter);
    if (!fileName.isEmpty()) {
    QString filter = selectedFilter;
    QString fileType;

    if(tr("BMP (*.bmp)") == filter){
        fileType = "BMP";
    }else if(tr("PNG (*.png)") == filter){
        fileType = "PNG";
    }else if(tr("JPEG (*.jpg *.jpeg)") == filter){
        fileType = "JPG";
    }else if(tr("XPM (*.xpm)") == filter){
        fileType = "XPM";
    }else if(tr("XBM (*.xbm)") == filter){
        fileType = "XBM";
    }else if(tr("PPM (*.ppm)") == filter){
        fileType = "PPM";
    }else if(tr("TIFF (*.tif *.tiff)") == filter){
        fileType = "TIFF";
    }

     writeStat = image.save(fileName,fileType.toLocal8Bit());
    }
    // if (writeStat==false)
   // {
   //     QMessageBox::information(this, tr("Image Viewer"),tr("Cannot save %1.").arg(fileName));
   //     return;
   // }

}
void MainWindow::clearImage(){

    if(isModifed==true){
    switch( QMessageBox::warning( this,"Geomdef","Czy chcesz zapisac zmiany?",
                                  "Tak", "Nie", 0, 0, 1 )){
    case 0:
        saveFileAs();
        break;
    case 1:

        break;
    }}

    isImageLoaded=false;
    activateMenu();
    isModifed=false;
    clearScene();



}
void MainWindow::print(){
    QPrinter printer;
    if (QPrintDialog(&printer).exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        painter.setRenderHint(QPainter::Antialiasing);
        scene->render(&painter);

    }}


void MainWindow::exit(){
    close();
}

void MainWindow::activateMenu(){

    if(isImageLoaded==true)
    {
        ui->menuView->setEnabled(true);
        ui->menuEdit->setEnabled(true);
        ui->actionSave->setEnabled(true);
        ui->actionSave_As->setEnabled(true);
        ui->actionPrint->setEnabled(true);
        ui->actionClose_Imege->setEnabled(true);

    }else{
        ui->menuView->setEnabled(false);
        ui->menuEdit->setEnabled(false);
        ui->actionSave->setEnabled(false);
        ui->actionSave_As->setEnabled(false);
        ui->actionPrint->setEnabled(false);
        ui->actionClose_Imege->setEnabled(false);
    }

}

void MainWindow::loadImage()
{

    double ratio=1;
    if (isImageLoaded==true)
    {

        if ( image.width()>(ui->graphicsView->width()) || (image.height()>ui->graphicsView->height()) )
        {

 ui->graphicsView->resetTransform ();
            if(ui->graphicsView->width()>ui->graphicsView->height())
            {


                ratio =(double)(ui->graphicsView->width()-0.05*ui->graphicsView->width())/(double)(image.width());

                if(image.height()*ratio>ui->graphicsView->height())
                {
                    ratio =(double)(ui->graphicsView->height()-0.05*ui->graphicsView->height())/(double)(image.height());
                    ui->graphicsView->scale(ratio,ratio);

                }else
                {
                    ui->graphicsView->scale(ratio,ratio);

                }


            }else
            {


                ratio =(double)(ui->graphicsView->height()-0.05*ui->graphicsView->height())/(double)(image.height());
                if(image.width()*ratio>ui->graphicsView->width())
                {
                    ratio =(double)(ui->graphicsView->width()-0.05*ui->graphicsView->width())/(double)(image.width());
                    ui->graphicsView->scale(ratio,ratio);

                }else
                {
                    ui->graphicsView->scale(ratio,ratio);

                }


            }


        } else {
            ui->graphicsView->resetTransform ();
        }


    }


}

void MainWindow:: zoomIn()
{
    ui->graphicsView->scale(1.2, 1.2);


}

void MainWindow:: zoomOut()
{
    ui->graphicsView->scale(1/1.2,1/1.2);
}
void MainWindow:: rotateDialog()
{
     if(isImageLoaded==true){
    rotateWindow = new rotate(&image,this);

    connect(rotateWindow,SIGNAL(CloseSignalOK(int)),this,SLOT(rotateImageCloseOK(int)));
    connect(rotateWindow,SIGNAL(CloseSignalCancel()),this,SLOT(rotateImageCloseCancel()));
    rotateWindow->setModal(true);
    rotateWindow->show();
}
}

void MainWindow:: rotateoDialog()
{
    if(isImageLoaded==true){
    axisRotateWindow = new rotateo(&image,this);

     connect(axisRotateWindow,SIGNAL(CloseSignalOK(int, int, int)),this,SLOT(axisRotateImageCloseOK(int, int, int)));
     connect(axisRotateWindow,SIGNAL(CloseSignalCancel()),this,SLOT(axisRotateImageCloseCancel()));
     axisRotateWindow->setModal(true);
    axisRotateWindow->show();
}
}

void MainWindow::skewd()
{
     if(isImageLoaded==true){
    skewWindow = new skewdialog(&image, this);

    connect(skewWindow,SIGNAL(CloseSignalOK(int, int)),this,SLOT(skewCloseOK(int,int)));
      connect(skewWindow,SIGNAL(CloseSignalCancel()),this,SLOT(skewCloseCancel()));
     skewWindow->setModal(true);
     skewWindow->show();
 }

}

void MainWindow::rotateImageCloseOK(int angle) {

this->clearScene();

RotateImage tmp(image);

//delete image;
image = tmp.rotateCutBackground(angle);
delete scene;
scene = new QGraphicsScene();

scene->addPixmap(QPixmap::fromImage(image));
 ui->graphicsView->setScene(scene); 
this->loadImage();
isModifed=true;

    delete rotateWindow;
}

void MainWindow::rotateImageCloseCancel() {
    delete rotateWindow;
}

void MainWindow::axisRotateImageCloseOK(int xp, int yp, int zp){


 int diagonal = sqrt( (image.height()*image.height()) + (image.width()*image.width()) );
    AxisRotate tmp(image,diagonal,diagonal);

    tmp.setX(xp);
    tmp.setY(yp);
    image = tmp.setZ(zp);
    clearScene();
    delete scene;
    scene = new QGraphicsScene();

    scene->addPixmap(QPixmap::fromImage(image));
     ui->graphicsView->setScene(scene);
      this->loadImage();
        isModifed=true;
      delete axisRotateWindow;
}

void MainWindow::axisRotateImageCloseCancel(){
 delete axisRotateWindow;
}
void MainWindow::resizeEvent( QResizeEvent * ){
loadImage();
}

void MainWindow::openHelp(){
    QString dir("file:///") ;
    dir.append(QDir::currentPath());

    dir.append("/help/help.html");

    QDesktopServices::openUrl(QUrl(tr(dir.toLocal8Bit())));

}
void MainWindow::openWeb(){
 QDesktopServices::openUrl(QUrl("http://code.google.com/p/geomdef/", QUrl::TolerantMode));
}
void MainWindow::aboutInfo(){

    if(aboutWindow==NULL){
    aboutWindow = new about(this);
    }

    aboutWindow->setModal(true);
    aboutWindow->show();

}

void MainWindow::skewCloseOK(int angleX, int angleY){

    clearScene();
    delete scene;
    scene = new QGraphicsScene();

    Skew tmp;

    image = tmp.skewImageTwo(&image,angleX, angleY);
    scene->addPixmap(QPixmap::fromImage(image));
     ui->graphicsView->setScene(scene);
      this->loadImage();
    isModifed=true;
    delete skewWindow;
}
void MainWindow::skewCloseCancel(){

delete skewWindow;
}

void MainWindow::clearScene(){

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



}

void MainWindow::closeEvent(QCloseEvent *){
    if(isModifed==true){
    switch( QMessageBox::warning( this,"Geomdef","Czy chcesz zapisac zmiany?",
                                  "Tak", "Nie", 0, 0, 1 )){
    case 0:
        saveFileAs();
        break;
    case 1:

        break;
    }}

}
