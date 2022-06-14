#pragma once
#include "Reservation.h"

class AI :public Reservation
{
private:
	bool paidBar;

public:
	AI();
	AI(const String& type, size_t days, size_t roomNumber, size_t bedNumber, const String& id);

	void display() const override;
	bool goToRestaurant() const override;
	bool goToBar() const override;
	void payToBar();

	Reservation* clone() const override;

	void payForBar() override;
	void payForRestaurant() override;
};
