#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Fauna.h"

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