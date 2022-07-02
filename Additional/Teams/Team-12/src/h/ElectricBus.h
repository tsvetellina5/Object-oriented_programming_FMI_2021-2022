#pragma once
#include "Vehicle.h"
#include "vector.h"
class ElectricBus : public Vehicle {
protected:
	Vector<MyString> listOfStops;
	struct Time
	{
		size_t hour, minutes;
	} startTime, finalTime, breakTime;
public:
	ElectricBus();
	ElectricBus(size_t, size_t, MyString, double, double, MyString, MyString, size_t, size_t, size_t, size_t);
	virtual bool isItWorkingAt(size_t, size_t) const = 0;

	void setTime(size_t, size_t, size_t, size_t);
    void addStop(const MyString &);
	bool rideFromTo(const MyString&, const MyString&);
    bool removeStop(const MyString &);
	bool driveVehicle(const double) override; 

	void display() const override;
};