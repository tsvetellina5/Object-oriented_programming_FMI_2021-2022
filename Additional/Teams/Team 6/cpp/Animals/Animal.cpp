#include "Animal.h"
#pragma warning(disable: 4996)

Animal::Animal():age(0), weight(0), caloriesNeeded(0), neededTimeToPlay(0), name(""), caloriesEaten(0), timePlayed(0)
{}

Animal::Animal(int age, int weight, int caloriesNeeded, const int timeForPlaying, const String& name) 
	: age(age), weight(weight), caloriesNeeded(caloriesNeeded), neededTimeToPlay(timeForPlaying), 
	name(name), caloriesEaten(0), timePlayed(0)
{}

void Animal::setAge(int age) {

	this->age = age;
}

void Animal::setWeight(int weight) {

	this->weight = weight;
}

void Animal::setCaloriesNeeded(int caloriesNeeded) {

	this->caloriesNeeded = caloriesNeeded;
}

void Animal::setCaloriesEaten(const int eaten) {

	this->caloriesEaten = eaten;
}

void Animal::setTimePlayed(const int time) {

	this->timePlayed = time;
}

void Animal::setName(const String& name) {

	this->name = name;
}

int Animal::getAge() const {

	return this->age;
}

int Animal::getCaloriesNeeded() const {

	return this->caloriesNeeded;
}

int Animal::getNeededTimeToPlay() const {

	return this->neededTimeToPlay;
}

int Animal::getCaloriesEaten() const {

	return this->caloriesEaten;
}

int Animal::getTimePlayed() const {

	return this->timePlayed;
}

int Animal::getWeight() const {

	return this->weight;
}

const String& Animal::getName() const {

	return this->name;
}

void Animal::play(const int time) {

	int timeNeeded = getNeededTimeToPlay();
	int timePlayed = getTimePlayed();

	if (timePlayed >= timeNeeded)
	{
		throw "Already tired for playing";
	}

	setTimePlayed(timePlayed + time);
}
