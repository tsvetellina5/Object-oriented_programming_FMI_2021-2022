#pragma once
#include "MyString.h"

class Person
{

protected:
	MyString name;
	MyString email;
	MyString EGN;
	MyString city;
	MyString phone;

public:
	Person();
	Person(const MyString &, const MyString &, const MyString &, const MyString &, const MyString &);
	virtual ~Person() = default;

	void setName(const MyString &);
	void setEmail(const MyString &);
	void setEGN(const MyString &);
	void setCity(const MyString &);
	void setPhone(const MyString &);

	const MyString &getName() const;
	const MyString &getEmail() const;
	const MyString &getEGN() const;
	const MyString &getCity() const;
	const MyString &getPhone() const;
};
