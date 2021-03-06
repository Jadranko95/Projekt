#ifndef SER_H
#define SER_H

#include "obiekt.h"

class Ser: public Obiekt
{
    Q_OBJECT

    private:

        QRect x_Obszar;

        void Kolizja();

    public:

        Ser(Gokno* gokno);

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

        void Ustaw_Obszar(QRect obszar);
        void Dodaj_Ser();

};

#endif
