/********************************************************************************
** Form generated from reading UI file 'skewdialog.ui'
**
** Created: Sun 31. Jan 21:29:31 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKEWDIALOG_H
#define UI_SKEWDIALOG_H

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
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_skewdialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QDial *dial_2;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QDial *dial;

    void setupUi(QDialog *skewdialog)
    {
        if (skewdialog->objectName().isEmpty())
            skewdialog->setObjectName(QString::fromUtf8("skewdialog"));
        skewdialog->resize(556, 353);
        gridLayout_2 = new QGridLayout(skewdialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(skewdialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 9, 1);

        dial_2 = new QDial(skewdialog);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setMaximum(50);

        gridLayout->addWidget(dial_2, 4, 1, 1, 1);

        spinBox_2 = new QSpinBox(skewdialog);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(50);

        gridLayout->addWidget(spinBox_2, 5, 1, 1, 1);

        spinBox = new QSpinBox(skewdialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(50);

        gridLayout->addWidget(spinBox, 6, 1, 1, 1);

        pushButton_2 = new QPushButton(skewdialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 1, 1, 1);

        pushButton = new QPushButton(skewdialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 8, 1, 1, 1);

        label = new QLabel(skewdialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 1, 1, 1);

        label_2 = new QLabel(skewdialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        dial = new QDial(skewdialog);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setAutoFillBackground(false);
        dial->setMaximum(50);

        gridLayout->addWidget(dial, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(skewdialog);
        QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(dial_2, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial_2, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(skewdialog);
    } // setupUi

    void retranslateUi(QDialog *skewdialog)
    {
        skewdialog->setWindowTitle(QApplication::translate("skewdialog", "Skew", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("skewdialog", "OK", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("skewdialog", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("skewdialog", "Y:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("skewdialog", "X:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class skewdialog: public Ui_skewdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKEWDIALOG_H
