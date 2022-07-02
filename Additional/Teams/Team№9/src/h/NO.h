#pragma once
#include "Reservation.h"

class NO : public Reservation
{
private:
	bool paidBar;
	bool paidRestaurant;

public:
	NO();
	NO(const Type& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id);

	void display() const override;
	bool goToRestaurant() const override;
	bool goToBar() const override;

	Reservation* clone() const override;

	void payForBar() override;
	void payForRestaurant() override;
};