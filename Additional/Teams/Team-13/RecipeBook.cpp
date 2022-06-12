#include "RecipeBook.h"
#include "HotMeal.h"
#include "ColdMeal.h"

void RecipeBook::copyFrom(const RecipeBook& other) {
    size_t size = other.recipes.getSize();
    for (size_t i = 0; i < size; ++i) {
        recipes.push_back(other.recipes[i]->clone());
    }
}

void RecipeBook::free() {
    size_t size = recipes.getSize();
    for (size_t i = 0; i < size; ++i) {
        delete recipes[i];
    }
}

void swap(Recipe* lhs, Recipe* rhs) {
    Recipe* temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void RecipeBook::addRecipe(Recipe* recipe){
    recipes.push_back(recipe);
    size_t i = recipes.getSize() - 1;
    while (recipes[i]->getRating() > recipes[i-1]->getRating()) {
        swap(recipes[i], recipes[i-1]);
        --i;
    }

}
int RecipeBook::findAtId(int id) const {
    size_t size = recipes.getSize();
    for (size_t i = 0; i < size; ++i) {
        if (recipes[i]->getID() == id)
            return i;
    }
    return -1;
}

RecipeBook::RecipeBook(const RecipeBook& other){
    copyFrom(other);
}
RecipeBook& RecipeBook::operator=(const RecipeBook& other){
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
RecipeBook::~RecipeBook(){
    free();
}

int RecipeBook::generateID() const
{
    int id = 0;
    do {
        srand(time(NULL));
        id = (rand() % 9999) + 1;
    } while (findAtId(id) != -1);

    return id;
}

void RecipeBook::addHotMeal(const MyString& name, size_t preparationTime, const MyString& instructions, size_t cookingTemperature, size_t cookingTime){
    int id = generateID();
    Recipe* newRecipe = new HotMeal(name, preparationTime, instructions, cookingTemperature, cookingTime, id);
    addRecipe(newRecipe);
}
void RecipeBook::addColdMeal(const MyString& name, size_t preparationTime, const MyString& instructions, double storingTemperature){
    int id = generateID();
    Recipe* newRecipe = new ColdMeal(name, preparationTime, instructions, storingTemperature, id);
    addRecipe(newRecipe);
}

bool RecipeBook::removeRecipe(int id){
    int index = findAtId(id);
    if (index == -1)
        return false;

    recipes.deleteAt(index);
    return true;
}

bool RecipeBook::addRating(int rating, int id) {
    int index = findAtId(id);
    if (index == -1)
        return false;

    recipes[index]->addRating(rating);
    return true;
}

