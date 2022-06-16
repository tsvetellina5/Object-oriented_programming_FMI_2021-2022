#pragma once

#include "MyString.h"
#include <iostream>

class Vehicle
{
private:
	MyString brand;
	MyString licensePlate;
	MyString model;
	size_t yearOfProduction;
	size_t seatsCount;

protected:
	enum Category
	{
		Motorcycle,
		Automobile,
		Bus,
		UnknownCarType
	} category;

	enum Gearbox
	{
		Manual,
		Auto,
		UnknownGearbox
	} gearbox;

	enum EngineType
	{
		Diesel,
		Petrol,
		Electric,
		UnknownEngineType
	} engineType;

public:
	Vehicle();
	Vehicle(const MyString &, const MyString &, const size_t, const size_t);

	virtual ~Vehicle() = default;
	virtual Vehicle *clone() const = 0;

	void setBrand(const MyString &);
	void setLicensePlate(const MyString &);
	void setYearOfProduction(const size_t);
	void setSeatsCount(const size_t);
	void setModel(const MyString &);
	void setEngineType(const size_t);
	void setGearbox(const size_t);

	const MyString &getBrand() const;
	const MyString &getLicensePlate() const;
	size_t getYearOfProduction() const;
	size_t getSeatsCount() const;
	const MyString &getModel() const;

	const Category &getCategory() const;
	const Gearbox &getGearbox() const;
	const EngineType &getEngineType() const;

	bool isVehicleNew();
	bool isVehicleRented() const;

	void changeRentedStatus(bool);

	virtual void print() const;

private:
	void setDefaultValue();
};
