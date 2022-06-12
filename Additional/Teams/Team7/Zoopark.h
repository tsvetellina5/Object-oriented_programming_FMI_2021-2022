#pragma once
#include "Animal.h"
#include "String.h"

class Zoopark
{
private:
	String name;
	Array<Animal*> animals;
	bool cleaned;

public:
	Zoopark(); //Niki 

	void clean();
	void feed();
	void addAnimal();
	void menu();
	void printCommands() const;
	void printFacts() const;
	void removeAnimal();
	void printAll();
private:
	void addTurtle();
	void addPenguin();
	// addHippopotamus
};