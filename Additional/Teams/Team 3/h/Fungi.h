#pragma once

#include "Organism.h"
#include "VectorC.hpp"
#include "StringC.h"

#include <iostream>

class Fungi : public Organism
{
	bool isPoisonous;

public:
	Fungi();
	Fungi(const StringC&, double, const VectorC<StringC>&, const StringC&, bool);

	void print() const override;

	Organism* clone() const override;
};