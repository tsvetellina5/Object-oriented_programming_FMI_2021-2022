#include <iostream>
#include "Tiger.h"

const int TIGERS_PLAYING_TIME = 145;

Tiger::Tiger() :Animal(), speed(0), coloring("")
{
	origin = Origin::Asia;
	type = TypeOfAnimal::Tiger;
}

Tiger::Tiger(const int age, const int weight, const int caloriesNeeded, const String& name, const int maxSpeed)
	: Animal(age, weight, caloriesNeeded, TIGERS_PLAYING_TIME, name), speed(maxSpeed), coloring("Orange with black stripes")
{
	origin = Origin::Asia;
	type = TypeOfAnimal::Tiger;
}

void Tiger::setColoring(const String& coloring) {

	this->coloring = coloring;
}

int Tiger::getSpeed() const {

	return this->speed;
}

void Tiger::produceSound() {

	std::cout << "Roaaaaaar" << std::endl;
}

String Tiger::typeToStr() {

	return String("Tiger");
}

String Tiger::originToStr() {

	return String("Asia");
}

void Tiger::printInfo() {
	std::cout << "Animal: " << typeToStr() << std::endl;
	std::cout << "From: " << originToStr() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Weight: " << getWeight() << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Caloring: " << coloring << std::endl;
	std::cout << "Calories needed per day: " << getCaloriesNeeded() << std::endl;
	std::cout << "Time needed for playing: " << TIGERS_PLAYING_TIME << std::endl;
}

void Tiger::eat(const Food& meal) {

	if (!(meal.getType() == 2))
	{
		throw "Tigers eat only meat!";
	}

	int eaten = getCaloriesEaten();
	int needed = getCaloriesNeeded();

	if (eaten >= needed)
	{
		throw "Tiger is already fed";
	}

	setCaloriesEaten(eaten + meal.getCalories());
}

Animal* Tiger::clone() {

	return new Tiger(*this);
}