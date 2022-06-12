#pragma once
#pragma once
#include "Animal.h"

class Sloth : public Animal {

private:
	int speed;

public:
	Sloth();
	Sloth(const int, const int, const int, const String&, const int);

	int getSpeed() const;

	void produceSound() override;
	void printInfo() override;
	void eat(const Food&) override;
	String typeToStr() override;
	String originToStr() override;

	Animal* clone() override;
};