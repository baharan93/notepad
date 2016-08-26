#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDebug>

class person : public QObject
{
    Q_OBJECT
public:
    explicit person(QObject *parent = 0);

    void addName(QString &name);
    void addNumber(QString &number);
    void removeNumber(QString &number);
    QString getName();
    QList<QString> getNumber();

signals:

public slots:

private:
    QString contactName;
    QList<QString> numbers;
};

#endif // PERSON_H
