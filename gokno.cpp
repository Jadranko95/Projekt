#include "gokno.h"

Gokno::Gokno()
{
        // wstępne ustawienia okna
    this->setRenderHint(QPainter::Antialiasing);
    this->setCacheMode(QGraphicsView::CacheBackground);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

        // budowanie sceny
    this->x_Scena = new QGraphicsScene;
    this->x_Scena->setSceneRect(-300, -300, 600, 600);

        // tworzenie gracza
    this->x_Gracz = new Gracz;
    this->x_Scena->addItem(this->x_Gracz);
    this->Dodaj_Ser();

    this->setScene(this->x_Scena);
}

void Gokno::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Up:
            this->x_Gracz->Start_Predkosc();
            break;

        case Qt::Key_Left:
            this->x_Gracz->Start_Lewo();
            break;

        case Qt::Key_Right:
            this->x_Gracz->Start_Prawo();
            break;

        case Qt::Key_Down:
            break;

        case Qt::Key_Shift:
            this->x_Gracz->Start_Nitro();
            break;

        case Qt::Key_Escape:
            this->close();
            break;
    }
}

void Gokno::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Up:
            this->x_Gracz->Stop_Predkosc();
            break;

        case Qt::Key_Left:
            this->x_Gracz->Stop_Kierunek();
            break;

        case Qt::Key_Right:
            this->x_Gracz->Stop_Kierunek();
            break;

        case Qt::Key_Down:
            break;

        case Qt::Key_Shift:
            this->x_Gracz->Stop_Nitro();
            break;
    }
}

void Gokno::Dodaj_Ser()
{
    Ser* ser = new Ser;
    ser->setPos(250 - rand() % 500, 250 - rand() % 500);
    this->x_Scena->addItem(ser);
}
