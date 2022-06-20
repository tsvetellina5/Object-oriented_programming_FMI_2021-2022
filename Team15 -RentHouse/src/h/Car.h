#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	bool isSportsCar;
	bool isConvertable;

public:
	Car();
	Car(const MyString &, const MyString &, const MyString &, const size_t, const size_t, const size_t, const size_t, const bool, const bool);

	const bool getIsSportsCar() const;
	void setIsSportsCar(const bool);
	const bool getIsConvertable() const;
	void setIsConvertable(const bool);

	Vehicle *clone() const override;
	void print() const override;
	std::ofstream &save(std::ofstream &) const override;
};
