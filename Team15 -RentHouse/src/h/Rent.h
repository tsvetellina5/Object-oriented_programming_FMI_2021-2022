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
    void setEGN(const MyString&);
    const MyString& getLicensePlate() const;
    void setLicensePlate(const MyString&);

    Rent* clone() const;
    void print() const;
};
