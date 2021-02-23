#ifndef CLASSES_H
#define CLASSES_H

#include <QDebug>

//before applying pattern
class BirdBad
{
public:
    virtual ~BirdBad() {}
    virtual void eat()
    {
        qDebug() << "BirdBad: Worm Eating";
    }
    virtual void fly()
    {
        qDebug() << "BirdBad: Normal Flying";
    }
    virtual void sing()
    {
        qDebug() << "BirdBad: Normal Singing";
    }
};

class PigeonBad : public BirdBad
{
public:
    void eat() override
    {
        qDebug() << "PigeonBad: Seeds Eating";
    }
    void sing() override
    {
        qDebug() << "PigeonBad: Urban Singing";
    }
};

class OwlBad : public BirdBad
{
public:
    void fly() override
    {
        qDebug() << "OwlBad: Swoop Flying";
    }
    void sing() override
    {
        qDebug() << "OwlBad: Rural Singing";
    }
};

class ChickenBad : public BirdBad
{
public:
    void eat() override
    {
        qDebug() << "ChickenBad: Seeds Eating";
    }
    void fly() override
    {
        qDebug() << "ChickenBad: No Flying";
    }
    void sing() override
    {
        qDebug() << "ChickenBad: Rural Singing";
    }
};

class EagleBad : public BirdBad
{
public:
    void eat() override
    {
        qDebug() << "EagleBad: SmallAnimal Eating";
    }
    void fly() override
    {
        qDebug() << "EagleBad: Swoop Flying";
    }
    void sing() override
    {
        qDebug() << "EagleBad: No Singing";
    }
};

//after applying pattern
class IEatStrategy
{
public:
    virtual ~IEatStrategy() {}
    virtual void eat() = 0;
};

class IFlyStrategy
{
public:
    virtual ~IFlyStrategy() {}
    virtual void fly() = 0;
};

class ISingStrategy
{
public:
    virtual ~ISingStrategy() {}
    virtual void sing() = 0;
};

class WormEatStrategy : public IEatStrategy
{
public:
    void eat() override
    {
        qDebug() << "Worm Eating Strategy";
    }
};

class SeedsEatStrategy : public IEatStrategy
{
public:
    void eat() override
    {
        qDebug() << "Seeds Eating Strategy";
    }
};

class SmallAnimalEatStrategy : public IEatStrategy
{
public:
    void eat() override
    {
        qDebug() << "SmallAnimal Eating Strategy";
    }
};

class NormalFlyStrategy : public IFlyStrategy
{
public:
    void fly() override
    {
        qDebug() << "Normal Flying Strategy";
    }
};

class SwoopFlyStrategy : public IFlyStrategy
{
public:
    void fly() override
    {
        qDebug() << "Swoop Flying Strategy";
    }
};

class NoFlyStrategy : public IFlyStrategy
{
public:
    void fly() override
    {
        qDebug() << "No Flying Strategy";
    }
};

class NormalSingStrategy : public ISingStrategy
{
public:
    void sing() override
    {
        qDebug() << "Normal Singing Strategy";
    }
};

class UrbanSingStrategy : public ISingStrategy
{
public:
    void sing() override
    {
        qDebug() << "Urban Singing Strategy";
    }
};

class RuralSingStrategy : public ISingStrategy
{
public:
    void sing() override
    {
        qDebug() << "Rural Singing Strategy";
    }
};

class NoSingStrategy : public ISingStrategy
{
public:
    void sing() override
    {
        qDebug() << "No Singing Strategy";
    }
};

class BirdGood
{
public:
    BirdGood(IEatStrategy *es, IFlyStrategy *fs, ISingStrategy *ss) : m_es{es}, m_fs{fs}, m_ss{ss} {}
    ~BirdGood()
    {
        if(nullptr == m_es)
            delete m_es;
        if(nullptr == m_fs)
            delete m_fs;
        if(nullptr == m_ss)
            delete m_ss;
    }

    void eat()
    {
        m_es->eat();
    }

    void fly()
    {
        m_fs->fly();
    }

    void sing()
    {
        m_ss->sing();
    }
private:
    IEatStrategy *m_es = nullptr;
    IFlyStrategy *m_fs = nullptr;
    ISingStrategy *m_ss = nullptr;
};

#endif // CLASSES_H
