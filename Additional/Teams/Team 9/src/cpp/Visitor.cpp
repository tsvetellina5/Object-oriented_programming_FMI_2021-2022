#include "Visitor.h"
#include <cstring>
#pragma warning (disable : 4996)

Visitor::Visitor() {}

Visitor::Visitor(const String& id, const String& name)
{
	this->id = id;
	this->name = name;
}

void Visitor::setID(const String& id)
{
	this->id = id;
}

void Visitor::setName(const String& name)
{
	this->name = name;
}

const String& Visitor::getID() const
{
	return id;
}

const String& Visitor::getName() const
{
	return name;
}

