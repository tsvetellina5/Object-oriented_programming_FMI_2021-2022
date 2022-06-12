#pragma once

#include "Organism.h"
#include "VectorC.hpp"
#include "StringC.h"

#include <iostream>

class Flora : public Organism
{

public:
	Flora();
	Flora(const StringC&, double, const VectorC<StringC>&, const StringC&);

	void print() const override;

	Organism* clone() const override;
};
