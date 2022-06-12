#include <iostream>
#include "Zoopark.h"
#include "Turtle.h"
#include "Penguin.h"

const int BUFFER_SIZE = 1024;

Zoopark::Zoopark()
{
	std::cout << "What is the name of the zoopark? ";
	char* nameT = new char[1024];
	std::cin.getline(nameT, 1024);
	name = nameT;
	delete[] nameT;
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

bool Zoopark::feed()
{
	bool found = false;
	std::cout << "Which animal do you want to feed? ";
	String input; std::cin >> input;
	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			std::cout << animals[i]->getName() << " was successfully fed with "
				<< animals[i]->getFoodQuantity() << " kg of " << animals[i]->getFoodType() << "!" << std::endl;
			found = true;
			break;
		}
	}
	return found;
}

bool Zoopark::addAnimal()
{
	std::cout << "What animal do you want to add? ";
	String input;  std::cin >> input;

	if (input == "turtle")
	{
		addTurtle();
	}
	else if (input == "penguin") {
		addPenguin();
	}
	//else if hippopotamus
	else {
		return false;
	}
	return true;
}

void Zoopark::addTurtle()
{
	std::cout << "How do you want to call your turtle? ";
	String name; std::cin >> name;
	Animal* animal = new Turtle(name);
	animals.pushBack(animal->clone());
}

void Zoopark::addPenguin()
{
	std::cout << "How do you want to call your penguin? ";
	String name; std::cin >> name;
	Animal* animal = new Penguin(name);
	animals.pushBack(animal->clone());
}

void Zoopark::menu()
{
	printCommands();
	while (true) {
		std::cout << "> ";
		String cmd;
		std::cin >> cmd;
		if (cmd == "cmd") {
			printCommands();
			std::cout << std::endl;
		}
		else if (cmd == "clean") {
			clean();
			std::cout << std::endl;
		}
		else if (cmd == "feed") {
			if (!feed())
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "add")
		{
			if (!addAnimal())
				std::cout << "That animal is not supported!";
			std::cout << std::endl;
		}
		else if (cmd == "remove")
		{
			if (!removeAnimal())
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "printFacts")
		{
			if (!printFacts())
				std::cout<<"Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "printAll") {
			printAll();
			std::cout << std::endl;
		}
		else if (cmd == "exit") {
			break;
		}
		else {
			std::cout << "Could not find that command!" << std::endl;
		}

	}
}

void Zoopark::printCommands() const
{
	std::cout << "\tcmd - lists all commands" << std::endl;
	std::cout << "\tclean - cleans all cages if dirty" << std::endl;
	std::cout << "\tfeed - feeds a certain animal" << std::endl;
	std::cout << "\tadd - adds a new animal" << std::endl;
	std::cout << "\tremove - removes an animal" << std::endl;
	std::cout << "\tprintFacts - prints facts about a certain animal's species" << std::endl;
	std::cout << "\tprintAll - prints all animals in the zoo" << std::endl;
}

bool Zoopark::printFacts() const
{
	bool found = false;
	std::cout << "Which animal do you want to get facts for? ";
	String input; std::cin >> input;

	for (unsigned int i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			std::cout << animals[i]->getFacts();
			std::cout << std::endl;
			found = true;
			break;
		}
	}
	return found;
}

bool Zoopark::removeAnimal()
{
	bool found=false;

	std::cout << "What animal do you want to remove? ";
	String input;  std::cin >> input;

	for (unsigned int i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			animals.popAt(i);
			found = true;
			break;
		}
	}
	
	return found;
}

void Zoopark::printAll()
{
	for (unsigned int i = 0; i < animals.getSize(); i++) {
		std::cout << "\t" << i + 1 << ".";
		animals[i]->print();
		std::cout << std::endl;
	}
}
