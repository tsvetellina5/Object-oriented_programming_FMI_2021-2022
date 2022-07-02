#include "../h/ElectricBus.h"
#include <stdexcept>

using std::cerr;

ElectricBus::ElectricBus() : Vehicle() {
	setTime(0, 0, 0, 0);
}

ElectricBus::ElectricBus(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double batteryRange, double chargingRate, MyString startDestination, MyString finalDestination, size_t sH, size_t sM, size_t fH, size_t fM) :
	Vehicle(DriverIdentityNumber, vehicleID, model, batteryRange, chargingRate) {
	listOfStops.pushBack(startDestination);
	listOfStops.pushBack(finalDestination);
	try{ setTime(sH, sM, fH, fM); }
	catch(const std::invalid_argument &e){ cerr << e.what() << '\n'; }
}

void ElectricBus::display() const {
	Vehicle::display();
	size_t indexFinalDestination = listOfStops.getSize() - 1;
	std::cout << "Starting destination: " << listOfStops[0]
	<< "\n \t At: " << startTime.hour << ":" << startTime.minutes
		<< "\n Final destination: " << listOfStops[indexFinalDestination]
		<< "\n \t At: " << finalTime.hour << ":" << finalTime.minutes << "\n";
}

void ElectricBus::addStop(const MyString &stop){ listOfStops.pushAt(stop, listOfStops.getSize() - 2); }
bool ElectricBus::removeStop(const MyString &stop){

    for(size_t i = 0; i < listOfStops.getSize(); i++)
        if(listOfStops[i] == stop){

            listOfStops.popAt(i);
            return true;

        }

    return false;

}

void ElectricBus::setTime(size_t sHour, size_t sMin, size_t fHour, size_t fMin) {
	if (!(sHour < 24 && fHour < 24 && sMin < 60 && fMin < 60 && sHour * 60 + sMin < fHour * 60 + fMin)) throw std::invalid_argument("Invalid time period");
	startTime.hour = sHour;
	startTime.minutes = sMin;
	finalTime.hour = fHour;
	finalTime.minutes = fMin;
}

bool ElectricBus::rideFromTo(const MyString &start, const MyString &end){

    bool containsStart = false, containsEnd = false;
    for(size_t i = 0; i < listOfStops.getSize(); i++){

        if(containsStart && containsEnd) break;

        containsStart = containsStart || listOfStops[i] == start;
        containsEnd = containsEnd || listOfStops[i] == end;

    }
    return containsStart && containsEnd;

}

bool ElectricBus::driveVehicle(const double km) {
	if (getBattery() <= 15 && needCharging(km)) return false;
    exhaustBattery(km);
	return true;
}