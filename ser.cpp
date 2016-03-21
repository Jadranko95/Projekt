#include "ser.h"

Ser::Ser(): QGraphicsObject()
{

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
    QPixmap tlo(":/images/cheese.jpg");
    painter->setBrush(QBrush(tlo.scaled(20, 20)));
    painter->drawRect(-10, -10, 20, 20);
}
