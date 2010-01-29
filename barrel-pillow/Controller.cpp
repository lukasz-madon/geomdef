//////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \file ControllerXML.cpp
/// \author Lukasz Madon
/// \author 7madon@novell.ftj.agh.edu.pl OR lukasgt@wp.pl
/// \version 1.0.1
/// \date 16-01-2010
/// \brief Defnicja metod klasy ControllerXML sluzacej do odczytu danych z pliku i parametrow. Plik zrodlowy.
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QtXml>
#include <QFile>

#include "ControllerXML.h"

//////////////////////////////////////////////////////////////////////////
// Konstruktor ktory wczytuje plik cameras.xml z parametrami obiektywów.
//////////////////////////////////////////////////////////////////////////
ControllerXML::ControllerXML()
{
        // plik z parametrami obiektywow
        QString fileName = "cameras.xml";
        doc = new QDomDocument( "cameras" );
        QFile file( fileName );

        // sprawdza czy plik istnieje
        if ( !file.open( QIODevice::ReadOnly ) )
        {
            QMessageBox::information(0, "FILE",QString("Cannot load %1.").arg(fileName));
            return;
        }

        // sprawdza czy to jest XML
        if ( !doc->setContent( &file ) )
        {
            QMessageBox::information(0, "FILE",QString("%1 - parser error").arg(fileName));
            file.close();
            return;
        }
        file.close();

        QDomElement docElem = doc->documentElement();
        QDomNode n = docElem.firstChild();

        // petla przeszukuje kolejne galezie w poszukiwaniu znacznika <title>
        while( !n.isNull() )
        {
            QDomElement e = n.toElement();
            QDomElement t;
            if( !e.isNull() )
            {
               // pobiera title
               t = e.firstChildElement("title");
               /// zapisuje go do wektora names
               names.append(t.text());
            }
            n = n.nextSibling();
        }
        // sortowanie nazw
        names.sort();
}

//////////////////////////////////////////////////////////////////////////
// Destruktor. Kasuje wczytanego XMLa.
//////////////////////////////////////////////////////////////////////////
ControllerXML::~ControllerXML()
{
    delete doc;
}

//////////////////////////////////////////////////////////////////////////
// Definicja funkcji pobierajacej parametry z XMLa
//////////////////////////////////////////////////////////////////////////
qreal* ControllerXML::getParams(QString name)
{

    QDomElement docElem = doc->documentElement();
    QDomNode n = docElem.firstChild();
    bool end = 1;

    // petla przeszukuje kolejne galezie w poszukiwaniu opowiedniego obiektywu
    while( !n.isNull() && end )
    {
      if ( n.isElement() ) // w przypadku gdyby byl pusty wezel
        {
        QDomElement e = n.toElement();
        QDomElement t;
        t = e.firstChildElement("title");
        QString d = t.text();
        // sprawdza
        if(name == d)
        {
           // pobiera parametry
           t = e.firstChildElement("a");
           params[0] = t.text().toDouble();
           t = e.firstChildElement("b");
           params[1] = t.text().toDouble();
           t = e.firstChildElement("c");
           params[2] = t.text().toDouble();
           t = e.firstChildElement("d");
           params[3] = t.text().toDouble();

           // koniec petli
            end = 0;

        }

            n = n.nextSibling();
        }

    }

    return params;
}
