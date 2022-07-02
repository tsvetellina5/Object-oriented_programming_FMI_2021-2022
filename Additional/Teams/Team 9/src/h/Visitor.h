#pragma once
#include "String.h"
#include "Reservation.h"

class Visitor
{
private:
	String id;
	String name;

public:
	Visitor();
	Visitor(const String& id, const String& name);

	void setID(const String& id);
	void setName(const String& name);

	const String& getID() const;
	const String& getName() const;
};