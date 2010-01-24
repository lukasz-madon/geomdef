//////////////////////////////////////////////////////////////////////////////////
/// \file about.h
/// \author Grzegorz Kurek
/// \author grzesiek.kurek@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Deklaracja klasy about - okna wyswietlajπcego informacje o programie
///////////////////////////////////////////////////////////////////////////////////


#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

/////////////////////////////////////////////////////////////////////////
/// \namespace Ui
/// Przestrzen nazw Ui
/////////////////////////////////////////////////////////////////////////

namespace Ui {
    class about;
}


/////////////////////////////////////////////////////////////////////////
/// \class about
/// Klasa oodpowiedzialna za glowne okno programu. Dziedzicy po QMainWindow.
/////////////////////////////////////////////////////////////////////////
class about : public QDialog {
    Q_OBJECT
public:


    /**
      *  Konstruktor
      * \brief Konstruktor about
      * \param parent wskaünik do rodzica typu QWidget.
      */
    about(QWidget *parent = 0);

    /**
      * Destruktor
      */
    ~about();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::about *ui;

private slots:
    void on_pushButton_clicked();
};

#endif // ABOUT_H
