#ifndef SER_H
#define SER_H

#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

class Ser: public QGraphicsObject
{

    protected:

    public:

        Ser();

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

};

#endif
