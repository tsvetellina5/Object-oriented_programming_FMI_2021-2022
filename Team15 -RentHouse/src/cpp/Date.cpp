#include "Date.h"
#include <ctime>

Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2000;
}

Date::Date(const size_t day, const size_t month, const size_t year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

size_t Date::daysToDate(const Date &other)
{
    const size_t daysInYear = 365;
    if (*this >= other)
    {
        return 0;
    }

    size_t count = 0;
    size_t year_copy = this->year;

    while (year_copy < other.year)
    {
        count += daysInYear;
        if (isLeapYear(year_copy))
        {
            count++;
        }
        year_copy++;
    }

    count += other.daysThisYear() - this->daysThisYear();

    return count;
}

size_t Date::daysThisYear() const
{
    size_t count = 0;
    size_t tempMonth = 1;

    while (tempMonth < this->month)
    {
        count += daysIn(tempMonth++, this->year);
    }
    count += this->day;

    return count;
}

bool Date::isBetweenDates(const Date &left, const Date &right)
{
    return left <= *this && *this <= right;
}

bool operator==(const Date &left, const Date &right)
{
    return left.day == right.day && left.month == right.month && left.year == right.year;
}

bool operator!=(const Date &left, const Date &right)
{
    return !(left == right);
}

bool operator<(const Date &left, const Date &right)
{
    if (left.year != right.year)
    {
        return left.year < right.year;
    }
    if (left.month != right.month)
    {
        return left.month < right.month;
    }
    return left.day < right.day;
}

bool operator>(const Date &left, const Date &right)
{
    return !(left <= right);
}

bool operator>=(const Date &left, const Date &right)
{
    return !(left < right);
}

bool operator<=(const Date &left, const Date &right)
{
    return left < right || left == right;
}

bool isValidDate(const size_t day, const size_t month, const size_t year)
{
    if (month > 12 || month < 1)
    {
        return false;
    }

    if (year > getCurrentYear() + 1)
    {
        return false;
    }

    if (daysIn(month, year) < day)
    {
        return false;
    }
    return true;
}

size_t getCurrentYear()
{
    time_t t = time(NULL);
    tm *now = localtime(&t);
    return now->tm_year + 1900;
}

bool isLeapYear(const size_t year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

size_t daysIn(size_t month, size_t year)
{
    size_t monthsArr[12] = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

    if (isLeapYear(year) && month == 2)
    {
        return 29;
    }
    return monthsArr[month - 1];
}

void Date::addDays(size_t days)
{
    days += day - 1;
    day = 1;
    while (days >= daysIn(month, year))
    {
        days -= daysIn(month, year);
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }

    day += days;
}

std::ostream &operator<<(std::ostream &ostr, const Date &date)
{
    ostr << date.day << " " << date.month << " " << date.year;
    return ostr;
}