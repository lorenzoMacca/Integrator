#include "gra/integrator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Integrator w;
    w.show();

    return a.exec();
}
