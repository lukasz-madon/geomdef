/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created: Mon 1. Feb 02:44:04 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(315, 246);
        about->setMinimumSize(QSize(315, 246));
        about->setMaximumSize(QSize(315, 246));
        about->setBaseSize(QSize(0, 0));
        pushButton = new QPushButton(about);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 210, 75, 23));
        label = new QLabel(about);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 111, 16));
        label_2 = new QLabel(about);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 40, 271, 16));
        label_3 = new QLabel(about);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 170, 81, 16));
        label_4 = new QLabel(about);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 170, 81, 16));
        label_5 = new QLabel(about);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 170, 81, 16));
        label_6 = new QLabel(about);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 80, 251, 81));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/image/logo")));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "About", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("about", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("about", "Geometric Deformation", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("about", "Geomdef v900000.56.7 kompilacja 78 (bata gamma)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("about", "Daniel Matras", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("about", "\305\201ukasz Mado\305\204", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("about", "Grzegorz Kurek", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
