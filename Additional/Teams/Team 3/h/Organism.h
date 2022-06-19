#pragma once

#include "Vector.hpp"
#include "StringC.h"

#include <ctime>

class Organism
{
protected:
	static const StringC LEVELS[8];

	enum class conservationLevel
	{
		leastConcern = 0,
		nearThreatened,
		vulnerable,
		endangered,
		criticallyEndangered,
		extinctInTheWild,
		extinct,
		unknown
	} consLevel;
	
	time_t lastLevelChange;

	StringC speciesName;
	double lifeSpan;
	Vector<StringC> habitats;

public:
	Organism();
	Organism(const StringC&, double, const Vector<StringC>&, const StringC&);

	void setConservationLevel(const StringC&);
	void setHabitats();

	void addHabitat(const StringC&);
	bool removeHabitat(const StringC&);

	void printHabitats() const;
	virtual void print() const;

	const StringC& getName() const;
	const StringC& getConservationLevel() const;
	double getLifeSpan() const;

	conservationLevel convertStrToEnum(const StringC&);

	virtual Organism* clone() const = 0;
	virtual ~Organism() = default;
};