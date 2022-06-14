#include "../h/InterCityBus.h"

IntercityBus::IntercityBus() : ElectricBus() {
	type = Vehicle::ElectricType::E_INTERCITY_BUS;
}

IntercityBus::IntercityBus(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double batteryRange, double chargingRate, MyString startDestination, MyString finalDestination, size_t sH, size_t sM, size_t fH, size_t fM, size_t bH, size_t bM, size_t breakMinutes, MyString breakStop) :
	ElectricBus(DriverIdentityNumber, vehicleID, model, batteryRange, chargingRate, startDestination, finalDestination, sH, sM, fH, fM), breakStop(breakStop), breakMinutes(breakMinutes) {
	type = Vehicle::ElectricType::E_INTERCITY_BUS;
	listOfStops.pushAt(breakStop, listOfStops.getSize() - 2);
	breakTime.hour = bH;
	breakTime.minutes = bM;
}

bool IntercityBus::isItWorkingAt(size_t h, size_t m) const{

	return startTime.hour * 60 + startTime.minutes < h * 60 + m && h * 60 + m < finalTime.hour * 60 + finalTime.minutes;

}

MyString IntercityBus::getTypeString() const {
	return "Electric Intecrity Bus";
}

Vehicle::ElectricType IntercityBus::getType() const {
	return ElectricType::E_INTERCITY_BUS;
}

Vehicle* IntercityBus::clone() const {
	return new IntercityBus(*this);
}

void IntercityBus::display() const {
	std::cout << "Intercity bus'";
	ElectricBus::display();
	std::cout << "\t Break time: " << breakTime.hour << ":" << breakTime.minutes << " for " << breakMinutes << " minutes\n";
}

double IntercityBus::calculateNeededBatteryForDistance(const double distance) const {
	double res = (distance * 100) / getBatteryRange();
	return res > 100 ? -1 : res;
}


MyString IntercityBus::getBreakDestination() const{ return breakStop; }