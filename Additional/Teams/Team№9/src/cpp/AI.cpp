#include "AI.h"
#include <iostream>

AI::AI() :Reservation()
{
	paidBar = false;
}

AI::AI(const String& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id)
	: Reservation(type, days, roomNumber, bedNumber, id) {
	paidBar = false;
}

void AI::display() const
{
	std::cout << "All inclusive reservation for " << days << " days in room " << roomNumber << " with " << bedNumber << " beds for " << bedNumber*days*100 << "$." << std::endl;
}

bool AI::goToRestaurant() const
{
	return true;
}

bool AI::goToBar() const
{
	return paidBar;
}

void AI::payToBar()
{
	this->paidBar = true;
}

Reservation* AI::clone() const
{
	return new AI(*this);
}

void AI::payForRestaurant() 
{
	std::cout << "Restaurant is paid!" << std::endl;
}

void AI::payForBar()
{
	paidBar = true;
	std::cout << "You succesfully paid for bar!" << std::endl;
}