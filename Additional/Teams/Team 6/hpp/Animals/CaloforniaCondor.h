#pragma once
#include "Animal.h"

class CaliforniaCondor : public Animal
{
private:
	int wingspan;

public:
	CaliforniaCondor();
	CaliforniaCondor(const int, const int, const int, const String&, const int);

	int getWingspan() const;

	void produceSound() const override;
	void printInfo() const override;
	void eat(const Food&) override;
	String typeToStr() const override;
	String originToStr() const override;

	Animal* clone() override;
};
