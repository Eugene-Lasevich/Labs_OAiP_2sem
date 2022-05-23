#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QDebug>
#include <QDate>

class Date
{
private:
    int year;
    int month;
    int day;
    int days;
    short m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:

    Date(int year, int month, int day);
    Date(const Date& date);

    Date NextDay();
    Date PreviousDay();

    bool IsLeap();
    short WeekNumber();

    int DaysTillYourBithday(Date bithdaydate);
    int Duration(Date date);

    QString ToString();
};

#endif // DATE_H
