#include "gracz.h"

Gracz::Gracz(Gokno* gokno): Mysz(gokno),
    x_Nitro(false), x_Mysz_Wypoczeta(true)
{
    this->x_Licznik_Zmeczenia = new QTimer;
    QObject::connect(this->x_Licznik_Zmeczenia, SIGNAL(timeout()),
                     this, SLOT(Odpoczynek()));
}

void Gracz::Odpoczynek()
{
    this->x_Mysz_Wypoczeta = !this->x_Mysz_Wypoczeta;
    this->x_Licznik_Zmeczenia->stop();
}

void Gracz::timerEvent(QTimerEvent*)
{
    this->setTransform(QTransform().rotate(this->x_Kat), true);
    this->Kolizja();

    if(this->x_Mysz_Wypoczeta)
        if(this->x_Nitro)
            this->setPos(mapToParent(0, -this->x_Predkosc));

    this->setPos(mapToParent(0, -this->x_Predkosc));
}


    // START
void Gracz::Start_Prawo()
{
    this->x_Kat = 15;
}

void Gracz::Start_Lewo()
{
    this->x_Kat = -15;
}

void Gracz::Start_Predkosc()
{
    this->x_Predkosc = 9;
}

void Gracz::Start_Nitro()
{
        // jeżeli wykonuje bieg lub odpoczynek
    if(this->x_Licznik_Zmeczenia->isActive())
        return;

        // pełna sił na nitro
    if(this->x_Mysz_Wypoczeta)
        this->x_Licznik_Zmeczenia->start(500);

    this->x_Nitro = true;
}


    // STOP
void Gracz::Stop_Kierunek()
{
    this->x_Kat = 0;
}

void Gracz::Stop_Predkosc()
{
    this->x_Predkosc = 0;
}

void Gracz::Stop_Nitro()
{
        // mysz biegła ile sił w nogach
    if(this->x_Mysz_Wypoczeta == false)
    {
        if(this->x_Licznik_Zmeczenia->isActive() == false)
            this->x_Licznik_Zmeczenia->start(5000);
    }
    else
    {
            // mysz zatrzymała się przed zakończeniem
            // czasu na nitro
        this->x_Licznik_Zmeczenia->stop();
        this->x_Mysz_Wypoczeta = false;
        this->x_Licznik_Zmeczenia->start(5000);
    }

    this->x_Nitro = false;
}
