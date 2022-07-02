#pragma once
#include "Animal.h"

class Lion : public Animal {

private:
	int speed;
	String coloring;

protected:
	void setColoring(const String&);

public:
	Lion();
	Lion(const int, const int, const int, const String&, const int);

	int getSpeed() const;

	void produceSound() const override;
	void printInfo() const override;
	void eat(const Food&) override;
	String typeToStr() const override;
	String originToStr() const override;

	Animal* clone() override;
};
