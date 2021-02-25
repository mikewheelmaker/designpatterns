#ifndef CLASSES_H
#define CLASSES_H

#include <QDebug>
#include <QList>

class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void update() = 0;
};

class IObservable
{
public:
    virtual ~IObservable() {}
    virtual void add(IObserver *observer) = 0;
    virtual void remove(IObserver *observer) = 0;
    virtual void notify() = 0;
};

class TemperatureStation : public IObservable
{
public:
    void add(IObserver *observer) override
    {
        m_observerList.append(observer);
    }

    void remove(IObserver *observer) override
    {
        if(!m_observerList.empty())
            m_observerList.removeOne(observer);
    }

    void notify() override
    {
        for(auto currentObserver : m_observerList)
            currentObserver->update();
    }

    double getTemperature() const
    {
        return m_temperature;
    }

    void setTemperature(double temperature)
    {
        m_temperature = temperature;
        notify();
    }

private:
    double m_temperature = 0.0;
    QList<IObserver *> m_observerList;
};

class TemperatureDisplayScreen : public IObserver
{
public:
    TemperatureDisplayScreen(TemperatureStation *station) : m_station {station} {}
    void update() override
    {
        qDebug() << "Temperature has been updated to: " << m_station->getTemperature();
    }

private:
    TemperatureStation *m_station = nullptr;
};

#endif // CLASSES_H
