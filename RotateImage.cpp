#include "RotateImage.h"

#include <QImage>
#include <cmath>

RotateImage::RotateImage(const QImage &im,QWidget *parent) : w(im.width()), h(im.height()),image(im)
{
    matrix.fill(0.0);
    vector.fill(0.0);
    move.fill(0.0);

    rawVec = vector.data();
    rawResult = result.data();

//    rotatedImage = NULL;

    imageData = image.bits();

}

RotateImage::~RotateImage() {

   // if(rotatedImage != NULL) {
     //   delete rotatedImage;
     //   rotatedImage = NULL;
   // }
}

QImage  RotateImage::rotateAnyPoint(const qreal alpha, const qreal x, const qreal y, const int sw, const int sh) {

    
   // if(rotatedImage != NULL) { delete rotatedImage; rotatedImage = NULL; }

    qreal alphaRad = alpha*M_PI/180;

   rotatedImage = QImage(sw,sh,QImage::Format_RGB32);
   uchar *rotatedImageData = rotatedImage.bits();

    /*Macierz odwrotna*/

    matrix(0,0) = matrix(1,1) = cos(alphaRad) ;
    matrix(1,0) = sin(alphaRad);
    matrix(0,1) = -matrix(1,0);
    matrix(2,2) = 1;
    matrix(0,2) = x*(1-matrix(0,0))+y*matrix(1,0);
    matrix(1,2) = y*(1-matrix(0,0))-x*matrix(1,0);


   // move(0,0) = move(1,1) = move(2,2) = 1.0;
   // move(0,2) = (-sw+w)/2.0;
   // move(1,2) = (-sw+w)/2.0;

    /*Wektor*/

    for(int k=0,j=0,i=0;k<sw*sh*4;k+=4,++i) {

        if(i==sw) {
            i = 0;
            ++j;
        }

        rawVec[0] = i+(-sw+w)/2.0;
        rawVec[1] = j+(-sh+h)/2.0;
        rawVec[2] = 1;

        //vector = matrix*vector;

        rawResult[0] = matrix(0,0)*rawVec[0]+matrix(0,1)*rawVec[1]+matrix(0,2)*rawVec[2];
        rawResult[1] = matrix(1,0)*rawVec[0]+matrix(1,1)*rawVec[1]+matrix(1,2)*rawVec[2];

        if(rawResult[0] < w && rawResult[0] >= 0 && rawResult[1] < h && rawResult[1] >= 0) {

           int tmp = (static_cast<int>(rawResult[1])*w+static_cast<int>(rawResult[0]))*4;

               rotatedImageData[k]   = imageData[tmp];
               rotatedImageData[k+1] = imageData[tmp+1];
               rotatedImageData[k+2] = imageData[tmp+2];
        } else {
                rotatedImageData[k] = rotatedImageData[k+1] = rotatedImageData[k+2] = 255;
               }
 }
    return rotatedImage;
    
}

//Funkcja obracajaca zdjecie o dany kat
QImage RotateImage::rotateCutBackground(const qreal alpha) {

    //if(rotatedImage != NULL) { delete rotatedImage; rotatedImage = NULL; }

    qreal alphaRad = alpha*M_PI/180;

 //   const int w = image.width(), h = image.height();
 //   const uchar *imageData = image.bits();
    float nh=0,nw=0,dx=0,dy=0;

    if(alpha <= 90) {        
    dx = 0;
    dy = sin(alphaRad)*w;
    nh = sin(alphaRad)*w + cos(alphaRad)*h;
    nw = sin(alphaRad)*h + cos(alphaRad)*w;
    } else if(alpha > 90 && alpha <= 180) {
    dx = cos(alphaRad)*w;
    dy = sin(alphaRad-M_PI/2)*h-cos(alphaRad+M_PI/2)*w;
    nh = sin(alphaRad-M_PI/2)*h+cos(alphaRad-M_PI/2)*w;
    nw = sin(alphaRad-M_PI/2)*w+cos(alphaRad-M_PI/2)*h;
    } else if(alpha > 180 && alpha <= 270) {
    dx = cos(alphaRad)*w+sin(alphaRad)*h;
    dy = sin(alphaRad-M_PI/2)*h;
    nh = sin(alphaRad-M_PI)*w + cos(alphaRad-M_PI)*h;
    nw = sin(alphaRad-M_PI)*h + cos(alphaRad-M_PI)*w;
    } else if(alpha > 270 && alpha <= 360) {
    dx = -h*cos(alphaRad-3*M_PI/2);
    dy = 0;
    nw = sin(alphaRad-3*M_PI/2)*w + cos(alphaRad-3*M_PI/2)*h;
    nh = sin(alphaRad-3*M_PI/2)*h + cos(alphaRad-3*M_PI/2)*w;
    }

   rotatedImage = QImage((int)nw,(int)nh,QImage::Format_RGB32);

    const int wr = rotatedImage.width(), hr = rotatedImage.height();
    uchar *rotatedImageData = rotatedImage.bits();

    matrix(0,0) = matrix(1,1) = cos(alphaRad) ;
    matrix(1,0) = sin(alphaRad);
    matrix(0,1) = -matrix(1,0);
    matrix(2,2) = 1;

    int tmp;

    for(int k=0,j=0,i=0;k<wr*hr*4;k+=4,++i) {

        if(i==wr) {
            i = 0;
            ++j;
        }

            rawVec[0] = i+dx ;
            rawVec[1] = j-dy;
            rawVec[2] = 0;

        //vector = matrix*vector;

            rawResult[0] = matrix(0,0)*rawVec[0]+matrix(0,1)*rawVec[1];
            rawResult[1] = matrix(1,0)*rawVec[0]+matrix(1,1)*rawVec[1];


        if(rawResult[0] < w && rawResult[0] >= 0 && rawResult[1] < h && rawResult[1] >= 0) {

            tmp = (static_cast<int>(rawResult[1])*w+static_cast<int>(rawResult[0]))*4;

               rotatedImageData[k]   = imageData[tmp];
               rotatedImageData[k+1] = imageData[tmp+1];
               rotatedImageData[k+2] = imageData[tmp+2];
        } else {
                rotatedImageData[k] = rotatedImageData[k+1] = rotatedImageData[k+2] = 194;
               }
 }
    return rotatedImage;
}

