#include "mokno.h"

Mokno::Mokno(QWidget *parent): QMainWindow(parent)
{
        // wstępne ustawienia okna
    this->resize(300, 300);

        // przyciski i editbox z adresem
    this->server_button = new QPushButton(this);
    this->server_button->setText(tr("Server"));
    this->server_button->setMinimumSize(QSize(100, 25));
    this->server_button->move(QPoint(100, 25));
    connect(this->server_button, SIGNAL(clicked()), this, SLOT(serverButton()));

    this->client_button = new QPushButton(this);
    this->client_button->setText(tr("Client"));
    this->client_button->setMinimumSize(QSize(100, 25));
    this->client_button->move(QPoint(100, 75));
    connect(this->client_button, SIGNAL(clicked()), this, SLOT(clientButton()));

    QPushButton *test_button = new QPushButton(this);
    test_button->setText(tr("Testowa mapa"));
    test_button->setMinimumSize(QSize(100, 25));
    test_button->move(QPoint(100, 125));
    connect(test_button, SIGNAL(clicked()), this, SLOT(testButton()));

    this->ip_text = new QLineEdit(this);
    this->ip_text->setMinimumWidth(150);
    this->ip_text->move(75, 175);
    this->ip_text->setText(tr("127.0.0.1"));

    this->gokno = new Gokno();
}

Mokno::~Mokno()
{
    delete gokno;
}

void Mokno::serverButton()
{
    this->ip_text->setText(tr("serwer"));
    this->client_button->setEnabled(false);

    // ustawianie serwera
    QNetworkConfigurationManager manager;

    // Get saved network configuration
    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
    settings.endGroup();

    // If the saved network configuration is not currently discovered use the system default
    QNetworkConfiguration config = manager.configurationFromIdentifier(id);
    if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
    {
        config = manager.defaultConfiguration();
    }

    this->networkSession = new QNetworkSession(config, this);
    connect(this->networkSession, &QNetworkSession::opened, this, &Mokno::otwarcieSesjiSerwera);

    this->networkSession->open();

    connect(this->tcpServer, &QTcpServer::newConnection, this, &Mokno::wyslijDoKlienta);
}

void Mokno::clientButton()
{
    ip_text->setText(tr("klient"));
    this->server_button->setEnabled(false);
}

void Mokno::testButton()
{
    gokno->show();
}

void Mokno::otwarcieSesjiSerwera()
{
    // Save the used configuration
    if (this->networkSession)
    {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
        {
            id = this->networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        }
        else
        {
            id = config.identifier();
        }

        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
        settings.endGroup();
    }

    this->tcpServer = new QTcpServer(this);
    if (!this->tcpServer->listen())
    {
        QMessageBox::critical(this, tr("Projekt"), tr("Nie można utworzyć serwera: %1.").arg(this->tcpServer->errorString()));
        close();
        return;
    }

    this->ip_text->setText(tr("adres %1:%2").arg("127.0.0.1").arg(tcpServer->serverPort()));
}

void Mokno::wyslijDoKlienta()
{

}
