#include "gracz.h"

Gracz::Gracz(): Mysz(), x_Nitro(false)
{
}

void Gracz::timerEvent(QTimerEvent*)
{
    this->setTransform(QTransform().rotate(this->x_Kat), true);
    this->Kolizja();

    if(this->x_Nitro)
        this->setPos(mapToParent(0, -this->x_Predkosc * 3));

    else this->setPos(mapToParent(0, -this->x_Predkosc));
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
    this->x_Predkosc = 3;
}

void Gracz::Start_Nitro()
{
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
    this->x_Nitro = false;
}
