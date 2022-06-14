#include "NO.h"
#include <iostream>

NO::NO() :Reservation()
{
	paidBar = false;
	paidRestaurant = false;
}

NO::NO(const Type& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id)
	:Reservation(type, days, roomNumber, bedNumber, id), paidBar(false),
	paidRestaurant(false) {}

void NO::display() const
{
	std::cout << "Nights only reservation for " << days << " days in room " << roomNumber << " with " << bedNumber << " beds for " << bedNumber * days * 50 << "$." << std::endl;
}

bool NO::goToRestaurant() const
{
	return paidRestaurant;
}

bool NO::goToBar() const
{
	return paidBar;
}

Reservation* NO::clone() const
{
	return new NO(*this);
}

void NO::payForBar()
{
	paidBar = true;
	std::cout << "You succesfully paid for bar!" << std::endl;
}
void NO::payForRestaurant()
{
	paidRestaurant = true;
	std::cout << "You succesfully paid for restaurant!" << std::endl;
}