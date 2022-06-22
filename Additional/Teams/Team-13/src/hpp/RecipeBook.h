#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H
#include "src/hpp/Recipe.h"

void swap(Recipe* lhs, Recipe* rhs);

class RecipeBook {
    Vector<Recipe*> recipes;

    void copyFrom(const RecipeBook& other);
    void free();
    void addRecipe(Recipe* recipe);
    int findAtId(int id) const;
    void printType(const Type& type) const;


public:
    RecipeBook() = default;
    RecipeBook(const RecipeBook& other);
    RecipeBook& operator=(const RecipeBook& other);
    ~RecipeBook();

    int generateID() const;

    void addHotMeal(const MyString& name, const IngredientList& ingredients, const size_t& preparationTime,
                    const MyString& instructions, const size_t& kcal, const MyString& typeToConvert,
                    const size_t& cookingTemperature, const size_t& cookingTime, const Vector<MyString>& appliances);
    void addColdMeal(const MyString& name, const IngredientList& ingredients, const size_t& preparationTime,
                     const MyString& instructions, const size_t& kcal, const MyString& typeToConvert, const double& storingTemperature);

    bool removeRecipe(int id);
    bool addRating(int rating, int id);

    void printAllSoups() const;
    void printAllSalads() const;
    void printAllPastry() const;
    void printAllStew() const;
    void printAllSteak() const;
    void printAllSandwiches() const;
    void printAllDesserts() const;
    void printAll() const;

    void printDifficulty(unsigned short difficulty) const;

};

#endif //RECIPEBOOK_H
