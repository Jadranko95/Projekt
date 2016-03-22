#ifndef GOKNO_H
#define GOKNO_H

#include "gracz.h"
#include "mapa.h"

#include <QGraphicsView>
#include <QScrollBar>
#include <QTouchEvent>

class Gokno : public QGraphicsView
{
    Q_OBJECT

    private:

        QGraphicsScene* x_Scena;
        Gracz* x_Gracz;
        Mapa* x_Mapa;

    protected:

        void keyPressEvent(QKeyEvent* event);
        void keyReleaseEvent(QKeyEvent* event);

    public:

        Gokno();
        QGraphicsScene* Pobierz_Scene();

};

#endif
