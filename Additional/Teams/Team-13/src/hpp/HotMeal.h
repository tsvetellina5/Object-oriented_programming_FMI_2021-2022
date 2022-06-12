#ifndef HOTMEAL_H
#define HOTMEAL_H
#include "src/hpp/Recipe.h"

class HotMeal : public Recipe
{
private:
	size_t cookingTemperature; // ranging from 90 to 260 Celsius
	size_t cookingTime;// time necessary for the meal to be cooked (boiled, fried, baked, roasted, etc.)
	Vector<MyString> appliances; // list of necessary appliances in order to execute the recipe (stove, oven, mixer, etc.)
public:
	HotMeal(const MyString& name, const int& ID, const IngredientList& ingredients, const size_t& preparationTime,
            const MyString& instructions, const size_t& kcal, const MyString& typeToConvert,
            const size_t& cookingTemperature, const size_t& cookingTime, const Vector<MyString>& appliances);
	void print() const override;
	Recipe* clone() const override;
	void determineDifficulty() override;

	void setCookingTemperature(const size_t& cookingTemperature);
	void setCookingTime(size_t cookingTime);
	void setAppliances(const Vector<MyString>& appliances);

	size_t getCookingTemperature() const;
	size_t getCookingTime() const;
	const Vector<MyString>& getAppliances() const;

};
	void inputAppliances(Vector<MyString>& appliances); // !! A function to take user input for appliances list

#endif
