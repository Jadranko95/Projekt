#ifndef MYSZ_H
#define MYSZ_H

#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QKeyEvent>

#include <math.h>

static const double Pi = 3.14159265358979323846264338327950288419717;
static const double Dwa_Pi = 2.0 * Pi;

class Mysz : public QGraphicsObject
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

        Mysz();

        QRectF boundingRect() const;
        QPainterPath shape() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

};

#endif
