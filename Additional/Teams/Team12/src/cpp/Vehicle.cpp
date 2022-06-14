#include "../h/Vehicle.h"

bool Vehicle::needCharging(const double distance) const {
	return distance > battery * batteryRange / 100;
}

void Vehicle::exhaustBattery(const double km){
	this -> battery = ((batteryRange - km) * 100) / batteryRange;
}

double Vehicle::getMinutesToCharge() const {
	return (batteryRange - (batteryRange * battery) / 100) / chargingRate; //t = S/v  t-time; S-distance; v-charging rate (km per min)
}
void Vehicle::chargeBattery(){
	cout << "Battery charged! It took" << getMinutesToCharge() << " minutes. \n";
	battery = 100;
}

void Vehicle::setBattery(const double battery) {
	if (battery > 100) return;
	this -> battery = battery;
}

size_t Vehicle::getVehicleId() const
{
	return vehicleID;   
}

double Vehicle::getBattery() const {
	return battery;
}

double Vehicle::getBatteryRange() const {
	return batteryRange;
}

Vehicle::Vehicle() : DriverIdentityNumber(0), vehicleID(0), model(""), battery(100), batteryRange(0), chargingRate(0) {
	type = ElectricType::UNKNOWN;
}

Vehicle::Vehicle(size_t DriverIdentityNumber,size_t vehicleID, MyString model, double batteryRange, double chargingRate) :
	DriverIdentityNumber(DriverIdentityNumber), model(""), vehicleID(vehicleID), battery(100), batteryRange(batteryRange), chargingRate(chargingRate) {
	type = ElectricType::UNKNOWN;
}

void Vehicle::display() const {
	cout << " Id: " << vehicleID << "\n Model: " << model
		<< "\n Battery at the moment: " << battery << "\n Battery range: " << batteryRange
		<< "\n Charging rate kilometer per minute: " << chargingRate << "\n";
}

