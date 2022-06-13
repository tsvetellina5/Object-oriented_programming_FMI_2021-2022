#include "String.h"
#include <iostream>
#pragma once

class Food 
{
private:
	int calories;

protected:
	enum Type {
		PLANTS,
		SEAFOOD,
		MEAT
	} type;

public:
	Food(const int);
	virtual ~Food() {};

	int getCalories() const;
	const Type& getType() const;
	virtual const String* convertTypeToString() const = 0;
	virtual Food* clone() const = 0;
};
