#pragma once
#include "Vector.h"
#include "Animal.h"

class Zoo 
{
private:
	Vector<Animal*> animals;
	Vector<Food*> food;
	Vector<String> log;

public:
	Zoo() = default;
	Zoo(const Vector<Animal*>&, const Vector<Food*>&);
	Zoo(const Zoo&);
	Zoo& operator=(const Zoo&);
	~Zoo();

	void saveToFile() const;
	void printInfoFood() const;
	void restock(int, Food*);
	void printAvailableFood() const;
	void print() const;
	void printSounds() const;
	void addAnimal(Animal*);
	void removeAnimal(int);
	void feedAnimal(int, const String&);
	void letAnimalPlay(int, int);
	void showFastestCat() const;
	void changeAnimalName(int, const String&);
	bool areAllAnimalsFed();
	bool allAnimalsPlayedEnough();

private:
	void copy(const Zoo&);
	void free();
};