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
        void otwarcieSesjiKlienta();
        void wyslijWiadomosc();
        void odczytajWiadomosc();

    private:
        QPushButton *server_button;
        QPushButton *client_button;
        QLineEdit *ip_text;
        Gokno *gokno;

        QTcpServer *tcpServer;
        QTcpSocket *tcpSocket;
        QNetworkSession *networkSession;
        quint16 blockSize;
        QString ipAddress;

    public:
        explicit Mokno(QWidget *parent = 0);
        ~Mokno();
};

#endif
