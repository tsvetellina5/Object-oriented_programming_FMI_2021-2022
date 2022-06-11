#include <iostream>
#include "Zoopark.h"
#include "Turtle.h"

const int BUFFER_SIZE = 1024;

Zoopark::Zoopark()
{
	cleaned = false;
}


void Zoopark::clean()
{
	if (cleaned)
	{
		std::cout << "Everything is already clean!" << std::endl;
	}
	else
	{
		cleaned = true;
		std::cout << "Zoopark cages were successfully cleaned!" << std::endl;
	}
}

void Zoopark::feed()
{
	std::cout << "Which animal do you want to feed? ";
	String input; std::cin >> input;
	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			std::cout << animals[i]->getName() << " was successfully fed with "
				<< animals[i]->getFoodType() << " kg of " << animals[i]->getFoodQuantity() << std::endl;
			break;
		}
	}
}

void Zoopark::addAnimal()
{
	std::cout << "What animal do you want to add? ";
	String input;  std::cin >> input;

	if (input == "turtle")
	{
		addTurtle();
	}
	//else if hippopotamus, penguin
}

void Zoopark::addTurtle()
{
	std::cout << "How do you want to call your turtle? ";
	String name; std::cin >> name;
	Animal* animal = new Turtle(name);
	animals.pushBack(animal->clone());
}

void Zoopark::printFacts()
{
	std::cout << "Which animal do you want to get facts for? ";
	String input; std::cin >> input;

	//handle string exception Niki
	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			std::cout << animals[i]->getFact(i);
		}
	}
}

void Zoopark::removeAnimal()
{
	std::cout << "What animal do you want to remove? ";
	String input;  std::cin >> input;

	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			animals.popAt(i);
			break;
		}
	}
}

