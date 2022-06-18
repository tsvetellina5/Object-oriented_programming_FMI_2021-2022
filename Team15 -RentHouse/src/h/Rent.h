#pragma once

#include "MyString.h"
#include "Date.h"

class Rent
{
private:
    MyString EGN;
    MyString licensePlate;
    Date dateRented;
    Date dateToReturn;

public:
    Rent() = default;
    Rent(const MyString, const MyString, const Date &, const Date &);

    void increaseRentalTime(size_t);

    friend std::ostream &operator<<(std::ostream &, const Rent &);

    const MyString &getEGN() const;
    const MyString &getLicensePlate() const;
    const Date &getDateRented() const;
    const Date &getDateToReturn() const;

    void setEGN(const MyString &);
    void setLicensePlate(const MyString &);
    void setDateRented(const Date &);
    void setDateToReturn(const Date &);

    Rent *clone() const;
    void print() const;
};
