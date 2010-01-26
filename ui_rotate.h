/********************************************************************************
** Form generated from reading UI file 'rotate.ui'
**
** Created: Tue 26. Jan 01:16:58 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATE_H
#define UI_ROTATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_rotate
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLabel *label;
    QDial *dial;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBox;

    void setupUi(QDialog *rotate)
    {
        if (rotate->objectName().isEmpty())
            rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->resize(610, 360);
        gridLayout = new QGridLayout(rotate);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(rotate);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 9, 1);

        pushButton = new QPushButton(rotate);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 8, 2, 1, 1);

        pushButton_2 = new QPushButton(rotate);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 2, 1, 1);

        label_2 = new QLabel(rotate);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(rotate);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        dial = new QDial(rotate);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setAutoFillBackground(false);
        dial->setMaximum(360);

        gridLayout->addWidget(dial, 2, 2, 1, 1);

        groupBox = new QGroupBox(rotate);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 20, 91, 20));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 50, 91, 20));

        gridLayout->addWidget(groupBox, 4, 2, 3, 1);

        spinBox = new QSpinBox(rotate);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(360);

        gridLayout->addWidget(spinBox, 3, 2, 1, 1);


        retranslateUi(rotate);
        QObject::connect(pushButton_2, SIGNAL(clicked()), rotate, SLOT(rotateOKSlot()));
        QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(rotate);
    } // setupUi

    void retranslateUi(QDialog *rotate)
    {
        rotate->setWindowTitle(QApplication::translate("rotate", "Rotate", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("rotate", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("rotate", "OK", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("rotate", "Rotation around Point:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("rotate", "Angle:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("rotate", "Rotate Point", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("rotate", "0", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("rotate", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rotate: public Ui_rotate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATE_H
