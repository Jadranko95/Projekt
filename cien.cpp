#include "cien.h"

Cien::Cien(Gokno* gokno, QRect wymiary):
    Obiekt(CIEN, gokno), x_Wymiary(wymiary)
{
}

QRectF Cien::boundingRect() const
{
    return QRectF(this->x_Wymiary);
}

QPainterPath Cien::shape() const
{
    QPainterPath path;
    path.addRect(this->x_Wymiary);
    return path;
}

void Cien::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
        // jeżeli podany obrazek
    if(!this->x_Tlo.isEmpty())
    {
        QPixmap tlo(this->x_Tlo);
        painter->setBrush(QBrush(tlo.scaled(this->x_Wymiary.width(),
                                            this->x_Wymiary.height())));
    }
    else
    {
        painter->setBrush(QBrush(QColor(0, 0, 0)));
        painter->setPen(QColor(0, 0, 0, 0));
    }

    painter->setOpacity(0.2);
    painter->drawRect(this->x_Wymiary);
}

void Cien::Ustaw_Tlo(QString obrazek)
{
    this->x_Tlo = obrazek;
}
