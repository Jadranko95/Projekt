#include "mokno.h"
#include "gokno.h"
#include <QCoreApplication>

Mokno::Mokno(QWidget *parent): QMainWindow(parent)
{
        // wstępne ustawienia okna
    this->resize(300, 300);

        // przyciski i editbox z adresem
    QPushButton *server_button = new QPushButton(this);
    server_button->setText(tr("Server"));
    server_button->setMinimumSize(QSize(100, 25));
    server_button->move(QPoint(100, 25));
    connect(server_button, SIGNAL(clicked()), this, SLOT(serverButton()));

    QPushButton *client_button = new QPushButton(this);
    client_button->setText(tr("Client"));
    client_button->setMinimumSize(QSize(100, 25));
    client_button->move(QPoint(100, 75));
    connect(client_button, SIGNAL(clicked()), this, SLOT(clientButton()));

    this->ip_text = new QLineEdit(this);
    this->ip_text->setMinimumWidth(150);
    this->ip_text->move(75, 125);
    this->ip_text->setText(tr("127.0.0.1"));

    this->gokno = new Gokno();
}

Mokno::~Mokno()
{
    delete gokno;
}

void Mokno::serverButton()
{
    this->ip_text->setText(tr("i'm server motherfuckers!!!"));
}

void Mokno::clientButton()
{
    gokno->show();
}
