#include "Animal.h"

Animal::Weight Animal::getWeight() const
{
	return weightType;
}

Animal::Consumer Animal::getConsumer() const
{
	return consumerType;
}

String Animal::getName() const
{
	return name;
}

String Animal::getSound() const
{
	return sound;
}

Array<String*> Animal::getFacts() const
{
	return facts;
}

String& Animal::getFact(const unsigned int& index) const //Niki
{
	return *facts[index];
}

String& Animal::getFoodType() const
{
	String foodType;
	if (consumerType == 0) //herbivore
	{
		foodType = "grass";
	}
	else if (consumerType == 1) //carnivore
	{
		foodType = "fresh meat";
	}
	else // omnivore
	{
		foodType = "fresh meat and grass";
	}

	return foodType;
}

double Animal::getFoodQuantity() const
{
	double foodQuantity;
	if (weightType == 0) //herbivore
	{
		foodQuantity = 0.2;
	}
	else if (weightType == 1) //carnivore
	{
		foodQuantity = 3;
	}
	else // omnivore
	{
		foodQuantity = 10;
	}

	return foodQuantity;
}