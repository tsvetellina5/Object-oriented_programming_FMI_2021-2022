#pragma once
#include "Component.h"
#include<cstring>

Component::Component()
{
	manufacturer = nullptr;

	model = nullptr;

	price = 0.0;
}

Component::Component(const char* manufacturer, const char* model, const double price, ComponentType componentType)
{
	this->price = price;

	this->manufacturer = new char[strlen(manufacturer) + 1];
	strcpy(this->manufacturer, manufacturer);

	this->model = new char[strlen(model) + 1];
	strcpy(this->model, model);

	this->componentType = componentType;

}

Component::Component(const Component& other)
{
	copy(other);
}

Component& Component::operator=(const Component& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Component::~Component()
{
	free();
}

double Component::getPrice() const
{
	return price;
}

void Component::setPrice(const double price)
{
	this->price = price;
}

ComponentType Component::getComponentType() const
{
	return componentType;
}

void Component::copy(const Component& other)
{
	this->price = other.price;

	this->manufacturer = new char[strlen(other.manufacturer) + 1];
	strcpy(this->manufacturer, other.manufacturer);

	this->model = new char[strlen(other.model) + 1];
	strcpy(this->model, other.model);
	
	componentType = other.componentType;
}

void Component::free()
{
	delete[] manufacturer;
	delete[] model;
}
