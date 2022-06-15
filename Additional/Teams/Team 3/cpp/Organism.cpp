#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Organism.h"

const StringC Organism::LEVELS[8] = { "least concern", "near threatened", "vulnerable", "endangered", "critically endangered",
								"extinct in the wild", "extinct", "unknown" };

Organism::Organism()
{
	consLevel = (conservationLevel)0;

	time(&lastLevelChange);

	speciesName = "";
	lifeSpan = 0;
	habitats = Vector<StringC>();
}

Organism::Organism(const StringC& name, double lifeSpan, const Vector<StringC>& habitats, const StringC& consLevel)
{
	speciesName = name;
	this->lifeSpan = lifeSpan;
	this->habitats = habitats;

	setConservationLevel(consLevel);
	time(&lastLevelChange);
}

Organism::conservationLevel Organism::convertStrToEnum(const StringC& str)
{
	if (str == "least concern")
		return conservationLevel::leastConcern;
	if (str == "near threatened")
		return conservationLevel::nearThreatened;
	if (str == "vulnerable")
		return conservationLevel::vulnerable;
	if (str == "endangered")
		return conservationLevel::endangered;
	if (str == "critically endangered")
		return conservationLevel::criticallyEndangered;
	if (str == "extinct in the wild")
		return conservationLevel::extinctInTheWild;
	if (str == "extinct")
		return conservationLevel::extinct;

	return conservationLevel::unknown;
}

void Organism::setConservationLevel(const StringC& consLevel)
{
	this->consLevel = convertStrToEnum(consLevel);
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
		habitats.pushBack(habitat);
	}
}

void Organism::addHabitat(const StringC& newHabitat)
{
	habitats.pushBack(newHabitat);
}

bool Organism::removeHabitat(const StringC& remHabitat)
{
	for (size_t i = 0; i < habitats.getSize(); i++)
	{
		if (habitats.At(i) == remHabitat)
		{
			habitats.popAt(i);
			return true;
		}
	}
	return false;
}

void Organism::printHabitats() const
{
	for (int i = 0; i < habitats.getSize(); i++)
		std::cout << habitats[i] << std::endl;
}

void Organism::print() const
{
	std::cout << "Species name: " << speciesName << std::endl;
	std::cout << "Conservation level: " << LEVELS[(int)consLevel] << std::endl;
	std::cout << "Last conservation level change: " << ctime(&lastLevelChange);
	std::cout << "Average lifespan (in years): " << lifeSpan << std::endl;
	std::cout << "Habitats: " << std::endl;
	printHabitats();
}

const StringC& Organism::getName() const
{
	return speciesName;
}

const StringC& Organism::getConservationLevel() const
{
	return LEVELS[(int)consLevel];
}

double Organism::getLifeSpan() const
{
	return lifeSpan;
}