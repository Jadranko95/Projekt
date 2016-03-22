#include "obiekt.h"

Obiekt::Obiekt(RODZAJ_OBIEKTU rodzaj, Gokno* gokno):
    QGraphicsObject(), x_Rodzaj(rodzaj), x_Gokno(gokno)
{
}

RODZAJ_OBIEKTU Obiekt::Pobierz_Rodzaj()
{
    return this->x_Rodzaj;
}
