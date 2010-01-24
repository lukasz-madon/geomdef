#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QGenericMatrix>

class QImgae;

/// \class Transform
/// Klasa definujaca szybka transformacje obrazka.

class Transform
{
public:
    Transform();
    void trans(const uchar *imageDataIn, const uchar *imageDataOut,const QGenericMatrix<3,3,qreal> matrix);
private:


};

#endif // TRANSFORM_H
