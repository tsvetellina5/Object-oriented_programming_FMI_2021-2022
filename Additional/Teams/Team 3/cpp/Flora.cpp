#include "Flora.h"

#include <iostream>

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