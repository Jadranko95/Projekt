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
    QPixmap tlo(":/images/stol.jpg");
    painter->setBrush(QBrush(tlo.scaled(this->x_Wymiary.width(),
                                        this->x_Wymiary.height())));

    //painter->setBrush(QBrush(QColor(0, 0, 0, 25)));
    //painter->setPen(QColor(0, 0, 0, 25));
    painter->setOpacity(0.2);
    painter->drawRect(this->x_Wymiary);
}
