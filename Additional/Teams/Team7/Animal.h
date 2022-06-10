#pragma once
#include "String.h"
#include "Array.h"

class Animal
{
protected:

	enum Weight
	{
		LIGHT, MEDIUM, HEAVY
	}weightType;

	enum Consumer
	{
		HERBIVORE, CARNIVORE, OMNIVORE
	}consumerType;

private:
	String name;
	String sound;
	Array<String*> facts;

public:

	Animal::Weight getWeight() const;
	Animal::Consumer getConsumer() const;
	String getName() const;
	String getSound() const;
	Array<String*> getFacts() const;

	virtual Animal* clone() const = 0;
	virtual void makeSound() = 0;
};