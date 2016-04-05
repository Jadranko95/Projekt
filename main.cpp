#include "gokno.h"
#include "mokno.h"

#include <QtWidgets>
#include <ctime>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    srand(time(NULL));

    Mokno mokno;
    mokno.show();

    return app.exec();
}
