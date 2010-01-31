//////////////////////////////////////////////////////////////////////////////////
/// \file barreldialog.h
/// \author Grzegorz Kurek
/// \author grzesiek.kurek@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Deklaracja klasy bedacej oknem pomocniczym korekcji obiektywu.
///////////////////////////////////////////////////////////////////////////////////

#ifndef BARRELDIALOG_H
#define BARRELDIALOG_H

#include <QDialog>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "ControllerXML.h"
#include "interpolation.h"


namespace Ui {
    class barreldialog;
}

////////////////////////////////////////////////////////////////////////////////
/// \class barreldialog
/// \brief Klasa oodpowiedzialna za korekcje obiektywu
///////////////////////////////////////////////////////////////////////////////
class barreldialog : public QDialog {
    Q_OBJECT
public:
    //////////////////////////////////////////////////////////////////////////
    /// barreldialog
    /// \brief Konstruktor przyjmujacy obrazek oraz rodzica 
    /// \param img obrazek na ktorym zostana wykonane przeksztalcenia
	/// \param parent rodzic
    /////////////////////////////////////////////////////////////////////////
    barreldialog(QImage *img,QWidget *parent = 0);
	//////////////////////////////////////////////////////////////////////////
    /// barreldialog
    /// \brief Destruktor
    /////////////////////////////////////////////////////////////////////////
    ~barreldialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::barreldialog *ui;

    ControllerXML *cxml;

     QGraphicsScene *scene;

     QImage image;

     Interpolation *interp;
     QRgb rgb;

     void clearScene();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void setParamsSlot();

signals:
    void CloseSignalCancel();
    void CloseSignalOk(qreal a,qreal b,qreal c,qreal d);

};

#endif // BARRELDIALOG_H
