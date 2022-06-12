#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H
#include "Recipe.h"

void swap(Recipe* lhs, Recipe* rhs);

class RecipeBook {
    Vector<Recipe*> recipes;

    void copyFrom(const RecipeBook& other);
    void free();
    void addRecipe(Recipe* recipe);
    int findAtId(int id) const;

public:
    RecipeBook(const RecipeBook& other);
    RecipeBook& operator=(const RecipeBook& other);
    ~RecipeBook();

    int generateID() const;

    void addHotMeal(const MyString& name, size_t preparationTime, const MyString& instructions, size_t cookingTemperature, size_t cookingTime);
    void addColdMeal(const MyString& name, size_t preparationTime, const MyString& instructions, double storingTemperature);

    bool removeRecipe(int id);
    bool addRating(int rating, int id);

};

#endif //RECIPEBOOK_H
