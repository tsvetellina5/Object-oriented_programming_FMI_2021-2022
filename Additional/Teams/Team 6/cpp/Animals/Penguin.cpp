#include <iostream>
#include "Penguin.h"

const int PENGUINS_PLAYING_TIME = 200;

Penguin::Penguin() :Animal() 
{}

Penguin::Penguin(const int age, const int weight, const int caloriesNeeded, const String& name)
	: Animal(age, weight, caloriesNeeded, PENGUINS_PLAYING_TIME, name)
{}

void Penguin::produceSound() {

	std::cout << "Squawk, squawk, squawk" << std::endl;
}

String Penguin::typeToStr() {

	return String("Penguin");
}

String Penguin::originToStr() {

	return String("Antarctica");
}

void Penguin::printInfo() {
	std::cout << "Animal: " << typeToStr() << std::endl;
	std::cout << "From: " << originToStr() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Weight: " << getWeight() << std::endl;
	std::cout << "Calories needed per day: " << getCaloriesNeeded() << std::endl;
	std::cout << "Time needed for playing: " << PENGUINS_PLAYING_TIME << std::endl;
}

void Penguin::eat(const Food& meal) {

	if (!(meal.getType() == 1))
	{
		throw "Penguins eat only seafood!";
	}

	int eaten = getCaloriesEaten();
	int needed = getCaloriesNeeded();

	if (eaten >= needed)
	{
		throw "Penguin is already fed";
	}

	setCaloriesEaten(eaten + meal.getCalories());
}

Animal* Penguin::clone() {

	return new Penguin(*this);
}