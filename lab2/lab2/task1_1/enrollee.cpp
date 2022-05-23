#include "enrollee.h"

Enrollee::Enrollee()
{

}

const QString &Enrollee::getName() const
{
    return name;
}

void Enrollee::setName(const QString &newName)
{

    name = newName;

}

const QString &Enrollee::getSurname() const
{
    return surname;
}

void Enrollee::setSurname(const QString &newSurname)
{
    surname = newSurname;
}

const QString &Enrollee::getPatronymic() const
{
    return patronymic;
}

void Enrollee::setPatronymic(const QString &newPatronymic)
{
    patronymic = newPatronymic;
}

const QString &Enrollee::getPhysics() const
{
    return physics;
}

void Enrollee::setPhysics(const QString &newPhysics)
{
    physics = newPhysics;
}

const QString &Enrollee::getMath() const
{
    return math;
}

void Enrollee::setMath(const QString &newMath)
{
    math = newMath;
}

const QString &Enrollee::getRussian() const
{
    return russian;
}

void Enrollee::setRussian(const QString &newRussian)
{
    russian = newRussian;
}

bool Enrollee::isEmpty()
{
    if(this->getName() == "" || this->getSurname() == ""  || this->getPatronymic() == "" || this->getPhysics() == "" || this->getMath() =="" || this->getRussian() == "")
    {
    return true;
    }
    else return false;
}

QString Enrollee::empty_fields()
{
    QString str;
    QString name = "Name not entered ";
    QString surname = "Surname not entered ";
    QString patronymic = "Patronomic not enterd ";
    QString physics = "Physics score not entered ";
    QString math = "Math score not entered ";
    QString russian = "Russian language score not entered ";
    if(this->getName() == "") str += name +'\n';
    if(this->getSurname() == "") str += surname + '\n';
    if(this->getPatronymic() == "") str += patronymic + '\n';
    if(this->getPhysics() == "") str += physics + '\n';
    if(this->getMath() == "") str += math + '\n';
    if(this->getRussian() == "") str += russian + '\n';
    return str;
}




