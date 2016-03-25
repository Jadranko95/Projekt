#ifndef GRACZ_H
#define GRACZ_H

#include <QTimer>
#include "mysz.h"

class Gracz : public Mysz
{
    Q_OBJECT

    private:

        bool x_Nitro;
        bool x_Mysz_Wypoczeta;
        QTimer* x_Licznik_Zmeczenia;

    private slots:

        void Odpoczynek();

    protected:

        void timerEvent(QTimerEvent*);

    public:

        Gracz(Gokno* gokno);

        void Start_Prawo();
        void Start_Lewo();
        void Start_Predkosc();
        void Start_Nitro();

        void Stop_Kierunek();
        void Stop_Predkosc();
        void Stop_Nitro();

};

#endif
