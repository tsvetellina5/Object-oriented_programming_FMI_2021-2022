#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle
{
private:
	bool doesHaveExtraHouse;
	bool hasStorageSpace;

public:
	Motorcycle();
	Motorcycle(const MyString &, const MyString &, const size_t, const size_t, const bool, const bool);

	const bool getDoesHaveExtraHouse() const;
	void setDoesHaveExtraHouse(const bool);
	const bool getHasStorageSpace() const;
	void setHasStorageSpace(const bool);

	Vehicle *clone() const override;
	void print() const override;

	friend std::ofstream &operator<<(std::ofstream &, const Motorcycle &);
	friend std::ifstream &operator>>(std::ifstream &, Motorcycle &);
};
