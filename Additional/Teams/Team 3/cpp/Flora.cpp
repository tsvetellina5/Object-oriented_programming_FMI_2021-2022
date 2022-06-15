#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Flora.h"

Flora::Flora() : Organism() {}

Flora::Flora(const StringC& name, double lifeSpan, const Vector<StringC>& habitats, const StringC& consLevel)
		: Organism(name, lifeSpan, habitats, consLevel) {}

Organism* Flora::clone() const
{
	return new Flora(*this);
}

void Flora::print() const
{
	Organism::print();
}