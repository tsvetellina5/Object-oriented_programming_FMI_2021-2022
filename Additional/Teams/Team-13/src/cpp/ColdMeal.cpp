#include "src/hpp/ColdMeal.h"
#include <iostream>

ColdMeal::ColdMeal(const MyString& name, int ID, const IngredientList& ingredients,
                   size_t preparationTime, const MyString& instructions, size_t kcal,
                   const MyString& typeToConvert, double storingTemperature)
	: Recipe(name, ID, ingredients, preparationTime, instructions, kcal, typeToConvert)
{
	setStoringTemperature(storingTemperature);
}

void ColdMeal::print() const
{
	Recipe::print();
    unsigned short difficulty = getDifficulty();
    std::cout << "Difficulty: ";
    for (size_t i = 0; i < difficulty; ++i)
        std::cout << "* ";
    std::cout << std::endl;
	std::cout << "Storing temperature: " << storingTemperature << " degrees Celsius" << std::endl;
}

Recipe* ColdMeal::clone() const
{
	return new ColdMeal(*this);
}

unsigned short ColdMeal::getDifficulty() const // max difficulty of cold meal recipes is 3
{
	if (getPreparationTime() > 100)
        return 3;
	else if (getPreparationTime() <= 100 && getPreparationTime() > 20)
        return 2;
	else
        return 1;
}

void ColdMeal::setStoringTemperature(double storingTemperature)
{
	if (storingTemperature > -18 && storingTemperature < 4)
	{
		this->storingTemperature = storingTemperature;
		return;
	}
	throw std::invalid_argument("Invalid storing temperature!");
}

double ColdMeal::getStoringTemperature() const
{
	return storingTemperature;
}
