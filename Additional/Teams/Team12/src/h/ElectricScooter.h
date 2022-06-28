#pragma once
#include "Vehicle.h"

class ElectricScooter : public Vehicle {

	bool isFree;
public:
	ElectricScooter();
	ElectricScooter(size_t, MyString, double, double);

	void occupy();
	void free();
	bool isOccupied() const;

	void display() const override;

	bool driveVehicle(const double) override; // km = how many km have you driven
	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

};