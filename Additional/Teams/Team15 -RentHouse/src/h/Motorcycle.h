#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private:
	bool doesHaveSideCar;
	bool hasStorageSpace;

public:
	Motorcycle();
	Motorcycle(const MyString &, const MyString &, const MyString &, const size_t, const size_t, const size_t, const size_t, const bool, const bool);

	const bool getDoesHaveSideCar() const;
	void setDoesHaveSideCar(const bool);
	const bool getHasStorageSpace() const;
	void setHasStorageSpace(const bool);

	Vehicle *clone() const override;
	void print() const override;
	std::ofstream &save(std::ofstream &) const override;
};
