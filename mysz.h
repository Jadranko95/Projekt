#ifndef MYSZ_H
#define MYSZ_H

#include "obiekt.h"

class Mysz : public Obiekt
{
    Q_OBJECT

    protected:

        qreal x_Kat; // kąt
        qreal x_Predkosc;
        qreal x_Kierunek_Oczu;
        QColor x_Kolor;

        virtual void timerEvent(QTimerEvent *event);
        void Kolizja();

    public:

        Mysz(Gokno* gokno);

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem*,
                   QWidget*);

};

#endif
