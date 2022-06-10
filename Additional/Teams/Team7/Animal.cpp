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
