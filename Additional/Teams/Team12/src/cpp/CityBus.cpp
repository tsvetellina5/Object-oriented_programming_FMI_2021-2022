#include "../h/CityBus.h"

CityBus::CityBus() : ElectricBus() {
	type = Vehicle::ElectricType::E_CITY_BUS;
}

CityBus::CityBus(size_t DriverIdentityNumber,size_t vehicleID, MyString model, double batteryRange, double chargingRate, MyString startDestination, MyString finalDestination, size_t sH, size_t sM, size_t fH, size_t fM, size_t capacity) :
	ElectricBus(DriverIdentityNumber, vehicleID, model, batteryRange, chargingRate, startDestination, finalDestination, sH, sM, fH, fM), capacity(capacity) {
	type = Vehicle::ElectricType::E_CITY_BUS;

}

bool CityBus::isItWorkingAt(size_t h, size_t m) const{

	return startTime.hour * 60 + startTime.minutes < h * 60 + m && h * 60 + m < finalTime.hour * 60 + finalTime.minutes;

}

MyString CityBus::getTypeString() const{
	return "Electric City Bus";
}

Vehicle::ElectricType CityBus::getType() const {
	return ElectricType::E_CITY_BUS;
}

Vehicle* CityBus::clone() const {
	return new CityBus(*this);
}

void CityBus::setStops(Vector<MyString>& stops) {
	listOfStops = stops;
}

void CityBus::addStop(MyString stop) {
	listOfStops.pushBack(stop);
}

bool CityBus::addStopAtIndex(size_t index, MyString stop) {
	if (index > listOfStops.getCapacity()) {
		return false;
	}
	listOfStops.pushAt(stop, index - 1);
	return true;
}

bool CityBus::removeStop(size_t index) {
	if (index >= listOfStops.getSize()) {
		return false;
	}
	listOfStops.popAt(index - 1);
	return true;
}

void CityBus::display() const {
	std::cout << "City bus'";
	ElectricBus::display();
	std::cout << "List of stops:\n";
	for (size_t i = 0; i < listOfStops.getSize(); i++) {
		std::cout << "\t\t" << listOfStops[i] << std::endl;
	}
}