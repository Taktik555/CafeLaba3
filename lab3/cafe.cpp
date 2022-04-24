#include "cafe.h"

Cafe::Cafe(/*QString ID, QString Name, QString Flow, QString Lenght, QString Runoff, QObject *parent): QObject(parent*/)
{
    /*id = ID;
    name = Name;
    type = Flow;
    address = Lenght;
    worktime = Runoff;*/
}

void Cafe::setID(const QString ID)
{
    id = ID;
}
void Cafe::setName(const QString Name)
{
    name = Name;
}
void Cafe::setType(const QString Flow)
{
    type = Flow;
}
void Cafe::setAddress(const QString Lenght)
{
    address = Lenght;
}
void Cafe::setWorktime(const QString Runoff)
{
    worktime = Runoff;
}

QString Cafe::getID() const
{
    return id;
}
QString Cafe::getName() const
{
    return name;
}
QString Cafe::getType() const
{
    return type;
}
QString Cafe::getAddress() const
{
    return address;
}
QString Cafe::getWorktime() const
{
    return worktime;
}

 Cafe::~Cafe()
{
}
