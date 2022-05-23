#ifndef ENROLLEE_H
#define ENROLLEE_H

#include<QString>
#include<QMessageBox>
#include<QDebug>
class Enrollee
{
public:
    Enrollee();
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);


    const QString &getPhysics() const;
    void setPhysics(const QString &newPhysics);
    const QString &getMath() const;
    void setMath(const QString &newMath);
    const QString &getRussian() const;
    void setRussian(const QString &newRussian);
    bool isEmpty();
    QString empty_fields();




private:
    QString name;
    QString surname;
    QString patronymic;
    QString physics;
    QString math;
    QString russian;

};

#endif // ENROLLEE_H
