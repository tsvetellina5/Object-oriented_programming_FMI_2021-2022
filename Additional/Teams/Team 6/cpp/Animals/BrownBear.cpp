#include <iostream>
#include "BrownBear.h"

const int BROWNBEARS_PLAYING_TIME = 105;

BrownBear::BrownBear() :Animal(), speed(0)
{
	origin = Origin::Europe;
	type = TypeOfAnimal::BrownBear;
}

BrownBear::BrownBear(const int age, const int weight, const int caloriesNeeded, const String& name, const int maxSpeed)
	: Animal(age, weight, caloriesNeeded, BROWNBEARS_PLAYING_TIME, name), speed(maxSpeed)
{
	origin = Origin::Europe;
	type = TypeOfAnimal::BrownBear;
}

int BrownBear::getSpeed() const {

	return this->speed;
}

void BrownBear::produceSound() const {

	std::cout << "Grooowl, grooowl" << std::endl;
}

String BrownBear::typeToStr() const {

	return String("Brown Bear");
}

String BrownBear::originToStr() const {

	return String("Europe");
}

void BrownBear::printInfo() const {
	std::cout << "Animal: " << typeToStr() << std::endl;
	std::cout << "From: " << originToStr() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Weight: " << getWeight() << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Calories needed per day: " << getCaloriesNeeded() << std::endl;
	std::cout << "Time needed for playing: " << BROWNBEARS_PLAYING_TIME << std::endl;
}

void BrownBear::eat(const Food& meal) {

	int eaten = getCaloriesEaten();
	int needed = getCaloriesNeeded();

	if (eaten >= needed)
	{
		throw "Brown Bear is already fed";
	}

	setCaloriesEaten(eaten + meal.getCalories());
}

Animal* BrownBear::clone() {

	return new BrownBear(*this);
}
