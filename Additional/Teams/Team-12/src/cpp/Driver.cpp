#include "../h/Driver.h"

Driver::Driver() : name(""), identityNumber(0), age(0){
	license = driverLicense::Unknown;
}

Driver::Driver(const MyString &name, size_t identityNumber, size_t age, driverLicense type) : name(name), identityNumber(identityNumber), age(age), license(type) {}

void Driver::display() const {
	std::cout << "\tName : " << name << "\n" <<
		"\tIdentity Number: " << identityNumber << "\n" <<
		"\tAge : " << age << "\n" <<
		"\tDriver License: " << getLicenseString() << "\n";
}

MyString Driver::getLicenseString() const {
	if (license == driverLicense::B)
		return "B - Car";
	if (license == driverLicense::D)
		return "D - Bus";
	return  "Error";
}

void Driver::setLicense(driverLicense type){
	license = type;
}