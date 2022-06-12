#include "src/hpp/HotMeal.h"
#include <iostream>
const double SIZE_T_LIMIT = 1e3;
HotMeal::HotMeal(const MyString& name, const int& ID, const IngredientList& ingredients, const size_t& preparationTime, const MyString& instructions, const size_t& kcal, const MyString typeToConvert, const size_t& cookingTemperature, const size_t& cookingTime, const Vector<MyString>& appliances)
	: Recipe(name, ID, ingredients, preparationTime, instructions, kcal, typeToConvert)
{
	setCookingTemperature(cookingTemperature);
	setCookingTime(cookingTime);
	setAppliances(appliances);
	determineDifficulty();
}

void HotMeal::print() const
{
	Recipe::print();
	std::cout << "Cooking time: " << cookingTime << " minutes" << std::endl;
	std::cout << "Cooking temperature: " << cookingTemperature << " degrees Celsius" << std::endl;
	std::cout << "Necessary appliances: " << std::endl;
	for (size_t i = 0; i < appliances.getSize(); ++i)
		std::cout << "- " << appliances[i] << std::endl;
}

Recipe* HotMeal::clone() const
{
	return new HotMeal(*this);
}

void HotMeal::determineDifficulty() //cannot be less than 2, because preparation includes cooking in any case
{
	if (cookingTime >= 0.75 * getPreparationTime() && getPreparationTime() > 90)
		setDifficulty(5);
	else if (cookingTime >= 0.75 * getPreparationTime() && getPreparationTime() > 60)
		setDifficulty(4);
	else if (cookingTime >= 0.5 * getPreparationTime() && getPreparationTime() > 30)
		setDifficulty(3);
	else
		setDifficulty(2);
}

void HotMeal::setCookingTemperature(const size_t& cookingTemperature)
{
	if (cookingTemperature >= 90 && cookingTemperature <= 260)
	{
		this->cookingTemperature = cookingTemperature;
		return;
	}
	throw std::invalid_argument("Invalid cooking temperature!");
}

void HotMeal::setCookingTime(const size_t& cookingTime)
{
	if (cookingTime < SIZE_T_LIMIT)
	{
		if (cookingTime >= getPreparationTime())
		{
			throw std::invalid_argument("Invalid cooking time!");
		}
		this->cookingTime = cookingTime;
		return;
	}	
	throw std::invalid_argument("Invalid cooking time!");
}

void HotMeal::setAppliances(const Vector<MyString> appliances)
{
	if (appliances.getSize() > 0 && appliances.getSize() < SIZE_T_LIMIT)
	{
		this->appliances = appliances;
		return;
	}
	throw std::invalid_argument("No appliances!");
}

const size_t HotMeal::getCookingTemperature() const
{
	return cookingTemperature;
}

const size_t HotMeal::getCookingTime() const
{
	return cookingTime;
}

const Vector<MyString> HotMeal::getAppliances() const
{
	return appliances;
}

void inputAppliances(Vector<MyString>& appliances)
{
	// an "IngredientList" has to be created before calling this function, 
	// then it is going to be filled with information, and then the list can
	// be used as a parameter of the recipe constructors
	size_t num = 0;
	std::cout << "Please, type the number of appliances: ";
	while (true)
	{
		std::cin >> num;
		if (num > 0 && num < 10) // 10 is the limit
			break;
		else
			std::cout << "Invalid number of appliances. Please try again..." << std::endl;
	}

	bool hasTyped = false;
	for (size_t i = 0; i < num; ++i)
	{
		std::cout << "Appliance: ";
		MyString temp;
		if (!hasTyped)
			std::cin.ignore();
		std::cin >> temp;
		hasTyped = true;
		appliances.push_back(temp);
	}
}