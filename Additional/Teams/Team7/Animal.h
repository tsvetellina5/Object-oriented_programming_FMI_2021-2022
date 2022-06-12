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

	String name;
	String sound;
	String facts;

public:

	Animal::Weight getWeight() const;
	Animal::Consumer getConsumer() const;
	String getName() const;
	String getSound() const;
	String getFacts() const;
	String getFoodType() const;
	double getFoodQuantity() const;

	virtual void print() const=0;
	virtual bool setFacts() = 0;
	virtual Animal* clone() const = 0;
	virtual void makeSound() = 0;
};