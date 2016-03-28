#include "sciana.h"

Sciana::Sciana(Gokno* gokno, QRect wymiary):
    Obiekt(SCIANA, gokno), x_Wymiary(wymiary)
{
}

QRectF Sciana::boundingRect() const
{
    return QRectF(this->x_Wymiary);
}

QPainterPath Sciana::shape() const
{
    QPainterPath path;
    path.addRect(this->x_Wymiary);
    return path;
}

void Sciana::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawRect(this->x_Wymiary);
}
