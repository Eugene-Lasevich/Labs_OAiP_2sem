#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include<QString>
class Participant
{
public:
    Participant();
    const QString &getCountry() const;
    void setCountry(const QString &newCountry);
    const QString &getTeam() const;
    void setTeam(const QString &newTeam);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);
    const QString &getGameNumber() const;
    void setGameNumber(const QString &newGameNumber);
    const QString &getAge() const;
    void setAge(const QString &newAge);
    const QString &getGrowth() const;
    void setGrowth(const QString &newGrowth);
    const QString &getWeight() const;
    void setWeight(const QString &newWeight);
    bool isEmpty();
    QString empty_fields();

private:
    QString country;
    QString team;
    QString name;
    QString surname;
    QString patronymic;
    QString gameNumber;
    QString age;
    QString growth;
    QString weight;
};

#endif // PARTICIPANT_H
