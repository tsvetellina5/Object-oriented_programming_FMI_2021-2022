#include "Animal.h"
#pragma once

class CaliforniaCondor : public Animal
{
private:
	int wingspan;

public:
	CaliforniaCondor();
	CaliforniaCondor(const int, const int, const int, const String&, const int);

	int getWingspan() const;

	void produceSound() override;
	void printInfo() override;
	void eat(const Food&) override;
	String typeToStr() override;
	String originToStr() override;

	Animal* clone() override;
};