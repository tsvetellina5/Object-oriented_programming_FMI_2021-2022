#include "Food.h"

Food::Food(const int calories) 
{
	this->calories = calories;
}

int Food::getCalories() const {

	return this->calories;
}

const Food::Type& Food::getType() const
{
	return type;
}


