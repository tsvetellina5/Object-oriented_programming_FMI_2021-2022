#include <iostream>
#include "CaloforniaCondor.h"

const int CONDORS_PLAYING_TIME = 40;

CaliforniaCondor::CaliforniaCondor() :Animal(), wingspan(0)
{
	origin = Origin::NorthAmerica;
	type = TypeOfAnimal::CaliforniaCondor;
}

CaliforniaCondor::CaliforniaCondor(const int age, const int weight, const int caloriesNeeded, const String& name, const int maxSpeed)
	: Animal(age, weight, caloriesNeeded, CONDORS_PLAYING_TIME, name), wingspan(maxSpeed)
{
	origin = Origin::NorthAmerica;
	type = TypeOfAnimal::CaliforniaCondor;
}

int CaliforniaCondor::getWingspan() const {

	return this->wingspan;
}

void CaliforniaCondor::produceSound() const {

	std::cout << "Grunting" << std::endl;
}

String CaliforniaCondor::typeToStr() const {

	return String("CaliforniaCondor");
}

String CaliforniaCondor::originToStr() const {

	return String("NorthAmerica");
}

void CaliforniaCondor::printInfo() const {
	std::cout << "Animal: " << typeToStr() << std::endl;
	std::cout << "From: " << originToStr() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	std::cout << "Age: " << getAge() << std::endl;
	std::cout << "Weight: " << getWeight() << std::endl;
	std::cout << "Wingspan: " << wingspan << std::endl;
	std::cout << "Calories needed per day: " << getCaloriesNeeded() << std::endl;
	std::cout << "Time needed for playing: " << CONDORS_PLAYING_TIME << std::endl;
}

void CaliforniaCondor::eat(const Food& meal) {

	if (!(meal.getType() == 2))
	{
		throw "Condors eat only meat!";
	}

	int eaten = getCaloriesEaten();
	int needed = getCaloriesNeeded();

	if (eaten >= needed)
	{
		throw "Condor is already fed";
	}

	setCaloriesEaten(eaten + meal.getCalories());
}

Animal* CaliforniaCondor::clone() {

	return new CaliforniaCondor(*this);
}
