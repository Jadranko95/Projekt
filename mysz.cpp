#include "mysz.h"
#include "gokno.h"

Mysz::Mysz(Gokno* gokno): Obiekt(MYSZ, gokno), x_Kat(0), x_Predkosc(0),
    x_Kierunek_Oczu(0), x_Kolor(qrand() % 256, qrand() % 256, qrand() % 256)
{
    this->setTransform(QTransform().rotate(qrand() % (360 * 16)), true);
    this->startTimer(1000 / 33);
}

void Mysz::timerEvent(QTimerEvent *)
{
}

void Mysz::Kolizja()
{
    if(!this->scene()->collidingItems(this).isEmpty())
    {
        /*QList<QGraphicsItem*> obiekty = this->scene()->collidingItems(this);

        foreach(QGraphicsItem* obiekt, obiekty)
            if(static_cast<Obiekt*>(obiekt)->Pobierz_Rodzaj() == SER)
                this->x_Gokno->Dodaj_Ser();*/

        this->setPos(mapToParent(0, 15));
        this->x_Predkosc = 0;
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
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
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
