#include "ser.h"
#include "gokno.h"
#include "mapa.h"

Ser::Ser(Gokno* gokno): Obiekt(SER, gokno)
{
}

void Ser::Kolizja()
{
    if(this->scene()->collidingItems(this).isEmpty())
        return;

        // pobranie wszystkich kolizji
    QList<QGraphicsItem*> obiekty = this->scene()->collidingItems(this);

        // przeszukiwanie wszystkich kolizji
    foreach (QGraphicsItem* obiekt, obiekty)
    {
            // kolizja z obiektem
        switch(static_cast<Obiekt*>(obiekt)->Pobierz_Rodzaj())
        {
            case MYSZ:
                break;

            case CIEN:
                break;

            default: // inne przedmioty
                this->Dodaj_Ser();
                break;
        }
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
