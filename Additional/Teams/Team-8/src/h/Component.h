#pragma once
#include "Enums.h"
#include<fstream>
#include<iostream>
#pragma warning(disable : 4996)
class Component {
protected:
	ComponentType componentType;
	char* manufacturer;
	char* model;
	double price;
public:

	Component();
	Component(const char*, const char*, const double, const ComponentType);
	Component(const Component&);
	Component& operator=(const Component&);
	virtual ~Component();

	double getPrice() const;
	void setPrice(const double);

	virtual void showComponentInfo() const = 0;
	virtual ComponentType getComponentType() const;
	virtual void saveToFile(std::ofstream&) const = 0;

	virtual Component* clone() const = 0;

private:
	void copy(const Component&);
	void free();
};