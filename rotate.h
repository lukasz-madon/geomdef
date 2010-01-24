//////////////////////////////////////////////////////////////////////////////////
/// \file rotate.h
/// \author Grzegorz Kurek
/// \author grzesiek.kurek@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Deklaracja klasy rotate - okna dialogowego
///////////////////////////////////////////////////////////////////////////////////

#ifndef ROTATE_H
#define ROTATE_H
#include <QtGui>
#include <QDialog>

class RotateImage;

/////////////////////////////////////////////////////////////////////////
/// \namespace Ui
/// Przestrzen nazw Ui
/////////////////////////////////////////////////////////////////////////

namespace Ui {
    class rotate;
}

/////////////////////////////////////////////////////////////////////////
/// \class rotate
/// Klasa oodpowiedzialna za glowne okno programu. Dziedzicy po QMainWindow.
/////////////////////////////////////////////////////////////////////////
class rotate : public QDialog {
    Q_OBJECT
public:


    /**
      *  Konstruktor
      * \brief Konstruktor rotate
      * \param parent wskaünik do rodzica typu QWidget.
      */
    rotate(const QImage *img,QWidget *parent = 0);

    /**
      * Destruktor
      */
    ~rotate();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::rotate *ui;

    QGraphicsScene *scene;
   int angle;
    RotateImage *rimg;



public slots:
    void rotateSlot(int );
    void rotateOKSlot();



signals:
    void CloseSignalOK(int angle);
    void CloseSignalCancel();
private slots:
    void on_dial_valueChanged(int value);
    void on_pushButton_clicked();

};

#endif // ROTATE_H
