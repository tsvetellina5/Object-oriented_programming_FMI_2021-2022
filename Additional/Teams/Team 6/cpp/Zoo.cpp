#include <iostream>
#include "Zoo.h"
#include "Lion.h"
#include "Tiger.h"
#include <fstream>

void Zoo::free() {

	int sizeAnimals = animals.getSize();
	int sizeFood = animals.getSize();

	for (int i = 0; i < sizeAnimals; i++)
	{
		delete animals[i];
	}

	animals.clear();

	for (int i = 0; i < sizeFood; i++)
	{
		delete food[i];
	}

	food.clear();
}

void Zoo::copy(const Zoo& other) {

	int otherSizeAnimals = other.animals.getSize();
	int otherSizeFood = other.food.getSize();

	for (int i = 0; i < otherSizeAnimals; i++)
	{
		animals.pushBack(other.animals[i]->clone());
	}

	for (int i = 0; i < otherSizeFood; i++)
	{
		food.pushBack(other.food[i]->clone());
	}
}

Zoo::Zoo(const Vector<Animal*>& animals, const Vector<Food*>& food) 
{
	this->animals = animals;
	this->food = food;
}

Zoo::Zoo(const Zoo& other)
{
	copy(other);
}

Zoo& Zoo::operator=(const Zoo& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Zoo::~Zoo()
{
	free();
}

void Zoo::saveToFile() const
{
	std::ofstream file("log.txt");

	if (!file.is_open())
		return;

	size_t size = log.getSize();
	for (size_t i = 0; i < size; i++)
	{
		file << log[i].c_str() << std::endl;
	}
}

void Zoo::printInfoFood() const
{
	std::cout << "Deer meat can be eaten by bears, lions, tigers and condors." << std::endl;
	std::cout << "Fish can be eaten by bears and penguins." << std::endl;
	std::cout << "Leaves can be eaten by bears and sloths." << std::endl;
	std::cout << "Pig meat can be eaten by bears, lions, tigers and condors." << std::endl;
	std::cout << "Squid meat can be eaten by bears and penguins." << std::endl;
}

void Zoo::restock(int amount, Food* food)
{
	if (amount < 1)
	{
		throw "Amount has to be at least 1.";
	}

	for (size_t i = 0; i < amount; i++)
	{
		this->food.pushBack(food->clone());
	}

	log.pushBack("Restock food");
	delete food;
}

void Zoo::printAvailableFood() const
{
	size_t leavesCount = 0, fishCount = 0, deerCount = 0, pigCount = 0, squidCount = 0;
	size_t size = food.getSize();
	for (size_t i = 0; i < size; i++)
	{
		const String* temp = food[i]->convertTypeToString();
		if (*temp == "Leaves")
			leavesCount++;
		else if (*temp == "Pig")
			pigCount++;
		else if (*temp == "Fish")
			fishCount++;
		else if (*temp == "Deer")
			deerCount++;
		else if (*temp == "Squid")
			squidCount++;

		delete temp;
	}

	std::cout << "Currenty stocked:\nLeaves: " << leavesCount << "\nPig meat: " << pigCount << "\nFish: " << fishCount << "\nDeer meat: " << deerCount
		<< "\nSquids: " << squidCount << std::endl;
}

void Zoo::print() const {

	for (size_t i = 0; i < animals.getSize(); i++)
	{
		animals[i]->printInfo();
		std::cout << std::endl;
	}
}

void Zoo::printSounds() const {

	for (size_t i = 0; i < animals.getSize(); i++)
	{
		animals[i]->produceSound();
	}
}

void Zoo::addAnimal(Animal* toAdd) {

	animals.pushBack(toAdd);
	log.pushBack("Animal added");
}

void Zoo::removeAnimal(int index) {
	delete animals[index];
	animals.popAt(index);
	log.pushBack("Animal removed.");
}

void Zoo::feedAnimal(int index, const String& foodName) {

	if (index < 0 || index >= animals.getSize())
	{
		throw "No such animal";
	}

	size_t size = food.getSize();

	for (size_t i = 0; i < size; i++)
	{
		const String* temp = food[i]->convertTypeToString();
		if (*temp == foodName) {
			animals[index]->eat(*food[i]);
			food.popAt(i);
			delete temp;
			log.pushBack("Animal fed.");
			return;
		}
		delete temp;
	}

	throw "No food of this type currently stocked.";
}

void Zoo::letAnimalPlay(int index, int time) {

	if (index < 0 || index >= animals.getSize())
	{
		throw "No such animal";
	}

	animals[index]->play(time);
	log.pushBack("Animal played.");
}

void Zoo::showFastestCat() const {

	int fastestIndex = -1;
	int bestSpeed = -1;

	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->typeToStr() == "Tiger")
		{
			Tiger* tiger = (Tiger*)animals[i];

			int tigersSpeed = tiger->getSpeed();

			if (tigersSpeed > bestSpeed)
			{
				bestSpeed = tigersSpeed;
				fastestIndex = i;
			}
		}
		else if (animals[i]->typeToStr() == "Lion")
		{
			if (animals[i]->typeToStr() == "Lion")
			{
				Lion* lion = (Lion*)animals[i];

				int lionsSpeed = lion->getSpeed();

				if (lionsSpeed > bestSpeed)
				{
					bestSpeed = lionsSpeed;
					fastestIndex = i;
				}
			}
		}
	}

	if (fastestIndex == -1)
	{
		throw "No big cats in this zoo";
	}

	std::cout << animals[fastestIndex]->typeToStr() << " " << animals[fastestIndex]->getName()
		<< " - " << bestSpeed << " " << "km/h" << std::endl;
}

void Zoo::changeAnimalName(int index, const String& newName) {

	if (index < 0 || index >= animals.getSize())
	{
		throw "No such animal";
	}

	animals[index]->setName(newName);
	log.pushBack("Animal name changed.");
}

bool Zoo::areAllAnimalsFed() {

	for (size_t i = 0; i < animals.getSize(); i++)
	{
		int currentCaloriesNeeded = animals[i]->getCaloriesNeeded();
		int currentCaloriesEaten = animals[i]->getCaloriesEaten();

		if (currentCaloriesEaten < currentCaloriesNeeded)
		{
			return false;
		}
	}

	return true;
}

bool Zoo::allAnimalsPlayedEnough() {

	for (size_t i = 0; i < animals.getSize(); i++)
	{
		int timeNeededToPlay = animals[i]->getNeededTimeToPlay();
		int timePlayed = animals[i]->getTimePlayed();

		if (timePlayed < timeNeededToPlay)
		{
			return false;
		}
	}

	return true;
}