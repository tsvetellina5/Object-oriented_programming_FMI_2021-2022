#include "Reservation.h"
#pragma warning(disable:4996)

Reservation::Reservation()
{
	days = 0;
	roomNumber = 0;
	bedNumber = 0;
	price = 0;
}

Reservation::Reservation(const String& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id)
{
	this->type = type;
	this->days = days;
	this->roomNumber = roomNumber;
	this->bedNumber = bedNumber;
}

void Reservation::setType(const String& type)
{
	this->type = type;
}

void Reservation::setDays(size_t days)
{
	this->days = days;
}

void Reservation::setRoomNumber(size_t roomNumber)
{
	this->roomNumber = roomNumber;
}

void Reservation::setBedNumber(size_t bedNumber)
{
	this->bedNumber = bedNumber;
}

void Reservation::setPrice(double price)
{
	this->price = price;
}

const String& Reservation::getType() const
{
	return type;
}

const String& Reservation::getID() const
{
	return id;
}

size_t Reservation::getDays() const
{
	return days;
}

size_t Reservation::getRoomNumber() const
{
	return roomNumber;
}

size_t Reservation::getBedNumber() const
{
	return bedNumber;
}

double Reservation::getPrice() const
{
	return price;
}