#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Fungi.h"

Fungi::Fungi() : Organism(), isPoisonous(false) {}

Fungi::Fungi(const StringC& name, double lifeSpan, const Vector<StringC>& habitats, const StringC& consLevel, bool poison)
		: Organism(name, lifeSpan, habitats, consLevel), isPoisonous(poison) {}

Organism* Fungi::clone() const
{
	return new Fungi(*this);
}

void Fungi::print() const
{
	Organism::print();
	std::cout << "Is poisonous: " << std::boolalpha << isPoisonous << std::endl;
}