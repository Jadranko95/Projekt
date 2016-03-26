#include "mysz.h"
#include "gokno.h"

Mysz::Mysz(Gokno* gokno): Obiekt(MYSZ, gokno), x_Kat(0), x_Predkosc(0),
    x_Kierunek_Oczu(0), x_Kolor(rand() % 256, rand() % 256, rand() % 256)
{
    this->setTransform(QTransform().rotate(rand() % (360 * 16)), true);
    this->startTimer(1000 / 33);
}

void Mysz::timerEvent(QTimerEvent *)
{
}

void Mysz::Kolizja()
{
    if(this->scene()->collidingItems(this).isEmpty())
        return;

        // pobranie wszystkich kolizji
    QList<QGraphicsItem*> obiekty = this->scene()->collidingItems(this);

        // przeszukiwanie wszystkich kolizji
    foreach(QGraphicsItem* obiekt, obiekty)
    {
            // kolizja z obiektem
        switch(static_cast<Obiekt*>(obiekt)->Pobierz_Rodzaj())
        {
            case SER:
                static_cast<Ser*>(obiekt)->Dodaj_Ser();
                break;

            case CIEN: // po cieniu może chodzić
                break;

            default: // cofa i zatrzymuje mysz
                this->setPos(mapToParent(0, 15));
                this->x_Predkosc = 0;
                break;
        }
    }
}

QRectF Mysz::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}

QPainterPath Mysz::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 20);
    return path;
}

void Mysz::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
        // ciało
    painter->setBrush(x_Kolor);
    painter->drawEllipse(-10, -20, 20, 40);

        // oczy
    painter->setBrush(Qt::white);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

        // nos
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(-2, -22, 4, 4));

        // źrenice
    painter->drawEllipse(QRectF(-8.0 + this->x_Kierunek_Oczu, -17, 4, 4));
    painter->drawEllipse(QRectF(4.0 + this->x_Kierunek_Oczu, -17, 4, 4));

        // uszy
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::darkGray);
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);

        // ogon
    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
}
