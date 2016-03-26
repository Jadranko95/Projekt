#ifndef CIEN_H
#define CIEN_H

#include "obiekt.h"

class Cien : public Obiekt
{
    Q_OBJECT

    private:

        QRect x_Wymiary;

    public:

        Cien(Gokno* gokno, QRect wymiary);

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

};

#endif
