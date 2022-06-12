#ifndef RECIPE_H
#define RECIPE_H

#include <time.h>
#include "String.h"
#include "Vector.hpp"
#include "Pair.hpp"
#include "Type.h"

typedef Vector<Pair<MyString, size_t>> IngredientList;

class Recipe
{
private:
	MyString name;
	IngredientList ingredients;
	size_t preparationTime;
	MyString instructions;
	Vector<unsigned short> ratings;
	double averageRating;
	int ID;

	Type type;
	size_t difficulty;
	size_t kcal;

public:

	Recipe(const MyString& name, const int& ID, const IngredientList& ingredients, const size_t& preparationTime, const MyString& instructions, const size_t& kcal, const MyString typeToConvert);
	virtual ~Recipe() = default;
	virtual void print() const;
	virtual Recipe* clone() const = 0;
	virtual void determineDifficulty() = 0;

	void setName(const MyString& name);
	void setIngredients(const IngredientList& ingredients);
	void setPreparationTime(const size_t& time);
	void setInstructions(const MyString& instructions);
	void setID(const int& ID);
	void setInitialRatingState();
	void setInitialDifficultyState();
	void setKcal(const size_t& kcal);
	void setType(const MyString& typeToConvert);
	void setDifficulty(const size_t& difficulty);

	void addRating(const unsigned short& rating); // not supposed to be used in the initialization

	const MyString getName() const;
	const IngredientList getIngredients() const;
	const size_t getPreparationTime() const;
	const MyString getInstructions() const;
	const int getID() const;
	const double getRating() const;
	const Type getType() const;
	const size_t getKcal() const;
	const size_t getDifficulty() const;

};
	void inputIngredients(IngredientList& ingredients); // !! A function to take user input for the ingredients list
	// to be used inside the menu

#endif