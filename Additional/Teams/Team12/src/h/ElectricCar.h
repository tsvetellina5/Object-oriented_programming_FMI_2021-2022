#pragma once
#include "Vehicle.h"

class ElectricCar : public Vehicle { //Electric Taxi car

	public:
		ElectricCar();
		ElectricCar(size_t, size_t, size_t, MyString, double, double);

		size_t getSpeed() const;

		void display() const override;

		bool driveVehicle(const double) override; 
		MyString getTypeString() const override;
		ElectricType getType() const override;
		Vehicle* clone() const override;

	private:
		size_t speed;

};