#ifndef MAPA_H
#define MAPA_H

#include "sciana.h"
#include "cien.h"
#include "ser.h"

enum RODZAJ_MAPY
{
    PUDELKO,
    POD_STOLEM,
    BRAK
};

class Mapa
{

    private:

        RODZAJ_MAPY x_Mapa;
        Gokno* x_Gokno;
        QGraphicsScene* x_Scena;
        Ser* x_Ser;

        void Wczytaj_Mape();
        void Mapa_Pudelko();
        void Mapa_Pod_Stolem();

    public:

        Mapa(Gokno* gokno);
        void Wybierz_Mape(RODZAJ_MAPY mapa);

};

#endif
