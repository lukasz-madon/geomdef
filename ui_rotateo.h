/********************************************************************************
** Form generated from reading UI file 'rotateo.ui'
**
** Created: Sun 31. Jan 21:29:31 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATEO_H
#define UI_ROTATEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_rotateo
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QDial *dial;
    QDial *dial_2;
    QDial *dial_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QDialog *rotateo)
    {
        if (rotateo->objectName().isEmpty())
            rotateo->setObjectName(QString::fromUtf8("rotateo"));
        rotateo->resize(646, 346);
        gridLayout = new QGridLayout(rotateo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(rotateo);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 10, 1);

        pushButton_3 = new QPushButton(rotateo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 8, 1, 1, 1);

        pushButton = new QPushButton(rotateo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 9, 1, 1, 1);

        dial = new QDial(rotateo);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMaximum(90);

        gridLayout->addWidget(dial, 3, 1, 1, 1);

        dial_2 = new QDial(rotateo);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setMaximum(90);

        gridLayout->addWidget(dial_2, 5, 1, 1, 1);

        dial_3 = new QDial(rotateo);
        dial_3->setObjectName(QString::fromUtf8("dial_3"));
        dial_3->setMaximum(90);

        gridLayout->addWidget(dial_3, 7, 1, 1, 1);

        label = new QLabel(rotateo);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 6, 1, 1, 1);

        label_2 = new QLabel(rotateo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 1, 1, 1);

        label_4 = new QLabel(rotateo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_3 = new QLabel(rotateo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);


        retranslateUi(rotateo);

        QMetaObject::connectSlotsByName(rotateo);
    } // setupUi

    void retranslateUi(QDialog *rotateo)
    {
        rotateo->setWindowTitle(QApplication::translate("rotateo", "Rotate", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("rotateo", "OK", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("rotateo", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("rotateo", "Z Angle:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("rotateo", "Y Angle:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("rotateo", "Rotation around Axis:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("rotateo", "X Angle:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rotateo: public Ui_rotateo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEO_H
