#include "phonebook.h"
#include <QFile>

phonebook::phonebook(QObject *parent) : QObject(parent)
{

}
//std::list<person> phonebook::QlistToStd (){
//    return this->*contacts->toStdList();
//}

void phonebook::addContact(QString &name, QList<QString> numbers){

    person *contact = new person;
    contact->addName(name);
    foreach (QString i, numbers) {
        contact->addNumber(i);
    }

    this->contacts.append(contact);
    qDebug() << "contact is added";

}

person* phonebook::searchContact(QString &name){
    foreach (person *i, this->contacts) {
        if(i->getName() == name){
            return i;
        }
    }
    //std::list<person> myList = QlistToStd();
    //std::list<person>::iterator findIter = std::find_if(myList.begin(), myList.end(), person::getName()==name);
    //return *findIter;

}
person* phonebook::searchNumber(QString &number){
    foreach (person *i, this->contacts) {
        foreach (QString j, i->getNumber()){
            if(j == number){
                return i;
            }
        }
    }
}

void phonebook::removeContact(QString &name){
    person *contact = this->searchContact(name);
    this->contacts.removeOne(contact);
    delete contact;

}
void phonebook::save(){
    QFile file;file.setFileName("/home/baharan/Desktop/test.txt");
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream stream(&file);
    foreach(person *i , this->contacts){
        stream << i->getName() << " Numbers:\n";
        foreach (QString z, i->getNumber()) {
            stream << z << " ";
        }
    }
    file.flush();
    file.close();
}
void phonebook::open(){
    QFile file;file.setFileName("/home/baharan/Desktop/test.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    qDebug()<<stream.readAll();

    file.close();
}
