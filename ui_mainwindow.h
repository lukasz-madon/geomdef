/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 24. Jan 03:23:27 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionRotate;
    QAction *actionRotate_1;
    QAction *actionSkew;
    QAction *actionBeczka_poduszka;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionPrinter_Setup;
    QAction *actionClose_Imege;
    QAction *actionExit;
    QAction *actionGeomdef_Help;
    QAction *actionWeb_Site;
    QAction *actionAbout;
    QAction *actionF;
    QAction *actionE;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(618, 511);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionZoom_In = new QAction(MainWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_In->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/icons/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_In->setIcon(icon1);
        actionZoom_Out = new QAction(MainWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/icons/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_Out->setIcon(icon2);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        actionRotate->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/icons/pointrot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon3);
        actionRotate_1 = new QAction(MainWindow);
        actionRotate_1->setObjectName(QString::fromUtf8("actionRotate_1"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/icons/axisrot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate_1->setIcon(icon4);
        actionSkew = new QAction(MainWindow);
        actionSkew->setObjectName(QString::fromUtf8("actionSkew"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/icons/skew.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSkew->setIcon(icon5);
        actionBeczka_poduszka = new QAction(MainWindow);
        actionBeczka_poduszka->setObjectName(QString::fromUtf8("actionBeczka_poduszka"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon6);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSave_As->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/icons/filesaveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon7);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionPrint->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/icons/fileprint.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon8);
        actionPrinter_Setup = new QAction(MainWindow);
        actionPrinter_Setup->setObjectName(QString::fromUtf8("actionPrinter_Setup"));
        actionPrinter_Setup->setEnabled(true);
        actionClose_Imege = new QAction(MainWindow);
        actionClose_Imege->setObjectName(QString::fromUtf8("actionClose_Imege"));
        actionClose_Imege->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/icons/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_Imege->setIcon(icon9);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/image/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon10);
        actionGeomdef_Help = new QAction(MainWindow);
        actionGeomdef_Help->setObjectName(QString::fromUtf8("actionGeomdef_Help"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/image/icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGeomdef_Help->setIcon(icon11);
        actionWeb_Site = new QAction(MainWindow);
        actionWeb_Site->setObjectName(QString::fromUtf8("actionWeb_Site"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/image/icons/gohome.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWeb_Site->setIcon(icon12);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/image/icons/mail_generic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon13);
        actionF = new QAction(MainWindow);
        actionF->setObjectName(QString::fromUtf8("actionF"));
        actionF->setCheckable(true);
        actionF->setChecked(true);
        actionE = new QAction(MainWindow);
        actionE->setObjectName(QString::fromUtf8("actionE"));
        actionE->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_3->addWidget(graphicsView);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 618, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuView->setEnabled(false);
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuEdit->setEnabled(false);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionClose_Imege);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);
        menuEdit->addAction(actionRotate);
        menuEdit->addAction(actionRotate_1);
        menuEdit->addAction(actionSkew);
        menuHelp->addAction(actionGeomdef_Help);
        menuHelp->addAction(actionWeb_Site);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(actionOpen, SIGNAL(activated()), MainWindow, SLOT(loadFile()));
        QObject::connect(actionZoom_In, SIGNAL(activated()), MainWindow, SLOT(zoomIn()));
        QObject::connect(actionZoom_Out, SIGNAL(activated()), MainWindow, SLOT(zoomOut()));
        QObject::connect(actionRotate, SIGNAL(activated()), MainWindow, SLOT(rotateDialog()));
        QObject::connect(actionRotate_1, SIGNAL(activated()), MainWindow, SLOT(rotateoDialog()));
        QObject::connect(actionSkew, SIGNAL(activated()), MainWindow, SLOT(skewd()));
        QObject::connect(actionExit, SIGNAL(activated()), MainWindow, SLOT(exit()));
        QObject::connect(actionSave, SIGNAL(activated()), MainWindow, SLOT(saveFile()));
        QObject::connect(actionSave_As, SIGNAL(activated()), MainWindow, SLOT(saveFileAs()));
        QObject::connect(actionPrint, SIGNAL(activated()), MainWindow, SLOT(print()));
        QObject::connect(actionClose_Imege, SIGNAL(activated()), MainWindow, SLOT(clearImage()));
        QObject::connect(actionAbout, SIGNAL(activated()), MainWindow, SLOT(aboutInfo()));
        QObject::connect(actionGeomdef_Help, SIGNAL(activated()), MainWindow, SLOT(openHelp()));
        QObject::connect(actionWeb_Site, SIGNAL(activated()), MainWindow, SLOT(openWeb()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Geomdef", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("MainWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setShortcut(QApplication::translate("MainWindow", "Ctrl+Up", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("MainWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setShortcut(QApplication::translate("MainWindow", "Ctrl+Down", 0, QApplication::UnicodeUTF8));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate around piont", 0, QApplication::UnicodeUTF8));
        actionRotate->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionRotate_1->setText(QApplication::translate("MainWindow", "Rotate around axis", 0, QApplication::UnicodeUTF8));
        actionRotate_1->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionSkew->setText(QApplication::translate("MainWindow", "Skew", 0, QApplication::UnicodeUTF8));
        actionSkew->setShortcut(QApplication::translate("MainWindow", "Ctrl+K", 0, QApplication::UnicodeUTF8));
        actionBeczka_poduszka->setText(QApplication::translate("MainWindow", "beczka/poduszka", 0, QApplication::UnicodeUTF8));
        actionBeczka_poduszka->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0, QApplication::UnicodeUTF8));
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionPrinter_Setup->setText(QApplication::translate("MainWindow", "Printer Setup", 0, QApplication::UnicodeUTF8));
        actionClose_Imege->setText(QApplication::translate("MainWindow", "Close Image", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionGeomdef_Help->setText(QApplication::translate("MainWindow", "Geomdef Help", 0, QApplication::UnicodeUTF8));
        actionWeb_Site->setText(QApplication::translate("MainWindow", "Web Site", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionF->setText(QApplication::translate("MainWindow", "f", 0, QApplication::UnicodeUTF8));
        actionE->setText(QApplication::translate("MainWindow", "e", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
