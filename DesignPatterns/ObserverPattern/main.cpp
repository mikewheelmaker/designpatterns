#include <QCoreApplication>
#include <Windows.h>

#include "classes.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TemperatureStation *ts = new TemperatureStation();
    TemperatureDisplayScreen *screen1 = new TemperatureDisplayScreen(ts);
    TemperatureDisplayScreen *screen2 = new TemperatureDisplayScreen(ts);
    TemperatureDisplayScreen *screen3 = new TemperatureDisplayScreen(ts);
    ts->add(screen1);       ts->add(screen2);       ts->add(screen3);

    ts->setTemperature(15);
    ts->setTemperature(10);
    ts->setTemperature(25);

    ts->remove(screen1);    ts->remove(screen2);    ts->remove(screen3);
    delete screen3;
    delete screen2;
    delete screen1;
    delete ts;

    return 0;

    //return a.exec();
}
