////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \file transform.h
/// \author
/// \author
/// \version
/// \date
/// \brief
////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QBitmap>
#include <QGenericMatrix>

/////////////////////////////////////////////////////////////////////////
/// \class Transform
/// Klasa definujaca szybka transformacje obrazka.
/////////////////////////////////////////////////////////////////////////
class Transform
{
public:
    /////////////////////////////////////////////////////////////////////////
    /// Kostruktor domyslny
    /////////////////////////////////////////////////////////////////////////
    Transform();

    /////////////////////////////////////////////////////////////////////////
    /// virtualny destruktor
    /////////////////////////////////////////////////////////////////////////
    virtual ~Transform();

    /////////////////////////////////////////////////////////////////////////
    /// Metoda trans odpowiada za transformacje obrazka
    /// \param inImage wskaznik na obrazek ktory bedzie transformowany
    /// \param outImage wskaznik na obrazek ktory zostal przetransformowany
    /// \param matrix macierz transformacji
    /////////////////////////////////////////////////////////////////////////
    void trans(QImage* inImage, QImage* outImage, QGenericMatrix<3,3,qreal> matrix);
};

#endif // TRANSFORM_H
