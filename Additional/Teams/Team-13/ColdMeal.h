#ifndef COLDMEAL_H
#define COLDMEAL_H

#include "Recipe.h"

class ColdMeal : public Recipe
{
private:
	double storingTemperature; // supposed to belong to the interval (-18 ; 4)
public:
	ColdMeal(const MyString& name, size_t preparationTime, const MyString& instructions, double storingTemperature, int id);
	void print() const override;
	Recipe* clone() const override;

	void setStoringTemperature(double storingTemperature);
	const double getStoringTemperature() const;
};

#endif