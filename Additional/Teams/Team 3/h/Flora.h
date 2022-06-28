#pragma once

#include "Organism.h"
#include "Vector.hpp"
#include "StringC.h"

class Flora : public Organism
{

public:
	Flora();
	Flora(const StringC&, double, const Vector<StringC>&, const StringC&);

	void print() const override;

	Organism* clone() const override;
};
