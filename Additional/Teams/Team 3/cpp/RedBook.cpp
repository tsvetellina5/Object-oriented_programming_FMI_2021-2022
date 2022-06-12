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

/*void RedBook::printSpecific(char* type) const {
	for (size_t i = 0; i < size; i++) {
		if (list[i] != nullptr) {
			{
				if (strcmp(type, "Animals") == 0) {
					if (strcmp(list[i]->typeToStr(), "Animal") == 0)
					{
						Animal* organism = (Animal*)list[i];
						list[i]->print();
					}
				}
				if (strcmp(type, "Plats") == 0) {
					if (strcmp(list[i]->typeToStr(), "Plants") == 0)
					{
						Plant* organism = (Plant*)list[i];
						list[i]->print();
					}
				}
				if (strcmp(type, "Fungi") == 0) {
					if (strcmp(list[i]->typeToStr(), "Fungi") == 0)
					{
						Fungi* organism = (Fungi*)list[i];
						list[i]->print();
					}
				}
			}
		}
	}
	*/

void RedBook::printConservationLevel(size_t level) const {
	for (size_t i = 0; i < size; i++) {
		if (list[i]->getConservationLevel() == level) {
			list[i]->print();
		}
	}
}

void RedBook::printFauna() const {
	for (int i = 0; i < size; i++)
	{
		Fauna* tmp = dynamic_cast<Fauna*>(list[i]);

		if (tmp == nullptr)
		{
			delete tmp;
			continue;
		}

		tmp->print();
		delete tmp;
	}
}

void RedBook::printFlora() const {
	for (int i = 0; i < size; i++)
	{
		Flora* tmp = dynamic_cast<Flora*>(list[i]);

		if (tmp == nullptr)
		{
			delete tmp;
			continue;
		}

		tmp->print();
		delete tmp;
	}
}

void RedBook::printFungi() const {
	for (int i = 0; i < size; i++)
	{
		Fungi* tmp = dynamic_cast<Fungi*>(list[i]);

		if (tmp == nullptr)
		{
			delete tmp;
			continue;
		}

		tmp->print();
		delete tmp;
	}
}

bool RedBook::setConservationLevelByIndex(int index, const StringC& level)
{
	if (index < 0 || index >= size)
		return false;

	if (list[index]->getConservationLevelStr() == "extinct")
		return false;

	return list[index]->setConservationLevel(level);
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