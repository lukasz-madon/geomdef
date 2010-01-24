#include "TestRotateValues.h"
#include <QFile>
#include <cmath>

TestRotateValues::TestRotateValues(const QString &str,const double angle,const int i, const int j) : condition(false)
{
    file = new QFile(str);
    if (!file->open(QIODevice::WriteOnly | QIODevice::Text))
             return;

    out.setDevice(file);

    ival = i;
    jval = j;
    ang = (int)angle;
//{30, 60, 90, 120, 150, 180}
    //{40, 80, 120, 160, 200, 240}

}

TestRotateValues::~TestRotateValues() {
    file->close();
}

void TestRotateValues::printfA(const int angle) {

        if(angle == ang && angle == ang) {
    out << "Kat: " << angle << "\n";
    out.flush();

    }
}

void TestRotateValues::printfV(const int bx, const double ax,const int by,const double ay,const int z, const int k) {

    if(ang == 1 && by == 160) {

        out << "i " << bx << " " << ax << " j " << by << " " << ay << " " << z << " " << k << "\n";
        out.flush();
        condition = true;

    }
}
