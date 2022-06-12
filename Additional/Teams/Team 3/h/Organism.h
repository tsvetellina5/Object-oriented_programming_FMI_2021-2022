#pragma once

#include <iostream>
#include <ctime>

#include "Vector.hpp"
#include "StringC.h"

class Organism
{
protected:
	static const StringC LEVELS[7];
	
	time_t lastLevelChange;
	int conservationLevel;

	StringC speciesName;
	double lifeSpan;
	Vector<StringC> habitats;

public:
	Organism();
	Organism(const StringC&, double, const Vector<StringC>&, const StringC&);

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