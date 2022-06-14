#pragma once
#include "MyString.h"
#include <iostream>

using std::cout;

class Vehicle {
	size_t DriverIdentityNumber;
	size_t vehicleID;
	MyString model;
	double battery;
	double batteryRange;
	double chargingRate;
public:
	enum ElectricType{
		E_SCOOTER,
		E_CAR,
		E_CITY_BUS,
		E_INTERCITY_BUS,
		UNKNOWN
	}type;

	Vehicle();
	Vehicle(size_t, size_t, MyString, double, double);
	virtual ~Vehicle() {};

	bool needCharging(const double) const;
	void exhaustBattery(const double);
	double getMinutesToCharge() const;
	void chargeBattery();

	void setBattery(const double);
	size_t getVehicleId() const;
	double getBattery() const;
	double getBatteryRange() const;

	virtual void display() const;

	virtual bool driveVehicle(const double) = 0;
	virtual MyString getTypeString() const = 0;
	virtual ElectricType getType() const = 0;
	virtual Vehicle* clone() const = 0;

};