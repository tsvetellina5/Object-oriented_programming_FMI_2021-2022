#pragma once
#include "Visitor.h"
#include "Reservation.h"
#include "NO.h"
#include "AI.h"
#include "UAI.h"
const int MAX_NUMBER_OF_VISITORS = 200;

class Hotel
{

private:
	Reservation** reservations;
	size_t count;
	size_t capacity;

	void free();
	void copyFrom(const Hotel& other);
	void resize();

public:
	Hotel();
	Hotel(const String& name, const String& address);
	Hotel(const Hotel& other);
	Hotel& operator=(const Hotel& other);
	~Hotel();

private:
	String name;
	String address;
	Visitor visitors[MAX_NUMBER_OF_VISITORS];

	size_t logCounter;
	size_t lastVisitor;
	size_t allReservations;

public:
	size_t getLastVisitor() const;
	size_t getLogCounter()const;
	Visitor getVisitor(size_t index) const;

	void payToBar(size_t index);
	void payToRestaurant(size_t index);

	bool barStatus(size_t index) const;
	bool restaurantStatus(size_t index)const;

	void addVisitor(const char* id, const String& name);
	void deleteVisitor(const char* id);
	void addReservation(const char* id, const String& type, size_t days, size_t room, size_t beds);
	bool deleteReservation(size_t index);

	void listVisitors() const;
	void listReservations() const;
	void listVisitorReservation(const char* id) const;

	void exportVisitors(const char* file);               //saves visitors to file

	void display() const;
};