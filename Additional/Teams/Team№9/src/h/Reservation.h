#pragma once
#include "String.h"
#include "Visitor.h"

class Reservation
{
protected:
	String type;
	String id;
	size_t days;
	size_t roomNumber;
	size_t bedNumber;
	double price;

public:
	Reservation();
	Reservation(const String& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id);

	void setType(const String& type);
	void setDays(size_t days);
	void setRoomNumber(size_t roomNumber);
	void setBedNumber(size_t bedNumber);
	void setPrice(double price);

	const String& getType() const;
	const String& getID() const;
	size_t getDays() const;
	size_t getRoomNumber() const;
	size_t getBedNumber() const;
	double getPrice() const;

	virtual void display() const = 0;
	virtual bool goToRestaurant() const = 0;
	virtual bool goToBar() const = 0;

	virtual Reservation* clone() const = 0;

	virtual void payForBar() = 0;
	virtual void payForRestaurant() = 0;

};