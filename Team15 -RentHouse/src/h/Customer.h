#pragma once
#include "Person.h"
#include "MyString.h"

class Customer : public Person
{
private:
    MyString username;
    MyString password;

public:
    Customer();
    Customer(const MyString &, const MyString &, const MyString &, const MyString &, const MyString &, const MyString &, const MyString &);

    const MyString &getUsername() const;
    void setUsername(const MyString &);
    const MyString &getPassword() const;
    void setPassword(const MyString &);

    Customer *clone() const;
    void print() const;

    friend std::ofstream &operator<<(std::ofstream &, const Customer &);
    friend std::ifstream &operator>>(std::ifstream &, Customer &);
};
