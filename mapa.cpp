#include "mapa.h"
#include "gokno.h"

Mapa::Mapa(Gokno* gokno):
    x_Gokno(gokno), x_Mapa(BRAK)
{
    this->x_Scena = this->x_Gokno->Pobierz_Scene();

    this->x_Ser = new Ser(this->x_Gokno);
    this->x_Scena->addItem(this->x_Ser);
}

void Mapa::Wczytaj_Mape()
{
    switch (this->x_Mapa)
    {
        case PUDELKO:
            this->Mapa_Pudelko();
            break;

        default:
            break;
    }
}

void Mapa::Mapa_Pudelko()
{
        // tworzenie ścian
    Sciana* lewa = new Sciana(this->x_Gokno, QRect(0, 0, 10, 500));
    lewa->setPos(-250, -250);
    this->x_Scena->addItem(lewa);

    Sciana* prawa = new Sciana(this->x_Gokno, QRect(0, 0, 10, 500));
    prawa->setPos(250, -240);
    this->x_Scena->addItem(prawa);

    Sciana* gorna = new Sciana(this->x_Gokno, QRect(0, 0, 500, 10));
    gorna->setPos(-240, -250);
    this->x_Scena->addItem(gorna);

    Sciana* dolna = new Sciana(this->x_Gokno, QRect(0, 0, 500, 10));
    dolna->setPos(-250, 250);
    this->x_Scena->addItem(dolna);

        // ustawienie obszaru dla sera
    this->x_Ser->Ustaw_Obszar(QRect(-230, -230, 460, 460));
}

// więcej map...

void Mapa::Wybierz_Mape(RODZAJ_MAPY mapa)
{
    this->x_Mapa = mapa;
    this->Wczytaj_Mape();
}
