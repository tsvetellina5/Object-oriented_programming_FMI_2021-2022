#include "UAI.h"
#include <iostream>

UAI::UAI() :Reservation() {}

UAI::UAI(const String& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id)
	: Reservation(type, days, roomNumber, bedNumber, id) {}

void UAI::display() const
{
	std::cout << "Ultra all inclusive reservation for " << days << " days in room " << roomNumber << " with " << bedNumber << " beds for " << bedNumber * days * 150 << "$." << std::endl;
}

bool UAI::goToRestaurant() const
{
	return true;
}

bool UAI::goToBar() const
{
	return true;
}

Reservation* UAI::clone() const
{
	return new UAI(*this);
}

void UAI::payForBar()
{
	std::cout << "Bar is paid!" << std::endl;
}
void UAI::payForRestaurant()
{
	std::cout << "Restaurant is paid!" << std::endl;
}