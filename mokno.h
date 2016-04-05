#ifndef MOKNO_H
#define MOKNO_H

#include <QMainWindow>
#include <QtWidgets>
#include "gokno.h"

class Mokno : public QMainWindow
{
    Q_OBJECT

    private slots:
        void serverButton();
        void clientButton();

    private:
        QLineEdit *ip_text;
        Gokno *gokno;

    public:
        explicit Mokno(QWidget *parent = 0);
        ~Mokno();
};

#endif
