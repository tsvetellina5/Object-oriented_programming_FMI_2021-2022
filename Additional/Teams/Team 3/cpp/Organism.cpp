#include "Organism.h"

const StringC Organism::LEVELS[7] = { "least concern", "near threatened", "vulnerable", "endangered", "critically endangered",
								"extinct in the wild", "extinct" };

Organism::Organism()
{
	conservationLevel = 0;
	time(&lastLevelChange);

	speciesName = "";
	lifeSpan = 0;
	habitats = VectorC<StringC>();
}

Organism::Organism(const StringC& name, double lifeSpan, const VectorC<StringC>& habitats, const StringC& consLevel)
{
	speciesName = name;
	this->lifeSpan = lifeSpan;
	this->habitats = habitats;

	setConservationLevel(consLevel);
	time(&lastLevelChange);
}

bool Organism::setConservationLevel(const StringC& consLevel)
{
	for (int i = 0; i < 7; i++)
	{
		if (LEVELS[i] == consLevel)
		{
			conservationLevel = i;
			time(&lastLevelChange);
			return true;
		}
	}

	return false;
}
void Organism::setHabitats()
{
	std::cout << "Number of habitats: ";
	int num;
	std::cin >> num;

	if (num <= 0)
		return;

	for (int i = 0; i < num; i++)
	{
		std::cout << ">";
		StringC habitat;
		habitat.getline(std::cin);
		habitats.push(habitat);
	}
}

void Organism::printHabitats() const
{
	for (int i = 0; i < habitats.getSize(); i++)
	{
		std::cout << habitats.getElement(i) << std::endl;
	}
}

void Organism::print() const
{
	std::cout << "Species name: " << speciesName << std::endl;
	std::cout << "Conservation level: " << LEVELS[conservationLevel] << std::endl;
	std::cout << "Last conservation level change: " << ctime(&lastLevelChange);
	std::cout << "Average lifespan (in years): " << lifeSpan << std::endl;
	std::cout << "Habitats: " << std::endl;
	printHabitats();
}

StringC Organism::getName() const
{
	return speciesName;
}

int Organism::getConservationLevel() const
{
	return conservationLevel;
}

StringC Organism::getConservationLevelStr() const
{
	return LEVELS[conservationLevel];
}

double Organism::getLifeSpan() const
{
	return lifeSpan;
}