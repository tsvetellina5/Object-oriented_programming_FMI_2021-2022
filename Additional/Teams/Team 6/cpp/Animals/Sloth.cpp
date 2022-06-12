#include <iostream>
#include "Sloth.h"

const int SLOTHS_PLAYING_TIME = 100;

Sloth::Sloth() :Animal(), speed(0)
{
	origin = Origin::SouthAmerica;
	type = TypeOfAnimal::Sloth;
}

Sloth::Sloth(const int age, const int weight, const int caloriesNeeded, const String& name, const int maxSpeed)
	: Animal(age, weight, caloriesNeeded, SLOTHS_PLAYING_TIME, name), speed(maxSpeed)
{
	origin = Origin::SouthAmerica;
	type = TypeOfAnimal::Sloth;
}

int Sloth::getSpeed() const {

	return this->speed;
}

void Sloth::produceSound() {

	std::cout << "Aahh-eeeeeee" << std::endl;
}

String Sloth::typeToStr() {

	return String("Sloth");
}

String Sloth::originToStr() {

	return String("South America");
}

void Sloth::printInfo() {
	std::cout << "Animal: " << typeToStr() << std::endl;
	std::cout << "From: " << originToStr() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Weight: " << getWeight() << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Calories needed per day: " << getCaloriesNeeded() << std::endl;
	std::cout << "Time needed for playing: " << SLOTHS_PLAYING_TIME << std::endl;
}

void Sloth::eat(const Food& meal) {

	if (!(meal.getType() == 0))
	{
		throw "Sloths eat only plants.";
	}

	int eaten = getCaloriesEaten();
	int needed = getCaloriesNeeded();

	if (eaten >= needed)
	{
		throw "Sloth is already fed";
	}

	setCaloriesEaten(eaten + meal.getCalories());
}

Animal* Sloth::clone() {

	return new Sloth(*this);
}