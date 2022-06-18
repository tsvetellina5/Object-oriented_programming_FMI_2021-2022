#pragma once

#include "MyString.h"
#include <iostream>

class Vehicle
{
private:
	MyString brand;
	MyString model;
	MyString licensePlate;
	size_t yearOfProduction;
	size_t seatsCount;

protected:
	enum Category
	{
		Motorcycle,
		Automobile,
		Bus,
		UnknownVehicleType
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
	Vehicle(const MyString&, const MyString&, const MyString&, const size_t, const size_t, const size_t, const size_t);

	virtual ~Vehicle() = default;
	virtual Vehicle *clone() const = 0;

	//setters
	void setBrand(const MyString &);
	void setLicensePlate(const MyString &);
	void setModel(const MyString &);

	void setYearOfProduction(const size_t);
	void setSeatsCount(const size_t);

	void setEngineType(const size_t);
	void setGearbox(const size_t);

	//getters
	const MyString &getBrand() const;
	const MyString &getLicensePlate() const;
	const MyString &getModel() const;
	size_t getYearOfProduction() const;
	size_t getSeatsCount() const;

	const Category &getCategory() const;
	const Gearbox &getGearbox() const;
	const EngineType &getEngineType() const;


	bool isVehicleNew();
	virtual void print() const;
};
