#include "RedBook.h"

void RedBook::copy(const RedBook& other) {
	size = other.size;
	capacity = other.capacity;
	list = new Organism * [capacity];

	for (size_t i = 0; i < size; i++) {
		list[i] = other.list[i]->clone();
	}
}

void RedBook::free() {

	for (size_t i = 0; i < size; i++)
		delete list[i];

	delete[] list;
}

void RedBook::resize() {
	Organism** tmp = new Organism * [capacity *= 2];

	for (size_t i = 0; i < size; i++)
		tmp[i] = list[i];

	delete[] list;
	list = tmp;
}

RedBook::RedBook() {
	size = 0;
	capacity = 4;
	list = new Organism * [capacity];
}

RedBook::RedBook(size_t capacity) {
	this->capacity = capacity;
	size = 0;
	list = new Organism * [capacity];
}

RedBook::RedBook(const RedBook& other) {
	copy(other);
}

RedBook& RedBook::operator=(const RedBook& other) {
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

RedBook::~RedBook() {
	free();
}

bool RedBook::addOrganism(const Organism& newOrganism) {
	if (getSpeciesIndex(newOrganism.getName()) != -1)
		return false;

	if (size >= capacity)
		resize();

	list[size++] = newOrganism.clone();
}

bool RedBook::removeAtIndex(size_t index) {
	if (index >= size)
		return false;

	delete list[index];

	list[index] = list[size - 1];
	list[size - 1] = nullptr;
	size--;

	return true;
}

void RedBook::printAll() const {
	for (size_t i = 0; i < size; i++) {
		list[i]->print();
		std::cout << std::endl;
	}
}

void RedBook::printConservationLevel(const StringC& level) const {
	for (size_t i = 0; i < size; i++) {
		if (list[i]->getConservationLevel() == level)
			list[i]->print();
	}
}

void RedBook::printFauna() const {
	for (int i = 0; i < size; i++)
	{
		Fauna* tmp = dynamic_cast<Fauna*>(list[i]);

		if (tmp == nullptr)
			continue;

		tmp->print();
	}
}

void RedBook::printFlora() const {
	for (int i = 0; i < size; i++)
	{
		Flora* tmp = dynamic_cast<Flora*>(list[i]);

		if (tmp == nullptr)
			continue;

		tmp->print();
	}
}

void RedBook::printFungi() const {
	for (int i = 0; i < size; i++)
	{
		Fungi* tmp = dynamic_cast<Fungi*>(list[i]);

		if (tmp == nullptr)
			continue;

		tmp->print();
	}
}

bool RedBook::setConservationLevelByIndex(int index, const StringC& level)
{
	if (index < 0 || index >= size)
		return false;

	if (list[index]->getConservationLevel() == "extinct")
		return false;

	list[index]->setConservationLevel(level);
	return true;
}

int RedBook::getSpeciesIndex(const StringC& name) const
{
	for (int i = 0; i < size; i++)
	{
		if (list[i]->getName() == name)
			return i;
	}

	return -1;
}

size_t RedBook::getSize() const
{
	return size;
}

Organism* RedBook::getSpeciesAt(const size_t index) const
{
	if (index >= size)
	{
		return nullptr;
	}
	return list[index]->clone();
}

bool RedBook::addFaunaFromUserInput()
{
	StringC name, habitat, consLvL, con;
	int lifespan, consoleConsLvl, habNum;
	bool isPredator;

	std::cout << "    name:";
	std::cin >> name;
	std::cout << "    lifespan:";
	std::cin >> lifespan;
	std::cout << "    habitats count:";
	std::cin >> habNum;
	std::cin.ignore();

	if (habNum <= 0)
	{
		std::cout << "Habitats have to be at least one." << std::endl;
		return false;
	}

	Vector<StringC> habitats;

	for (size_t i = 0; i < habNum; i++)
	{
		std::cout << "\t >";
		habitat.getline(std::cin);
		habitats.pushBack(habitat);
	}
	
	std::cout << "    conservation lvl (from 0 to 6):";
	std::cin >> consoleConsLvl;

	switch (consoleConsLvl)
	{
	case 0: consLvL = "least concern"; break;
	case 1: consLvL = "near threatened"; break;
	case 2: consLvL = "vulnerable"; break;
	case 3: consLvL = "endangered"; break;
	case 4: consLvL = "critically endangered"; break;
	case 5: consLvL = "extinct in the wild"; break;
	case 6: consLvL = "extinct"; break;
	default: consLvL = "unknown";
	}

	std::cout << "    is it predator (yes or no):";
	std::cin >> con;
	std::cin.ignore();

	isPredator = con == "yes";

	Fauna f(name, lifespan, habitats, consLvL, isPredator);
	return addOrganism(f);
}

bool RedBook::addFloraFromUserInput()
{
	StringC name, habitat, consLvL, con;
	int lifespan, consoleConsLvl, habNum;

	std::cout << "    name:";
	std::cin >> name;
	std::cout << "    lifespan:";
	std::cin >> lifespan;
	std::cout << "    habitats count:";
	std::cin >> habNum;
	std::cin.ignore();

	if (habNum <= 0)
	{
		std::cout << "Habitats have to be at least one." << std::endl;
		return false;
	}

	Vector<StringC> habitats;

	for (size_t i = 0; i < habNum; i++)
	{
		std::cout << "\t >";
		habitat.getline(std::cin);
		habitats.pushBack(habitat);
	}

	std::cout << "    conservation lvl (from 0 to 6):";
	std::cin >> consoleConsLvl;
	std::cin.ignore();

	switch (consoleConsLvl)
	{
	case 0: consLvL = "least concern"; break;
	case 1: consLvL = "near threatened"; break;
	case 2: consLvL = "vulnerable"; break;
	case 3: consLvL = "endangered"; break;
	case 4: consLvL = "critically endangered"; break;
	case 5: consLvL = "extinct in the wild"; break;
	case 6: consLvL = "extinct"; break;
	default: consLvL = "unknown";
	}

	Flora f(name, lifespan, habitats, consLvL);
	return addOrganism(f);
}

bool RedBook::addFungiFromUserInput()
{
	StringC name, habitat, consLvL, con;
	int lifespan, consoleConsLvl, habNum;
	bool isPoisonous;

	std::cout << "    name:";
	std::cin >> name;
	std::cout << "    lifespan:";
	std::cin >> lifespan;
	std::cout << "    habitats count:";
	std::cin >> habNum;
	std::cin.ignore();

	if (habNum <= 0)
	{
		std::cout << "Habitats have to be at least one." << std::endl;
		return false;
	}

	Vector<StringC> tempVec;

	for (size_t i = 0; i < habNum; i++)
	{
		std::cout << "\t >";
		habitat.getline(std::cin);
		tempVec.pushBack(habitat);
	}

	std::cout << "    conservation lvl (from 0 to 6):";
	std::cin >> consoleConsLvl;

	switch (consoleConsLvl)
	{
	case 0: consLvL = "least concern"; break;
	case 1: consLvL = "near threatened"; break;
	case 2: consLvL = "vulnerable"; break;
	case 3: consLvL = "endangered"; break;
	case 4: consLvL = "critically endangered"; break;
	case 5: consLvL = "extinct in the wild"; break;
	case 6: consLvL = "extinct"; break;
	default: consLvL = "unknown";
	}

	std::cout << "    is it poisonous (yes or no):";
	std::cin >> con;
	std::cin.ignore();

	isPoisonous = con == "yes";

	Fungi f(name, lifespan, tempVec, consLvL, isPoisonous);
	return addOrganism(f);
}