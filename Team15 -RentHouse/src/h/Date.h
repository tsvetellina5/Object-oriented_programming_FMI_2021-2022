#pragma once

#include <fstream>
#include <iostream>

class Date
{

private:
    size_t day, month, year;

public:
    Date();
    Date(const size_t day, const size_t month, const size_t year);

    size_t daysToDate(const Date &);
    size_t daysThisYear() const;
    bool isBetweenDates(const Date &, const Date &);
    bool isValidDate();

    void print() const;

    friend bool operator==(const Date &, const Date &);
    friend bool operator!=(const Date &, const Date &);

    friend bool operator<(const Date &, const Date &);
    friend bool operator>(const Date &, const Date &);
    friend bool operator>=(const Date &, const Date &);
    friend bool operator<=(const Date &, const Date &);

    void addDays(size_t);
    friend std::ostream &operator<<(std::ostream &, const Date &);
    friend std::istream &operator>>(std::istream &, Date &);
};

size_t daysIn(size_t, size_t);
bool isLeapYear(const size_t year);
size_t getCurrentYear();

