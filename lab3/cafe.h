#ifndef CAFE_H
#define CAFE_H
#include "QString"
//#include <QObject>

class Cafe /*public QObject*/
{
    //Q_OBJECT

public:
    Cafe(/*QString ID, QString Name, QString Flow, QString Lenght, QString Runoff, QString Area QObject *parent = nullptr */);
    virtual ~Cafe();
    void setID(const QString ID);
    void setName(const QString Name);
    void setType(const QString Flow);
    void setAddress(const QString Lenght);
    void setWorktime(const QString Runoff);

    QString getID() const;
    QString getName() const;
    QString getType() const;
    QString getAddress() const;
    QString getWorktime() const;

private:
    QString id;
    QString name; //название
    QString address; //адрес
    QString type; //тип кухни
    QString worktime; //время работы
};

#endif // CAFE_H
