#include "participant.h"

Participant::Participant()
{

}

const QString &Participant::getCountry() const
{
    return country;
}

void Participant::setCountry(const QString &newCountry)
{
    country = newCountry;
}

const QString &Participant::getTeam() const
{
    return team;
}

void Participant::setTeam(const QString &newTeam)
{
    team = newTeam;
}

const QString &Participant::getName() const
{
    return name;
}

void Participant::setName(const QString &newName)
{
    name = newName;
}

const QString &Participant::getSurname() const
{
    return surname;
}

void Participant::setSurname(const QString &newSurname)
{
    surname = newSurname;
}

const QString &Participant::getPatronymic() const
{
    return patronymic;
}

void Participant::setPatronymic(const QString &newPatronymic)
{
    patronymic = newPatronymic;
}

const QString &Participant::getGameNumber() const
{
    return gameNumber;
}

void Participant::setGameNumber(const QString &newGameNumber)
{
    gameNumber = newGameNumber;
}

const QString &Participant::getAge() const
{
    return age;
}

void Participant::setAge(const QString &newAge)
{
    age = newAge;
}

const QString &Participant::getGrowth() const
{
    return growth;
}

void Participant::setGrowth(const QString &newGrowth)
{
    growth = newGrowth;
}

const QString &Participant::getWeight() const
{
    return weight;
}

void Participant::setWeight(const QString &newWeight)
{
    weight = newWeight;
}

bool Participant::isEmpty()
{
    if(this->getName() == "" || this->getSurname() == ""  || this->getPatronymic() == "" ||\
       this->getCountry() == "" || this->getTeam() =="" || this->getAge() == "" || this->getGameNumber() == "" || this->getGrowth() == "" || this->getWeight() =="")
    {
    return true;
    }
    else return false;
}

QString Participant::empty_fields()
{
    QString str;
    QString name = "Name not entered ";
    QString surname = "Surname not entered ";
    QString patronymic = "Patronomic not enterd ";
    QString country = "Country not entered";
    QString team = "Team not entered";
    QString gameNumber = "Game number not enterd";
    QString age = "Age not entered";
    QString growth = "Growth not entered";
    QString weight = "Weight not entered";
    if(this->getName() == "") str += name +'\n';
    if(this->getSurname() == "") str += surname + '\n';
    if(this->getPatronymic() == "") str += patronymic + '\n';
    if(this->getCountry() == "") str += country +'\n';
    if(this->getTeam() == "") str += team + '\n';
    if(this->getGameNumber() == "") str += gameNumber + '\n';
    if(this->getAge() == "") str += age +'\n';
    if(this->getGrowth() == "") str += growth + '\n';
    if(this->getWeight() == "") str += weight + '\n';

    return str;
}


