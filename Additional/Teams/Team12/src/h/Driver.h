#pragma once
#include "MyString.h"
#include <iostream>

class Driver {
	MyString name;
	size_t identityNumber;
	size_t age;
public:
	enum driverLicense {
		B,
		D,
		Unknown
	}license;
	Driver();
	Driver(MyString, size_t, size_t , driverLicense);
	void display() const;

	MyString getLicenseString() const;
	void setLicense(driverLicense);
};