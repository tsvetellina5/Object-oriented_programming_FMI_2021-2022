#pragma once
#include "Animal.h"

class Tiger : public Animal
{
private:
	int speed;
	String coloring;

protected:
	void setColoring(const String&);

public:
	Tiger();
	Tiger(const int, const int, const int, const String&, const int);

	int getSpeed() const;

	void produceSound() override;
	void printInfo() override;
	void eat(const Food&) override;
	String typeToStr() override;
	String originToStr() override;

	Animal* clone() override;
};