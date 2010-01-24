#ifndef AXISROTATE_H
#define AXISROTATE_H

#include <QGenericMatrix>

#include <QImage>
class QGraphicsScene;

class AxisRotate
{
public:
    AxisRotate(const QImage &im, const int newW, const int newH);
   ~AxisRotate();

    QImage * setX(int x);
    QImage * setY(int y);
    QImage * setZ(int z);

private:

    QImage *translate();

    QGenericMatrix<4,4,qreal> mx,my,mz,per,minusTran,tran,outcome,move;
    QGenericMatrix<1,4,qreal> vec;


    const QImage image;
    QImage *rotatedImage;

    int nw,nh;


};

#endif // AXISROTATE_H
