#pragma once
#include "Animal.h"
#include "String.h"

class Zoopark
{
private:
	String name;
	Array<Animal*> animals;
	Array<String*> log;

public:
	Zoopark(const String&);

	void clean();
	bool feed(const String&);
	bool addAnimal(const String&);
	void menu();
	void printCommands() const;
	bool printFacts(const String&) const;
	bool removeAnimal(const String&);
	void printAll() const;
	void listLog() const;
	bool saveLogToFile() const;
private:
	void addTurtle();
	void addPenguin();
	void addHippopotamus();
};
