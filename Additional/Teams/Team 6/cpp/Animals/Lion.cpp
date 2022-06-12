#include <iostream>
#include "Lion.h"

const int LIONS_PLAYING_TIME = 120;

Lion::Lion() :Animal(), speed(0), coloring("")
{
	origin = Origin::Africa;
	type = TypeOfAnimal::Lion;
}

Lion::Lion(const int age, const int weight, const int caloriesNeeded, const String& name, const int maxSpeed)
	: Animal(age, weight, caloriesNeeded, LIONS_PLAYING_TIME, name), speed(maxSpeed), coloring("Completely yellow")
{
	origin = Origin::Africa;
	type = TypeOfAnimal::Lion;
}

void Lion::setColoring(const String& coloring) {

	this->coloring = coloring;
}

int Lion::getSpeed() const {

	return this->speed;
}

void Lion::produceSound() {

	std::cout << "Roaaaar, roaaaar" << std::endl;
}

String Lion::typeToStr() {

	return String("Lion");
}

String Lion::originToStr() {

	return String("Africa");
}

void Lion::printInfo() {
	std::cout << "Animal: " << typeToStr() << std::endl;
	std::cout << "From: " << originToStr() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Weight: " << getWeight() << std::endl;
	std::cout << "Coloring: " << coloring << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Calories needed per day: " << getCaloriesNeeded() << std::endl;
	std::cout << "Time needed for playing: " << LIONS_PLAYING_TIME << std::endl;
}

void Lion::eat(const Food& meal) {

	if (!(meal.getType() == 2))
	{
		throw "Lions eat only meat!";
	}

	int eaten = getCaloriesEaten();
	int needed = getCaloriesNeeded();

	if (eaten >= needed)
	{
		throw "Lion is already fed";
	}

	setCaloriesEaten(eaten + meal.getCalories());
}

Animal* Lion::clone() {

	return new Lion(*this);
}