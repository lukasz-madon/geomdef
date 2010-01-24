//////////////////////////////////////////////////////////////////////////////////
/// \file RotateImage.h
/// \author Daniel Matras
/// \author 7matras@novell.ftj.agh.edu.pl
/// \version 1.0.1
/// \date 16-01-2010
/// \brief Deklaracja klasy RotatedImage sluzacej do obrotu obrazu wokó³
/// \brief dowolnej osi prostopad³ej do p³aszczyzny rejestruj¹cej. Plik naglowkowy.
///////////////////////////////////////////////////////////////////////////////////


#ifndef ROTATEIMAGE_H
#define ROTATEIMAGE_H

#include <QObject>
#include <QGenericMatrix>
#include <QImage>

/////////////////////////////////////////////////////////////////////////
/// \class RotatedImage
/// Klasa definujaca obrot obrazu. Dziedzyczy po klasie QObject oraz Transform
/////////////////////////////////////////////////////////////////////////
class RotateImage : public QObject
{
    Q_OBJECT

public:
    /**
      * \fn Konstruktor
      * \brief Konstruktor przyjmujacy jako parmetry obraz oraz rodzica QWidget
      * \param im obraz przyjmowany jest jako referencja
      * \param parent Parametr domniemany. WskaŸnik do rodzica typu QWidget.
      */
    RotateImage(const QImage &im,QWidget *parent = 0);
    ~RotateImage();

     QImage rotateCutBackground(const qreal alpha);
     QImage rotateAnyPoint(const qreal alpha, const qreal x, const qreal y, const int w, const int h);

private:

    QMatrix3x3 matrix,move;
    QGenericMatrix<1,3,qreal> vector,result;
    qreal *rawVec,*rawResult;



    QImage rotatedImage;
    QImage image;

    const uchar *imageData;
    const int w,h;

};

#endif // ROTATEIMAGE_H
