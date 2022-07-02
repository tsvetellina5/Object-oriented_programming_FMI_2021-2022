#include "../h/ElectricScooter.h"

ElectricScooter::ElectricScooter() : Vehicle() {
	type = ElectricType::E_SCOOTER;
}

ElectricScooter::ElectricScooter(size_t vehicleID, MyString model, double batteryRange, double chargingRate) : Vehicle(0, vehicleID, model, batteryRange, chargingRate) {
	type = ElectricType::E_SCOOTER;
}

void ElectricScooter::occupy(){ isFree = false; }
void ElectricScooter::free(){ isFree = true; }
bool ElectricScooter::isOccupied() const{ return isFree; }

bool ElectricScooter::driveVehicle(const double km) {
	if (getBattery() <= 5 || needCharging(km)) return false;
	exhaustBattery(km);
	return true;
}

MyString ElectricScooter::getTypeString() const {
	return "Electric Scooter";
}

Vehicle::ElectricType ElectricScooter::getType() const {
	return ElectricType::E_SCOOTER;
}

Vehicle* ElectricScooter::clone() const {
	return new ElectricScooter(*this);
}

void ElectricScooter::display() const{
	std::cout << " Scooter's";
	Vehicle::display();
}