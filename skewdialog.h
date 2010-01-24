//////////////////////////////////////////////////////////////////////////////////
/// \file skewdialog.h
/// \author Grzegorz Kurek
/// \author grzesiek.kurek@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Deklaracja klasy rotate - okna dialogowego
///////////////////////////////////////////////////////////////////////////////////


#ifndef SKEWDIALOG_H
#define SKEWDIALOG_H

#include <QtGui>
#include <QDialog>
#include "Skew.h"

/////////////////////////////////////////////////////////////////////////
/// \namespace Ui
/// Przestrzen nazw Ui
/////////////////////////////////////////////////////////////////////////
namespace Ui {
    class skewdialog;
}

/////////////////////////////////////////////////////////////////////////
/// \class skewdialog
/// Klasa oodpowiedzialna za glowne okno programu. Dziedzicy po QMainWindow.
/////////////////////////////////////////////////////////////////////////
class skewdialog : public QDialog {
    Q_OBJECT
public:

    /**
      *  Konstruktor
      * \brief Konstruktor skewdialog
      * \param parent wskaünik do rodzica typu QWidget.
      */
    skewdialog(QImage* img, QWidget *parent = 0);

    /**
      * Destruktor
      */
    ~skewdialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::skewdialog *ui;
    QGraphicsScene *scene;
    Skew *simg;
    QImage tmp;
    int angleX;
    int angleY;
    void clearScene();
signals:
    void CloseSignalOK(int angleX, int angleY);
    void CloseSignalCancel();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_dial_2_valueChanged(int value);
    void on_dial_valueChanged(int value);
};

#endif // SKEWDIALOG_H
