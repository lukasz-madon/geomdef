//////////////////////////////////////////////////////////////////////////////////
/// \file mainwindow.h
/// \author Grzegorz Kurek
/// \author grzesiek.kurek@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Deklaracja klasy mainwindow, glownego okna programu. Plik naglowkowy.
///////////////////////////////////////////////////////////////////////////////////

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include "interpolation.h"
#include <QColor>

/////////////////////////////////////////////////////////////////////////
/// \namespace Ui
/// \brief Przestrzen nazw Ui
/////////////////////////////////////////////////////////////////////////

namespace Ui
{
    class MainWindow;
}

class QGraphicsScene;
class rotate;
class rotateo;
class skewdialog;
class about;
class barreldialog;

////////////////////////////////////////////////////////////////////////////////
/// \class MainWindow
/// \brief Klasa oodpowiedzialna za glowne okno programu. Dziedzicy po QMainWindow.
///////////////////////////////////////////////////////////////////////////////
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    //////////////////////////////////////////////////////////////////////////
    /// MainWindow
    /// \brief Konstruktor przyjmujacy jako parmetr rodzica QWidget.
    /// \param parent Parametr domniemany. Wska�nik do rodzica typu QWidget.
    /////////////////////////////////////////////////////////////////////////
    MainWindow(QWidget *parent = 0);

    /////////////////////////////////////////////////////////////////////////
    /// Destruktor.
    /////////////////////////////////////////////////////////////////////////
    ~MainWindow();

    /////////////////////////////////////////////////////////////////////////
    /// image
    /// \brief Obiekt typu QImage, obraz wczytywany do modyfikacji.
    /////////////////////////////////////////////////////////////////////////
    QImage image;

protected:
    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void changeEvent(QEvent *e);

private:
    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    QGraphicsScene *scene;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    Ui::MainWindow *ui;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    int angle;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void resizeEvent( QResizeEvent * );

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    bool isImageLoaded;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    QString currentFileName;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    QString currentFileType;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void clearScene();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    bool isModifed;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    rotate *rotateWindow;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    rotateo *axisRotateWindow;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    skewdialog *skewWindow;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    about *aboutWindow;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    barreldialog * bdialog;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    Interpolation * interp;

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    QRgb rgb;
private slots:
    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void on_actionBarrel_correction_activated();
    void loadFile();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void barelCorrectionSlot();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void zoomIn();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void zoomOut();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void rotateDialog();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void rotateoDialog();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void skewd();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void rotateImageCloseOK(int angle);

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void rotateImageCloseCancel();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void axisRotateImageCloseOK(int xp, int yp, int zp);

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void axisRotateImageCloseCancel();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void skewCloseOK(int angleX, int angleY);

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void barrelSignalCancel();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void barrelSignalOK(qreal a1, qreal b1, qreal c1, qreal d1);

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void skewCloseCancel();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void saveFile();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void saveFileAs();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void clearImage();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void print();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void exit();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void loadImage();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void activateMenu();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void openHelp();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void openWeb();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void aboutInfo();

    ////////////////////////////////////////////////////////////////////////////////
    //
    ////////////////////////////////////////////////////////////////////////////////
    void closeEvent(QCloseEvent *);

};

#endif // MAINWINDOW_H
