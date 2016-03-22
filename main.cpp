#include "gokno.h"

#include <QtWidgets>
#include <ctime>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    srand(time(NULL));

    Gokno gokno;
    gokno.show();

    return app.exec();
}
