#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QObject>
#include "person.h"


class phonebook : public QObject
{
    Q_OBJECT
public:
    explicit phonebook(QObject *parent = 0);

    void addContact(QString &name, QList<QString> numbers);
    void removeContact(QString &name);
    person* searchContact(QString &name);
    person* searchNumber(QString &number);
    //std::list<person> QlistToStd ();
    void save();
    void open();

signals:

public slots:

private:

    QList<person*> contacts;
};

#endif // PHONEBOOK_H
