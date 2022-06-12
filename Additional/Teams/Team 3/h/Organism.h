#pragma once

#include <iostream>
#include <ctime>

#include "VectorC.hpp"
#include "StringC.h"

class Organism
{
protected:
	static const StringC LEVELS[7];
	
	time_t lastLevelChange;
	int conservationLevel;

	StringC speciesName;
	double lifeSpan;
	VectorC<StringC> habitats;

public:
	Organism();
	Organism(const StringC&, double, const VectorC<StringC>&, const StringC&);

	bool setConservationLevel(const StringC&);
	void setHabitats();

	void printHabitats() const;
	virtual void print() const;

	StringC getName() const;
	int getConservationLevel() const;
	StringC getConservationLevelStr() const;
	double getLifeSpan() const;

	virtual Organism* clone() const = 0;
	virtual ~Organism() = default;
};