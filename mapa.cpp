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

        case POD_STOLEM:
            this->Mapa_Pod_Stolem();
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

void Mapa::Mapa_Pod_Stolem()
{
        // tworzenie ścian
    Sciana* lewa = new Sciana(this->x_Gokno, QRect(0, 0, 10, 600));
    lewa->setPos(-550, -300);
    this->x_Scena->addItem(lewa);

    Sciana* prawa = new Sciana(this->x_Gokno, QRect(0, 0, 10, 600));
    prawa->setPos(550, -290);
    this->x_Scena->addItem(prawa);

    Sciana* gorna = new Sciana(this->x_Gokno, QRect(0, 0, 1100, 10));
    gorna->setPos(-540, -300);
    this->x_Scena->addItem(gorna);

    Sciana* dolna = new Sciana(this->x_Gokno, QRect(0, 0, 1100, 10));
    dolna->setPos(-550, 300);
    this->x_Scena->addItem(dolna);

        // tworzenie nóg stołu
    Sciana* pierwsza_noga = new Sciana(this->x_Gokno, QRect(-15, -15, 30, 30));
    pierwsza_noga->setPos(-220 + 150, -150 - 65);
    this->x_Scena->addItem(pierwsza_noga);

    Sciana* druga_noga = new Sciana(this->x_Gokno, QRect(-15, -15, 30, 30));
    druga_noga->setPos(220 + 150, -150 - 65);
    this->x_Scena->addItem(druga_noga);

    Sciana* trzecia_noga = new Sciana(this->x_Gokno, QRect(-15, -15, 30, 30));
    trzecia_noga->setPos(-220 + 150, 150 - 65);
    this->x_Scena->addItem(trzecia_noga);

    Sciana* czwarta_noga = new Sciana(this->x_Gokno, QRect(-15, -15, 30, 30));
    czwarta_noga->setPos(220 + 150, 150 - 65);
    this->x_Scena->addItem(czwarta_noga);

        // tworzenie cienia stołu
    Cien* cien_stolu = new Cien(this->x_Gokno, QRect(-400, -225, 800, 450));
    cien_stolu->setPos(150, -65);
    this->x_Scena->addItem(cien_stolu);

        // ustawienie obszaru dla sera
    this->x_Ser->Ustaw_Obszar(QRect(-550, -300, 1100, 600));
}

// więcej map...

void Mapa::Wybierz_Mape(RODZAJ_MAPY mapa)
{
    this->x_Mapa = mapa;
    this->Wczytaj_Mape();
}
