#include "Hotel.h"
#include<iostream>
#pragma warning (disable : 4996)
using namespace std;

Hotel::Hotel() : name(), address()
{
	count = 0;
	capacity = 2;
	reservations = new Reservation * [capacity];
	allReservations = 0;
}

Visitor Hotel::getVisitor(size_t index) const
{
	return visitors[index];
}

bool Hotel::barStatus(size_t index) const
{
	return reservations[index]->goToBar();
}

bool Hotel::restaurantStatus(size_t index) const
{
	return reservations[index]->goToRestaurant();
}

void Hotel::payToBar(size_t index)
{
	reservations[index]->payForBar();
}

void Hotel::payToRestaurant(size_t index)
{
	reservations[index]->payForRestaurant();
}

void Hotel::addVisitor(const char* id, const String& name)
{
	if (visitors.getSize() < MAX_NUMBER_OF_VISITORS)
	{
		int index = 0;
		int number = 0;
		while (id[index] != '\0')
		{
			number *= 10;
			number += (id[index++] - '0');
		}
		Visitor temp(id, name);
		visitors.pushBack(temp);
	}
	else
		cout << "Hotel is full" << endl;
}

void Hotel::free()
{
	for (size_t i = 0; i < count; i++)
		delete reservations[i];
	delete[] reservations;
}

void Hotel::copyFrom(const Hotel& other)
{
	reservations = new Reservation * [other.capacity];
	count = other.count;
	capacity = other.capacity;

	for (size_t i = 0; i < count; i++)
		reservations[i] = other.reservations[i]->clone();
}

void Hotel::resize()
{
	Reservation** newCollection = new Reservation * [capacity *= 2];
	for (size_t i = 0; i < count; i++)
		newCollection[i] = reservations[i];
	delete[] reservations;
	reservations = newCollection;
}

Hotel::Hotel(const Hotel& other)
{
	copyFrom(other);
}

Hotel& Hotel::operator=(const Hotel& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Hotel::~Hotel()
{
	free();
}

void Hotel::deleteVisitor(const char* id)
{
	String temp(id);
	for (size_t i = 0; i < visitors.getSize(); i++)
	{
		if (temp.compare(visitors[i].getID()))
		{
			visitors.popAt(i);
			break;
		}
	}
}

void Hotel::addReservation(const char* id, /*const String&*/const Reservation::Type& type, size_t days, size_t room, size_t beds)
{
	allReservations++;
	int index = 0;
	int number = 0;
	while (id[index] != '\0')
	{
		number *= 10;
		number += (id[index++] - '0');
	}

	size_t current = 0;
	for (int i = 0; i < visitors.getSize(); i++)
	{
		if (number == visitors[i].getID())
		{
			current = i;
			break;
		}
	}

	if (count == capacity)
		resize();

	if (/*type.compare("AI")*/type==Reservation::Type::AI)
	{
		AI a(type, days, room, beds, id);

		reservations[count++] = a.clone();
		cout << "All inclusive reservation successfully added!" << endl;
	}

	if (/*type.compare("UAI")*/type == Reservation::Type::UAI)
	{
		UAI b(type, days, room, beds, id);

		reservations[count++] = b.clone();
		cout << "Ultra all inclusive reservation successfully added!" << endl;
	}

	if (/*type.compare("NO")*/type == Reservation::Type::NO)
	{
		NO c(type, days, room, beds, id);

		reservations[count++] = c.clone();
		cout << "Nights only reservation successfully added!" << endl;
	}
}

bool Hotel::deleteReservation(size_t index)
{
	size_t t = count;
	if (index > t - 1)
	{
		std::cout << "There is no reservation number " << index << "!" << std::endl;
		return false;
	}

	delete reservations[index];
	for (size_t i = index; i < count - 1; i++)
	{
		reservations[i] = reservations[i + 1];
	}
	count--;
	std::cout << "Erased (" << index << ")" << std::endl;
	return true;

}

void Hotel::listVisitors() const
{
	for (int i = 0; i < visitors.getSize(); i++)
	{
		cout << "Name: " << visitors[i].getName() << " ID: " << visitors[i].getID() << endl;
	}
	cout << endl;
}

void Hotel::listReservations() const
{
	for (size_t i = 0; i < count; i++)
		reservations[i]->display();
}

void Hotel::listVisitorReservation(const char* id) const
{
	String temp(id);
	cout << "reservations: " << endl;
	int current = 0;
	for (int i = 0; i < count; i++)
	{
		if (reservations[i]->getID().compare(temp))
		{
			reservations[i]->display();
		}
	}
	std::cout << std::endl;
}

Hotel::Hotel(const String& name, const String& address)
{
	this->name = name;
	this->address = address;
}

void Hotel::display() const
{
	cout << "Name: " << name << endl << "Address: " << address << endl << "Number of visitors: " << visitors.getSize() << endl;
	cout << endl;
}

void Hotel::exportVisitors(const char* file) {
	ofstream output(file);

	for (int i = 0; i < visitors.getSize(); i++)
		output << "Name: " << visitors[i].getName() << " ID: " << visitors[i].getID() << endl;
	for (int i = 0; i < count; i++)
	{
		String temp(reservations[i]->getID());
		output << "ID of reservation: " << temp.c_str() << " Type: " << reservations[i]->getType() << " Days: " << reservations[i]->getDays() << " Room: " << reservations[i]->getRoomNumber() << endl;
	}
	output.close();
}