#ifndef OBIEKT_H
#define OBIEKT_H

#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static const double Dwa_Pi = 2.0 * Pi;

enum RODZAJ_OBIEKTU
{
    MYSZ,
    SER,
    SCIANA,
    CIEN,
    OBIEKT
};

class Gokno;
class Mapa;

class Obiekt : public QGraphicsObject
{
    Q_OBJECT

    protected:

        RODZAJ_OBIEKTU x_Rodzaj;
        Gokno* x_Gokno;

    public:

        Obiekt(RODZAJ_OBIEKTU rodzaj, Gokno* gokno);
        RODZAJ_OBIEKTU Pobierz_Rodzaj();

};

#endif
