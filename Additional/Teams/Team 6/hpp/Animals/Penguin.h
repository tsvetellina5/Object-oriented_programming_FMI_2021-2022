#pragma once
#include "Animal.h"


class Penguin : public Animal 
{
public:
	Penguin();
	Penguin(const int age, const int weight, const int caloriesNeeded, const String& name);

	void produceSound() const override;
	void printInfo() const override;
	void eat(const Food&) override;
	String typeToStr() const override;
	String originToStr() const override;

	Animal* clone() override;
};
