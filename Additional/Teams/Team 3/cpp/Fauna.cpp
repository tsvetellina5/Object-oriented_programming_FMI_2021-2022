#include "Fauna.h"

#include <iostream>

Fauna::Fauna() : Organism(), isPredator(false) {}

Fauna::Fauna(const StringC& name, double lifeSpan, const Vector<StringC>& habitats, const StringC& consLevel, bool isPredator)
	: Organism(name, lifeSpan, habitats, consLevel), isPredator(isPredator) {}

Organism* Fauna::clone() const
{
	return new Fauna(*this);
}

void Fauna::print() const
{
	Organism::print();
	std::cout << "Is predator: " << std::boolalpha << isPredator << std::endl;
}