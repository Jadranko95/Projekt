#include "ser.h"
#include "gokno.h"
#include "mapa.h"

Ser::Ser(Gokno* gokno): Obiekt(SER, gokno)
{
}

void Ser::Kolizja()
{
        // sprawdzanie kolizji
    QList<QGraphicsItem*> obiekty = this->scene()->collidingItems(this);

    if(!obiekty.isEmpty())
    {
        foreach (QGraphicsItem* obiekt, obiekty)
        {
                // jeżeli jest myszą
            if(static_cast<Obiekt*>(obiekt)->Pobierz_Rodzaj() == MYSZ)
                ;//static_cast<Gracz*>(obiekt)->Stop_Predkosc();
        }

        this->Dodaj_Ser();
    }
}

QRectF Ser::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}

QPainterPath Ser::shape() const
{
    QPainterPath path;
    path.addRect(-10, -10, 20, 20);
    return path;
}

void Ser::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
        // tworzenie sera
    QPixmap tlo(":/images/cheese.jpg");
    painter->setBrush(QBrush(tlo.scaled(20, 20)));
    painter->drawRect(-10, -10, 20, 20);

    this->Kolizja();
}

void Ser::Ustaw_Obszar(QRect obszar)
{
    this->x_Obszar = obszar;
    this->Dodaj_Ser();
}

void Ser::Dodaj_Ser()
{
    this->setPos(this->x_Obszar.left() + rand() % this->x_Obszar.width(),
                 this->x_Obszar.top() + rand() % this->x_Obszar.height());
}
