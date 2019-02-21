#include "weather.h"
#include "weatherdata.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Weatherdata wd;
    Weather w;
    w.show();

    return a.exec();
}
