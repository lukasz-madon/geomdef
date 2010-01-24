//////////////////////////////////////////////////////////////////////////////////
/// \file axisrotate.h
/// \author Daniel Matras
/// \author 7matras@novell.ftj.agh.edu.pl
/// \version 1.0.1
/// \date 16-01-2010
/// \brief Deklaracja klasy AxisRotate sluzacej do obrotu obrazu dowolnej osi.
/// \brief dowolnej osi rownoleglej do płaszczyzny rejestrującej. Plik naglowkowy.
///////////////////////////////////////////////////////////////////////////////////

#ifndef AXISROTATE_H
#define AXISROTATE_H

#include <QGenericMatrix>
#include <QImage>

//////////////////////////////////////////////////////////////////////////////////////
/// \class AxisRotate
/// \brief Klasa definujaca obrot obrazu wokol osi.
//////////////////////////////////////////////////////////////////////////////////////
class QGraphicsScene;

class AxisRotate
{
public:
    ////////////////////////////////////////////////////////////////////////////////
    /// AxisRotate
    /// \brief Konstruktor przyjmujacy jako parmetry obrazi rozmiar okna.
    /// \param im obraz przyjmowany jest jako referencja do QImage.
    /// \param newW szerokosc tla.
    /// \param newH wysokosc tla.
    ////////////////////////////////////////////////////////////////////////////////
    AxisRotate(const QImage &im, const int newW, const int newH);

    ///////////////////////////////////////////////////////////////////////////////
    /// Destruktor.
    //////////////////////////////////////////////////////////////////////////////
   ~AxisRotate();

   /////////////////////////////////////////////////////////////////////////
   /// setX
   /// \brief Metoda setX odpowiada za pochylenie obrazka wzgledem osi x.
   /// \param x kat obrotu.
   /// \return Zwraca obrazek po obrocie jako obiekt QImage.
   /////////////////////////////////////////////////////////////////////////
    QImage  setX(int x);

    /////////////////////////////////////////////////////////////////////////
    /// setY
    /// \brief Metoda setY odpowiada za pochylenie obrazka wzgledem osi y.
    /// \param y kat obrotu.
    /// \return Zwraca obrazek po obrocie jako obiekt QImage.
    /////////////////////////////////////////////////////////////////////////
    QImage  setY(int y);

    /////////////////////////////////////////////////////////////////////////
    /// setZ
    /// \brief Metoda setZ odpowiada za pochylenie obrazka wzgledem osi z.
    /// \param z kat obrotu.
    /// \return Zwraca obrazek po obrocie jako obiekt QImage.
    /////////////////////////////////////////////////////////////////////////
    QImage  setZ(int z);

    ////////////////////////////////////////////////////////////////////////////////
    /// wartosci katow
    ////////////////////////////////////////////////////////////////////////////////
    int xp,yp,zp;

private:
    /////////////////////////////////////////////////////////////////////////
    /// translate
    /// \brief Metoda translate odpowiada za obrot obrazka.
    /// \return Zwraca obrazek po obrocie jako obiekt QImage.
    /////////////////////////////////////////////////////////////////////////
    QImage translate();

    ////////////////////////////////////////////////////////////////////////////////
    // macierze obrotu i przesuniecia
    ////////////////////////////////////////////////////////////////////////////////
    QGenericMatrix<4,4,qreal> mx,my,mz,per,minusTran,tran,outcome,move;

    ////////////////////////////////////////////////////////////////////////////////
    // vektor punktu
    ////////////////////////////////////////////////////////////////////////////////
    QGenericMatrix<1,4,qreal> vec;

    /////////////////////////////////////////////////////////////////////////
    // Wejsciowy obrazek
    /////////////////////////////////////////////////////////////////////////
    const QImage image;

    /////////////////////////////////////////////////////////////////////////
    // Wyjsciowy obrazek
    /////////////////////////////////////////////////////////////////////////
    QImage rotatedImage;

    ////////////////////////////////////////////////////////////////////////////////
    // wysokosc i szerokosc obrazka
    ////////////////////////////////////////////////////////////////////////////////
    int nw,nh;

};

#endif // AXISROTATE_H
