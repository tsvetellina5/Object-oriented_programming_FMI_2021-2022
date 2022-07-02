#pragma once
#include "ElectricBus.h"

class CityBus : public ElectricBus {
public:
	CityBus();
	CityBus(size_t, size_t, const MyString &, double, double, const MyString &, const MyString &, size_t, size_t, size_t, size_t, size_t);

	bool isItWorkingAt(size_t, size_t) const override;

	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

	void setStops(Vector<MyString>& stops);

	void addStop(MyString);
	bool addStopAtIndex(size_t index, MyString);
	bool removeStop(size_t);

	void display() const override;

private:
	size_t capacity;

};