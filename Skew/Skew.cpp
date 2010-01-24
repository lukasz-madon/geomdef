//////////////////////////////////////////////////////////////////////////////////
/// \file Skew.cpp
/// \author Lukasz Madon
/// \author 7madon@novell.ftj.agh.edu.pl OR lukasgt@wp.pl
/// \version 1.0.1
/// \date 16-01-2010
/// \brief Defnicja metod klasy Skew sluzacej do pochylen obrazow. plik zrodlowy
///////////////////////////////////////////////////////////////////////////////////

#include <QBitmap>
#include <QGenericMatrix>
#include <cmath>

#include "Skew.h"

//////////////////////////////////////////////////////////////////////////
/// Konstruktor domyslny
//////////////////////////////////////////////////////////////////////////
Skew::Skew()
{
    /// inicializacja tablicy ktora definuje macierz
    tab[0]= 1;
    tab[1]= 0;
    tab[2]= 0;
    tab[3]= 0;
    tab[4]= 1;
    tab[5]= 0;
    tab[6]= 0;
    tab[7]= 0;
    tab[8]= 1;
}

//////////////////////////////////////////////////////////////////////////
/// Destruktor
//////////////////////////////////////////////////////////////////////////
Skew::~Skew()
{

}

//////////////////////////////////////////////////////////////////////////
/// defnijca funkcji pochylajacej obraz
//////////////////////////////////////////////////////////////////////////
QImage* Skew::skewImage(QImage *newImage,  int valx, int valy)
{
    qreal alphax;
    qreal alphay;

    /// dlugosc i szerokosc obrazka
    int width = newImage->width();
    int height = newImage->height();

    /// kat pochylenia wzdluz osi x i y
    alphax = valx * M_PI/180;
    alphay = valy * M_PI/180;

    /// tablica do skew
    tab[1]= atan(alphax);
    tab[3]= atan(alphay);

    /// macierz pochylenia
    QGenericMatrix<3,3,qreal> matrix(tab);

    /// alokujemy obrazek wynikowy
    QImage *SkewImage = new QImage(width,height,QImage::Format_RGB32);

    /// transformacja obrazu
    trans(SkewImage,newImage,matrix);

    /// zwracamy wskaznik do pochylonego obrazka
    return SkewImage;
}

//////////////////////////////////////////////////////////////////////////
/// defnijca funkcji pochylajacej obraz
//////////////////////////////////////////////////////////////////////////
QImage* Skew::skewImageTwo(QImage *newImage, int valx, int valy)
{
    /// wspolrzedne pkt docelowego
    qreal x,y;

    /// dlugosc i szerokosc obrazka
    int width = newImage->width();
    int height = newImage->height();

    /// dlugosc i szerokosc obrazka wynikowego
    int outWidth = 2.5 * width;
    int outHeight = 2.5 * height;

    /// tablica do skew
    tab[1]= valx/100.0;
    tab[3]= valy/100.0;

    /// alokujemy obrazek wynikowy
    QImage *outImg = new QImage(outWidth,outHeight,QImage::Format_ARGB32);

    /// transformacja obrazu
    for(int i=1;i<width;++i)
    {
        for(int j=1;j<height;++j)
        {
            x=tab[0]*i+tab[3]*j;
            y=tab[1]*i+tab[4]*j;

            outImg->setPixel(x+(outWidth/2.0-width/2.0),y+(outHeight/2.0-height/2.0),newImage->pixel(i,j));
        }
    }
    /// zwracamy wskaznik do pochylonego obrazka
    return outImg;
}

