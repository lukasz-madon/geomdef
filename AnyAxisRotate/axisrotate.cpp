#include "axisrotate.h"
#include <QGenericMatrix>
#include <cmath>

AxisRotate::AxisRotate(const QImage &im, const int newW, const int newH): image(im)
{
mx.fill(0.0);
my.fill(0.0);
mz.fill(0.0);
per.fill(0.0);
minusTran.fill(0.0);
tran.fill(0.0);

minusTran(0,0) = minusTran(1,1) = minusTran(2,2) = minusTran(3,3) =
tran(0,0) = tran(1,1) = tran(2,2) = tran(3,3) = 1.0;

mx(0,0)=mx(1,1)=mx(2,2)=mx(3,3)=1.0;
my(0,0)=my(1,1)=my(2,2)=my(3,3)=1.0;
mz(0,0)=mz(1,1)=mz(2,2)=mz(3,3)=1.0;
move(0,0)=move(1,1)=move(2,2)=move(3,3)=1.0;

move(0,3)=newW/2-im.width()/2;
move(1,3)=newH/2-im.height()/2;

minusTran(0,3) = im.width()/2.0;
minusTran(1,3) = im.height()/2.0;
//minusTran(2,3) = 0;
nw = newW;
nh = newH;

tran(0,3) = -im.width() /2.0;
tran(1,3) = -im.height()/2.0;

//tran(2,3) = 0;

per(0,0) = per(1,1) = per(3,3) = 1.0;
per(3,2) = 1.0/-200.0;

rotatedImage = NULL;
}

AxisRotate::~AxisRotate() {
  //  if(rotatedImage != NULL) { delete rotatedImage;}
}

 QImage *AxisRotate::setX(int x) {

     double rx = static_cast<double>(x)*M_PI/180.0;

    mx(0,0) = mx(3,3) = 1;
    mx(1,1) = mx(2,2) = cos(rx);
    mx(2,1) = sin(rx);
    mx(1,2) = -mx(2,1);

return translate();
}

 QImage *AxisRotate::setY(int y) {

     double ry = static_cast<double>(y)*M_PI/180.0;

     my(1,1) = my(3,3) = 1;
     my(0,0) = my(2,2) = cos(ry);
     my(0,2) = sin(ry);
     my(2,0) = -sin(ry);
return translate();
}

 QImage *AxisRotate::setZ(int z) {

     double rz = static_cast<double>(z)*M_PI/180.0;

     mz(0,0) = mz(1,1) = cos(rz);
     mz(0,1) = -sin(rz);
     mz(1,0) = -mz(0,1);
     mz(2,2) = mz(3,3) = 1;

return translate();//const_cast<QImage>(image);
}

 QImage *AxisRotate::translate() {

      if(rotatedImage != NULL) { delete rotatedImage; rotatedImage = NULL; }

      const int w = image.width(), h = image.height();
      const uchar *imageData = image.bits();

      rotatedImage = new QImage((int)nw,(int)nh,QImage::Format_RGB32);

       //const int wr = rotatedImage->width(), hr = rotatedImage->height();
       uchar *rotatedImageData = rotatedImage->bits();

       outcome = minusTran*mx*my*mz*tran;//*tran;
       // mx = minusTran*mx;

       rotatedImage->fill(qRgb(0,0,0));

       for(int i=0;i<w;++i)
           for(int j=0;j<h;++j) {

           vec(0,0) = i ;
           vec(1,0) = j ;
           vec(2,0) = 0 ;
           vec(3,0) = 1 ;

           vec = outcome*vec;
           vec = move*vec;
        //   vec = per*vec;

      //     vec(0,0) *= 1/vec(3,0);
       //    vec(1,0) *= 1/vec(3,0);
          //  rotatedImage->setPixel(i,j,qRgb(0,0,0));
       //    vec = per*vec;
           if(vec(0,0) < nw && vec(0,0) >= 0 && vec(1,0) < nh && vec(1,0) >= 0)
                rotatedImage->setPixel(vec(0,0),vec(1,0),image.pixel((int)i,(int)j));

       //    } else {

           //if()

           //else {

         //      rotatedImage->setPixel(vec(0,0),vec(1,0),qRgb(0,0,0));
         //}

       }

    /*  for(int k=0,j=0,i=0;k<wr*hr*4;k+=4,++i) {

          if(i==wr) {
              i = 0;
              ++j;
          }

          vec(0,0) = i ;
          vec(1,0) = j ;
          vec(2,0) = vec(3,0) = 1;

          vec = mx*per*vec;

          vec(0,0) *= vec(3,0);
          vec(1,0) *= vec(3,0);

          if(vec(0,0) < w && vec(0,0) >= 0 && vec(1,0) < h && vec(1,0) >= 0) {

              int tmp = (static_cast<int>(vec(1,0))*w+static_cast<int>(vec(0,0)))*4;

                 rotatedImageData[k]   = imageData[tmp];
                 rotatedImageData[k+1] = imageData[tmp+1];
                 rotatedImageData[k+2] = imageData[tmp+2];
          } else {
                  rotatedImageData[k] = rotatedImageData[k+1] = rotatedImageData[k+2] = 0;
                 }
   }
*/
return rotatedImage;
  }

