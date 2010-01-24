#ifndef TESTROTATEVALUES_H
#define TESTROTATEVALUES_H

#include <QObject>

#include <QTextStream>

class QFile;

class TestRotateValues : public QObject
{
public:
    TestRotateValues(const QString &str,const double angle,const int i, const int j);
    ~TestRotateValues();
    void printfA(const int angle);
    void printfV(const int bx, const double ax,const int by,const double ay,const int z,const int k);
private:
    QFile *file;
    QTextStream out;
    int ival,jval;
    int ang;
    bool condition;
};

#endif // TESTROTATEVALUES_H
