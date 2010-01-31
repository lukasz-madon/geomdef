//////////////////////////////////////////////////////////////////////////////////
/// \file interpolation.h
/// \author Daniel Matras
/// \author mmatras@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Klasa zajmujaca sie interpolacja.
///////////////////////////////////////////////////////////////////////////////////


#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <QObject>
#include <QImage>
#include <QColor>


////////////////////////////////////////////////////////////////////////////////
/// \class Interpolation
/// \brief Klasa odpowiedzialna za interpolacje zdjecia
///////////////////////////////////////////////////////////////////////////////
class Interpolation : public QObject
{
public:

	//////////////////////////////////////////////////////////////////////////
    /// Interpolation
    /// \brief Konstruktor przyjmujacy jako parmetr wskaznik do obrazka.
    /// \param image Wskaznik do oryginalnego obrazka
    /////////////////////////////////////////////////////////////////////////
    Interpolation(QImage *image);

	//////////////////////////////////////////////////////////////////////////
    /// getHorizontal
    /// \brief Konstruktor przyjmujacy jako parmetr wskaznik do obrazka.
    /// \param x wspolrzedna x-owa
	/// \param y wspolrzedna y-owa
    /////////////////////////////////////////////////////////////////////////	
    QRgb getHorizontal(double x, double y);
private:
    QImage *image;


    QRgb getVertical(int x, double y);
    inline double weight(double dx);
    double range;
    int top,bottom,left,right;

    int getRed(int x, int y) {return qRed(image->pixel(x, y));}
    int getBlue(int x, int y) {return qBlue(image->pixel(x, y));}
    int getGreen(int x, int y) {return qGreen(image->pixel(x, y));}

};

#endif // INTERPOLATION_H
