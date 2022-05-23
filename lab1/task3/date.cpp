#include "date.h"


Date::Date(int year, int month, int day)
{
    Date::year = year;
    Date::month = month;
    Date::day = day;
    days = 0;

    for (int i = 0; i < month - 1; ++i)
    {
        days+= m[i];
    }
    days += day;

    if (IsLeap() && month > 2)
    {
        ++days;
    }
}




Date Date::NextDay()
{
    if (month == 12 && day == 31) return Date(year + 1, 1, 1);
    if (day == m[month - 1] && !IsLeap())  return Date(year, month + 1, 1);
    if (day == 29 && month == 2)  return Date(year, month + 1, 1);

    return Date(year, month, day + 1);
}




Date Date::PreviousDay()
{
    if(month == 1 && day == 1 && year == 1) return Date(-1,12,31);

    if (month == 1 && day == 1)
    {
        return Date(year - 1, 12, 31);
    }

    if (day == 1)
    {
        if (month == 3 && IsLeap())
        {
            return Date(year, 2, 29);
        }
        return Date(year, month - 1, m[month - 2]);
    }

    return Date(year, month, day - 1);
}



bool Date::IsLeap()
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}



short Date::WeekNumber()
{
    return days / 7 + 1;
}



int Date::DaysTillYourBithday(Date birthday_date)
{


    if(birthday_date.year<2022)
    {
    qDebug()<<"year < 2020 = "<<birthday_date.year;
    return (Duration(Date(this->year, birthday_date.month, birthday_date.day))+ (IsLeap() ? 366 : 365)) % (IsLeap() ? 366 : 365);
    }

    else
    {
        qDebug()<<"year >2022"<<birthday_date.year;
        if(Duration(Date(birthday_date.year, birthday_date.month, birthday_date.day))+ (IsLeap() ? 366 : 365)<50000)
        return (Duration(Date(birthday_date.year, birthday_date.month, birthday_date.day))+ (IsLeap() ? 366 : 365));

        else return Duration(Date(2550, 12, 1))+ (IsLeap() ? 366 : 365);
    }


}



int Date::Duration(Date date)
{
    return (date.year - this->year) * 365+ (date.year - this->year) / 4 - (date.year - this->year) / 100 + (date.year - this->year) / 400 + date.days - this->days;
    //return 1;
}



QString Date::ToString()
{
    return  QDate(year, month, day).toString("dd.MM.yyyy");
}



Date::Date(const Date &date)
{
    Date::year = date.year;
    Date::month = date.month;
    Date::day = date.day;
    Date::days = date.days;
}
