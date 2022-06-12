#pragma once
#include "String.h"
#include "Food.h"

class Animal
{
private:
	int age;
	int weight;
	int caloriesNeeded;
	int caloriesEaten;
	int neededTimeToPlay;
	int timePlayed;
	String name;

protected:

	enum Origin {
		Asia,
		SouthAmerica,
		NorthAmerica,
		Europe,
		Australia,
		Africa,
		Antarctica
	} origin;

	enum TypeOfAnimal {
		Lion,
		Tiger,
		Penguin,
		CaliforniaCondor,
		Sloth,
		BrownBear
	} type;

public:
	Animal();
	Animal(const int, const int, const int, const int, const String&);
	virtual ~Animal() {};

	int getCaloriesNeeded() const;
	int getCaloriesEaten() const;
	int getAge() const;
	int getWeight() const;
	String getName() const;
	int getNeededTimeToPlay() const;
	int getTimePlayed() const;

	void setAge(const int);
	void setWeight(const int);
	void setCaloriesNeeded(const int);
	void setCaloriesEaten(const int);
	void setTimePlayed(const int);
	void setName(const String&);

	void play(const int);

	virtual void produceSound() = 0;
	virtual void printInfo() = 0;
	virtual void eat(const Food&) = 0;
	virtual String typeToStr() = 0;
	virtual String originToStr() = 0;

	virtual Animal* clone() = 0;
};
