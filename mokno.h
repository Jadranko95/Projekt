#ifndef MOKNO_H
#define MOKNO_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>
#include <QtWidgets>

#include "gokno.h"

class Mokno : public QMainWindow
{
    Q_OBJECT

    private slots:
        void serverButton();
        void clientButton();
        void testButton();

        void otwarcieSesjiSerwera();
        void wyslijDoKlienta();

    private:
        QPushButton *server_button;
        QPushButton *client_button;
        QLineEdit *ip_text;
        Gokno *gokno;

        QTcpServer *tcpServer;
        QTcpSocket *tcpSocket;
        QNetworkSession *networkSession;
        quint16 blockSize;

    public:
        explicit Mokno(QWidget *parent = 0);
        ~Mokno();
};

#endif
