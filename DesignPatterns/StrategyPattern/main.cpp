#include <QCoreApplication>

#include "classes.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //before applying pattern
    PigeonBad *pb = new PigeonBad();
    OwlBad *ob = new OwlBad();
    ChickenBad *cb = new ChickenBad();
    EagleBad *eb = new EagleBad();

    pb->eat();      pb->fly();      pb->sing();
    ob->eat();      ob->fly();      ob->sing();
    cb->eat();      cb->fly();      cb->sing();
    eb->eat();      eb->fly();      eb->sing();

    delete eb;
    delete cb;
    delete ob;
    delete pb;

    //after applying pattern
    BirdGood *pigeon = new BirdGood {new SeedsEatStrategy, new NormalFlyStrategy, new UrbanSingStrategy};
    BirdGood *owl = new BirdGood {new WormEatStrategy, new SwoopFlyStrategy, new RuralSingStrategy};
    BirdGood *chicken = new BirdGood {new SeedsEatStrategy, new NoFlyStrategy, new RuralSingStrategy};
    BirdGood *eagle = new BirdGood {new SmallAnimalEatStrategy, new SwoopFlyStrategy, new NoSingStrategy};

    pigeon->eat();      pigeon->fly();      pigeon->sing();
    owl->eat();         owl->fly();         owl->sing();
    chicken->eat();     chicken->fly();     chicken->sing();
    eagle->eat();       eagle->fly();       eagle->sing();

    delete eagle;
    delete chicken;
    delete owl;
    delete pigeon;

    return 0;
    //return a.exec();
}
