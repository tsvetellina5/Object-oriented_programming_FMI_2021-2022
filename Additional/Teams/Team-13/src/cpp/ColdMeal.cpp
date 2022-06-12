#include "src/hpp/ColdMeal.h"
#include <iostream>

ColdMeal::ColdMeal(const MyString& name, const int& ID, const IngredientList& ingredients,const size_t& preparationTime,
                   const MyString& instructions, const size_t& kcal, const MyString& typeToConvert, const double& storingTemperature)
	: Recipe(name, ID, ingredients, preparationTime, instructions, kcal, typeToConvert)
{
	setStoringTemperature(storingTemperature);
	determineDifficulty();
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

void ColdMeal::determineDifficulty() // max difficulty of cold meal recipes is 3
{
	if (getPreparationTime() > 100)
		setDifficulty(3);
	else if (getPreparationTime() <= 100 && getPreparationTime() > 20)
		setDifficulty(2);
	else
		setDifficulty(1);
}

void ColdMeal::setStoringTemperature(const double& storingTemperature)
{
	if (storingTemperature > -18 && storingTemperature < 4)
	{
		this->storingTemperature = storingTemperature;
		return;
	}
	throw "Invalid storing temperature!";
}

const double ColdMeal::getStoringTemperature() const
{
	return storingTemperature;
}
