#include <QCoreApplication>
#include <QFile>
#include <iostream>
#include "person.h"
#include "phonebook.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    bool flag = true;
    phonebook *mycontacts = new phonebook;
    while (flag) {


    qDebug() << "CHOOSE:\n"
             << "0. Add Contact\n"
             << "1. Add Number\n"
             << "2. Delete Contact\n"
             << "3. Delete Number\n"
             << "4. Search Contact\n"
             << "5. Search Number\n"
             << "6. Save As A File\n"
             << "7. Open File\n"
             << "8. Quit\n";

    std::string str;
    std::getline(std::cin, str);
    QString qString(str.c_str());


    
    QStringList myOptions;
    myOptions << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8";

    std::string name1;
    std::string no1;
 
    switch (myOptions.indexOf(qString)) {
    case 0: {
        qDebug() << "enter name:  ";
        std::getline(std::cin, name1);
        QString contactName0(name1.c_str());
        qDebug() << "enter number:  ";
        QTextStream in(stdin);
        QString number;
        in >> number;
        mycontacts->addContact(contactName0, number.split(","));
        break;
    }
    case 1: {
        qDebug() << "enter name:  ";
        std::getline(std::cin, name1);
        QString contactName1(name1.c_str());
        qDebug() << "enter number:  ";
        std::getline(std::cin, no1);
        QString contactNo1(no1.c_str());
        mycontacts->searchContact(contactName1)->addNumber(contactNo1);
        break;
    }
    case 2: {
        qDebug() << "enter name:  ";
        std::getline(std::cin, name1);
        QString contactName1(name1.c_str());
        mycontacts->removeContact(contactName1);
        break;
    }
    case 3: {
        qDebug() << "enter name:  ";
        std::getline(std::cin, name1);
        QString contactName1(name1.c_str());
        qDebug() << "enter number:  ";
        std::getline(std::cin, no1);
        QString contactNo1(no1.c_str());
        mycontacts->searchContact(contactName1)->removeNumber(contactNo1);

        break;
    }
    case 4: {
        qDebug() << "enter name:  ";
        std::getline(std::cin, name1);
        QString contactName1(name1.c_str());

        person *found = mycontacts->searchContact(contactName1);
        qDebug() << found->getName();
        qDebug() << found->getNumber();
        break;
    }
    case 5:{
        qDebug() << "enter number:  ";
        std::getline(std::cin, no1);
        QString contactNo1(no1.c_str());
        person *found = mycontacts->searchNumber(contactNo1);
        qDebug() << found->getName();
        qDebug() << found->getNumber();
        break;
    }
    case 6: {

        mycontacts->save();

        break;
    }
    case 7: {
        mycontacts->open();
        break;
    }
    case 8:{
        flag = false;
        break;
    }
    default:
        break;
    }
    }


    return a.exec();
}
