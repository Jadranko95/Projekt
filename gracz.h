#ifndef GRACZ_H
#define GRACZ_H

#include "mysz.h"

class Gracz : public Mysz
{
    Q_OBJECT

    private:

        bool x_Nitro;

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
