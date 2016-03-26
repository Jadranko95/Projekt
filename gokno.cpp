#include "gokno.h"

Gokno::Gokno(): QGraphicsView()
{
        // wstępne ustawienia okna
    this->setRenderHint(QPainter::Antialiasing);
    this->setCacheMode(QGraphicsView::CacheBackground);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->resize(1280, 720);

        // budowanie sceny
    this->x_Scena = new QGraphicsScene;
    this->x_Scena->setSceneRect(-625, -350, 1250, 700);
    this->x_Mapa = new Mapa(this);
    this->x_Mapa->Wybierz_Mape(POD_STOLEM);

        // tworzenie gracza
    this->x_Gracz = new Gracz(this);
    this->x_Scena->addItem(this->x_Gracz);

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

QGraphicsScene* Gokno::Pobierz_Scene()
{
    return this->x_Scena;
}
