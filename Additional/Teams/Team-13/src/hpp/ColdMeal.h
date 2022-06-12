#ifndef COLDMEAL_H
#define COLDMEAL_H

#include "Recipe.h"

class ColdMeal : public Recipe
{
private:
	double storingTemperature; // supposed to belong to the interval (-18 ; 4)
public:
	ColdMeal(const MyString& name, const int& ID, const IngredientList& ingredients, const size_t& preparationTime, const MyString& instructions, const size_t& kcal, const MyString typeToConvert, const double& storingTemperature);
	void print() const override;
	Recipe* clone() const override;
	void determineDifficulty() override;

	void setStoringTemperature(const double& storingTemperature);
	const double getStoringTemperature() const;
};

#endif