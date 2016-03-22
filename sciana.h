#ifndef SCIANA_H
#define SCIANA_H

#include "obiekt.h"

class Sciana : public Obiekt
{
    Q_OBJECT

    private:

        QRect x_Wymiary;

    public:

        Sciana(Gokno* gokno, QRect wymiary);

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

};

#endif
