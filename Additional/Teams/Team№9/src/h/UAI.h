#pragma once
#include "Reservation.h"

class UAI :public Reservation
{
public:
	UAI();
	UAI(const String& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id);

	void display() const override;
	bool goToRestaurant() const override;
	bool goToBar() const override;

	Reservation* clone() const override;

	void payForBar() override;
	void payForRestaurant() override;
};