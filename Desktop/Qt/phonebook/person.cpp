#include "person.h"


person::person(QObject *parent) : QObject(parent)
{


}
QString person::getName(){
   return this->contactName;
}
QList<QString> person::getNumber(){
    return this->numbers;
}

void person::addName(QString &name){
    this->contactName = name;
}

void person::addNumber(QString &number){

    this->numbers.append(number);
    qDebug () <<"number is added";

}

void person::removeNumber(QString &number){
    this->numbers.removeOne(number);
    qDebug() << "number is removed";

}



