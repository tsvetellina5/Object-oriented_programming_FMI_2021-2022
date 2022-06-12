#include "ColdMeal.h"
#include <iostream>
//const double EPS = 1e-10; // Needed to accurately compare numbers of type float and double
ColdMeal::ColdMeal(const MyString& name, size_t preparationTime, const MyString& instructions, double storingTemperature, int id)
	: Recipe(name, preparationTime, instructions, id)
{
	setStoringTemperature(storingTemperature);
}

void ColdMeal::print() const
{
	Recipe::print();
	std::cout << "Storing temperature: " << storingTemperature << " degrees Celsius" << std::endl;
}

Recipe* ColdMeal::clone() const
{
	return new ColdMeal(*this);
}

void ColdMeal::setStoringTemperature(double storingTemperature)
{
	if (storingTemperature > -18 && storingTemperature < 4)
	{
		this->storingTemperature = storingTemperature;
		return;
	}
	this->storingTemperature = 3.99; // setting default refrigerator temperature value
}

const double ColdMeal::getStoringTemperature() const
{
	return storingTemperature;
}
