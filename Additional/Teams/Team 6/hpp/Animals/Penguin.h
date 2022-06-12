#include "Animal.h"
#pragma once


class Penguin : public Animal 
{
public:
	Penguin();
	Penguin(const int age, const int weight, const int caloriesNeeded, const String& name);

	void produceSound() override;
	void printInfo() override;
	void eat(const Food&) override;
	String typeToStr() override;
	String originToStr() override;

	Animal* clone() override;
};