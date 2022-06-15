#pragma once
#include "Organism.h"
#include "Flora.h"
#include "Fauna.h"
#include "Fungi.h"

class RedBook
{
	Organism** list;
	size_t size, capacity;

public:

	RedBook();
	RedBook(size_t capacity);
	RedBook(const RedBook&);
	RedBook& operator=(const RedBook&);
	~RedBook();

	void printAll() const;
	void printFauna() const;
	void printFlora() const;
	void printFungi() const;

	bool addOrganism(const Organism&);
	bool removeAtIndex(size_t);
	void printConservationLevel(const StringC&) const;

	bool setConservationLevelByIndex(int, const StringC&);

	int getSpeciesIndex(const StringC&) const;
	size_t getSize() const;
	Organism* getSpeciesAt(const size_t) const;

private:
	void copy(const RedBook&);
	void free();
	void resize();
};

