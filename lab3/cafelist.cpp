#include "cafelist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

CafeList::CafeList(QObject* parent):QAbstractListModel(parent)
{
    add("Макдоналдс", "Лежневская 55", "Американская", "8:00-23:00");
    add("ТО-ТО Пицца", "улица 8 марта 32", "Итальянская", "10:00-22:00");
    add("Пельменная", "Лежневская 33", "Русская", "10:00-18:00");
}

CafeList::~CafeList()
{

}

int CafeList::rowCount(const QModelIndex&) const //число элементов в data
{
    return listOfCafes.size();
}


QVariant CafeList::data(const QModelIndex &index, int role) const //возвращает данные элемента
{
    if (index.row() < 0 || index.row() >= listOfCafes.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfCafes.at(index.row()).getName());
                case address:
                    return QVariant(listOfCafes.at(index.row()).getAddress());
                case type:
                    return QVariant(listOfCafes.at(index.row()).getType());
                case worktime:
                    return QVariant(listOfCafes.at(index.row()).getWorktime());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> CafeList::roleNames() const //возвращает список ролей, доступных в делегате
{
    QHash<int, QByteArray> roles; //элементы произвольно упорядочиваются + происходит оч быстрый поиск значения, связанного с ключом
    roles[name] = "nameOfCafe";
    roles[address] = "lenghtOfCafe";
    roles[type] = "flowOfCafe";
    roles[worktime] = "runoffOfCafe";
       return roles;
}

void CafeList::add(const QString& nameRiv, const QString& lenghtRiv, const QString& flowRiv, const QString& runoffRiv){
     Cafe cafe;
     cafe.setName(nameRiv);
     cafe.setAddress(lenghtRiv);
     cafe.setType(flowRiv);
     cafe.setWorktime(runoffRiv);

    beginInsertRows(QModelIndex(),listOfCafes.size(),listOfCafes.size()); //издаст нужные сигналы о том что готовится добавление элементов
    listOfCafes.append(cafe);  //добавление в конец списка
    endInsertRows(); //издаёт сигнал о том что в модель добавились элементы
}

QAbstractListModel* CafeList::getModel()
{
    return this;
}

void CafeList::del(const int index)
{

     if (index >= 0 && index < listOfCafes.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfCafes.removeAt(index);
              endRemoveRows();
     }
     //else qDebug() << "Error index";

}

QString CafeList::count(const QString& textSelArea){ //считаем речки, полощадь бассейна которых больше указанного числа
    int count = 0;
    for(int i = 0; i < listOfCafes.size(); i++)
    {
        QString temp = listOfCafes[i].getType();
        if (textSelArea == temp)
            count++;
    }
    QString c = QString::number(count);
    return c;
}

void CafeList::edit(const QString& nameRiv, const QString& lenghtRiv, const QString& flowRiv, const QString& runoffRiv, const int index) {
     if(index >= 0 && index < listOfCafes.size() )
     {
        auto& currentCafe = listOfCafes[index];
        if (currentCafe.getName().compare(nameRiv)!=0 || currentCafe.getAddress() != lenghtRiv || currentCafe.getType() != flowRiv
                || currentCafe.getWorktime() != runoffRiv)
        {
            currentCafe.setName(nameRiv);
            currentCafe.setAddress(lenghtRiv);
            currentCafe.setType(flowRiv);
            currentCafe.setWorktime(runoffRiv);

            auto modelIndex = createIndex(index, 0); //создавать индексы моделей для использования другими компонентами
            emit dataChanged(modelIndex, modelIndex); //выдается всякий раз, когда изменяются элементы данных, предоставляемые моделью
            //qDebug() << listOfCafes[index].getArea();
        }

     }
      //else qDebug() << "Error index";
}
