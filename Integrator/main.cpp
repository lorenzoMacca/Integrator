#include "gra/integrator.h"
#include "src/core/data/data.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Data *data = new Data(&a);
    Integrator w(data);
    w.show();

    return a.exec();
}
