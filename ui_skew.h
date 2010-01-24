/********************************************************************************
** Form generated from reading UI file 'skew.ui'
**
** Created: Wed 20. Jan 20:57:54 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKEW_H
#define UI_SKEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_skew
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QDial *dial;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QDial *dial_2;
    QSpinBox *spinBox_2;

    void setupUi(QDialog *skew)
    {
        if (skew->objectName().isEmpty())
            skew->setObjectName(QString::fromUtf8("skew"));
        skew->resize(622, 369);
        gridLayout_2 = new QGridLayout(skew);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(skew);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 6, 1);

        dial = new QDial(skew);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setAutoFillBackground(false);

        gridLayout->addWidget(dial, 0, 1, 1, 1);

        spinBox = new QSpinBox(skew);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 3, 1, 1, 1);

        pushButton_2 = new QPushButton(skew);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton = new QPushButton(skew);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 5, 1, 1, 1);

        dial_2 = new QDial(skew);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));

        gridLayout->addWidget(dial_2, 1, 1, 1, 1);

        spinBox_2 = new QSpinBox(skew);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(skew);

        QMetaObject::connectSlotsByName(skew);
    } // setupUi

    void retranslateUi(QDialog *skew)
    {
        skew->setWindowTitle(QApplication::translate("skew", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("skew", "OK", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("skew", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class skew: public Ui_skew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKEW_H
