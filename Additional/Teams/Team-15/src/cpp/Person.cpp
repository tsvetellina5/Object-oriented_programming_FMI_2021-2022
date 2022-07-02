#include "Person.h"

Person::Person() {}

Person::Person(const MyString &name, const MyString &email, const MyString &EGN, const MyString &city, const MyString &phone)
    : name(name), email(email), EGN(EGN), city(city), phone(phone)
{
}

void Person::setName(const MyString &name)
{
    this->name = name;
}

void Person::setEmail(const MyString &email)
{
    this->email = email;
}

void Person::setEGN(const MyString &EGN)
{
    this->EGN = EGN;
}

void Person::setCity(const MyString &city)
{
    this->city = city;
}

void Person::setPhone(const MyString &phone)
{
    this->phone = phone;
}

const MyString &Person::getName() const
{
    return name;
}

const MyString &Person::getEmail() const
{
    return email;
}

const MyString &Person::getEGN() const
{
    return EGN;
}

const MyString &Person::getCity() const
{
    return city;
}

const MyString &Person::getPhone() const
{
    return phone;
}
