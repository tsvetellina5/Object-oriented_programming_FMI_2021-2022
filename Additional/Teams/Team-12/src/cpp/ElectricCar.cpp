#include "../h/ElectricCar.h"

ElectricCar::ElectricCar() : Vehicle() {
	type = ElectricType::E_CAR;
}

ElectricCar::ElectricCar(size_t DriverIdentityNumber, size_t vehicleID, size_t speed, MyString model, double batteryRange, double chargingRate) :
	Vehicle(DriverIdentityNumber, vehicleID, model, batteryRange, chargingRate), speed(speed){
	type = ElectricType::E_CAR;
}

size_t ElectricCar::getSpeed() const{ return speed; }

bool ElectricCar::driveVehicle(const double km) {
	if (getBattery() <= 10 || needCharging(km)) return false;
	exhaustBattery(km);
	return true;
}

MyString ElectricCar::getTypeString() const {
	return "Electric Car";
}

Vehicle::ElectricType ElectricCar::getType() const {
	return ElectricType::E_CAR;
}

Vehicle* ElectricCar::clone() const {
	return new ElectricCar(*this);
}

void ElectricCar::display() const {
	std::cout << "Electric Taxi car's";
	Vehicle::display();
}