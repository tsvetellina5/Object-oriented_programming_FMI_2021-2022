#include <iostream>
#include "Zoopark.h"
#include "Turtle.h"
#include "Penguin.h"
#include "Hippopotamus.h"

const int BUFFER_SIZE = 1024;

Zoopark::Zoopark(const String& name)
{
	this->name = name;
}

void Zoopark::clean()
{
	bool dirtyCages = false;
	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (!animals[i]->isClean())
		{
			dirtyCages = true;
			std::cout << animals[i]->getName() << "'s cage was successfully cleaned!" << std::endl;
			animals[i]->isClean(true);
		}
	}
	if (!dirtyCages)
	{
		std::cout << "Everything is already clean!";
	}
}

bool Zoopark::feed(const String& input)
{
	bool found = false;
	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			if (animals[i]->isClean())
			{
				std::cout << animals[i]->getName() << " was successfully fed with "
					<< animals[i]->getFoodQuantity() << " kg of " << animals[i]->getFoodType() << "!" << std::endl;
				animals[i]->isClean(false);

				String* l = new String[1];
				l[0].setCurrentTime();
				l[0] += " successfully fed ";
				l[0] += animals[i]->getName();
				log.pushBack(l->clone());
			}
			else
			{
				std::cout << "You can't feed " << animals[i]->getName() << " before cleaning its cage!" << std::endl;
			}
			found = true;
			break;
		}
	}
	return found;
}

bool Zoopark::addAnimal(const String& input)
{	
	String* l = new String[1];
	l[0].setCurrentTime();
	
	if (input == "turtle")
	{
		addTurtle();
	
		l[0] += " added a new turtle named ";
	}
	else if (input == "penguin") {
		addPenguin();
		l[0] += " added a new penguin named ";
	}
	else if (input == "hippopotamus") {
		addHippopotamus();
		l[0] += " added a new hippopotamus named ";
	}
	else {
		return false;
	}

	l[0] += animals[animals.getSize()-1]->getName();
	log.pushBack(l->clone());
	
	return true;
}

void Zoopark::addTurtle()
{
	std::cout << "How do you want to call your turtle? ";
	String name; std::cin >> name;
	Animal* animal = new Turtle(name);
	animals.pushBack(animal->clone());
	std::cout << "The animal was successfully added!" << std::endl;
}

void Zoopark::addPenguin()
{
	std::cout << "How do you want to call your penguin? ";
	String name; std::cin >> name;
	Animal* animal = new Penguin(name);
	animals.pushBack(animal->clone());
	std::cout << "The animal was successfully added!" << std::endl;
}


void Zoopark::addHippopotamus()
{
	std::cout << "How do you want to call your hippopotamus? ";
	String name; std::cin >> name;
	Animal* animal = new Hippopotamus(name);
	animals.pushBack(animal->clone());
	std::cout << "The animal was successfully added!" << std::endl;
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
			std::cout << "Which animal do you want to feed? ";
			String input; std::cin >> input;
			if (!feed(input))
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "add")
		{
			std::cout << "What animal do you want to add? ";
			String input;  std::cin >> input;
			if (!addAnimal(input))
				std::cout << "That animal is not supported!";
			std::cout << std::endl;
		}
		else if (cmd == "remove")
		{
			std::cout << "What animal do you want to remove? ";
			String input;  std::cin >> input;
			if (!removeAnimal(input))
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "printFacts")
		{
			std::cout << "Which animal do you want to get facts for? ";
			String input; std::cin >> input;
			if (!printFacts(input))
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "printAll") {
			printAll();
			std::cout << std::endl;
		}
		else if (cmd == "listLog") {
			listLog();
			std::cout << std::endl;
		}
		else if (cmd == "save") {
			if (!saveLogToFile())
				std::cout << "File not opened!" << std::endl;
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
	std::cout << "\tlistLog - lists the current log file" << std::endl;
	std::cout << "\tsave - saves the loginto a .txt file" << std::endl;
}

bool Zoopark::printFacts(const String& input) const
{
	bool found = false;

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

bool Zoopark::removeAnimal(const String& input)
{
	bool found = false;

	for (unsigned int i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			String* l = new String[1];
			l[0].setCurrentTime();
			l[0] += " removed ";
			l[0] += animals[i]->getName();
			log.pushBack(l->clone());

			animals.popAt(i);
			found = true;
			std::cout << "The animal was successfully removed!" << std::endl;
			
			break;
		}
	}
	return found;
}

void Zoopark::printAll() const
{
	for (unsigned int i = 0; i < animals.getSize(); i++) {
		std::cout << "\t" << i + 1 << ".";
		animals[i]->print();
		std::cout << std::endl;
	}
}

void Zoopark::listLog() const
{
	for (unsigned int i = 0; i < log.getSize(); i++)
		std::cout << i + 1 << ". " << *log[i] << std::endl;
}

bool Zoopark::saveLogToFile() const
{
	std::cout << "How would like to name your file? \nFiles with the same name will be overwritten! ";
	String fName;
	std::cin >> fName;
	fName += ".txt";
	std::ofstream ofile(fName.getStr());

	if (!ofile.is_open()) {
		return false;
	}
	for (unsigned int i = 0; i < log.getSize(); i++)
		ofile << i + 1 << ". " << log[i]->getStr() << std::endl;
	ofile.close();

	return true;
}
