#ifndef COLDMEAL_H
#define COLDMEAL_H

#include "Recipe.h"

class ColdMeal : public Recipe
{
private:
    double storingTemperature;
     // supposed to belong to the interval (-18 ; 4)
public:
	ColdMeal(const MyString& name, int ID, const IngredientList& ingredients, size_t preparationTime,
             const MyString& instructions, size_t kcal, const MyString& typeToConvert, double storingTemperature);
	void print() const override;
	Recipe* clone() const override;
	unsigned short getDifficulty() const override;

	void setStoringTemperature(double storingTemperature);
    double getStoringTemperature() const;
};

#endif