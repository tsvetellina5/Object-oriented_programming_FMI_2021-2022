#include "src/hpp/RecipeBook.h"
#include "src/hpp/HotMeal.h"
#include "src/hpp/ColdMeal.h"

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

void RecipeBook::addHotMeal(const MyString& name, const IngredientList& ingredients, const size_t& preparationTime,
                            const MyString& instructions, const size_t& kcal, const MyString& typeToConvert,
                            const size_t& cookingTemperature, const size_t& cookingTime, const Vector<MyString>& appliances){
    int ID = generateID();
    Recipe* newRecipe = new HotMeal(name, ID, ingredients, preparationTime, instructions,
                                    kcal, typeToConvert, cookingTemperature, cookingTime, appliances);
    addRecipe(newRecipe);
}
void RecipeBook::addColdMeal(const MyString& name, const IngredientList& ingredients, const size_t& preparationTime,
                             const MyString& instructions, const size_t& kcal, const MyString& typeToConvert, const double& storingTemperature){
    int ID = generateID();
    Recipe* newRecipe = new ColdMeal(name, ID, ingredients, preparationTime, instructions, kcal, typeToConvert, storingTemperature);
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

void RecipeBook::printType(const Type& type) const {
    size_t size = recipes.getSize();
    for (int i = 0; i < size; ++i) {
        if (recipes[i]->getType() == type)
            recipes[i]->print();
    }
}

void RecipeBook::printAll() const {
    size_t size = recipes.getSize();
    for (int i = 0; i < size; ++i)
        recipes[i]->print();
}

void RecipeBook::printAllSoups() const {
    printType(Type::soup);
}
void RecipeBook::printAllSalads() const{
    printType(Type::salad);
}

void RecipeBook::printAllPastry() const {
    printType(Type::pastry);
}
void RecipeBook::printAllStew() const {
    printType(Type::stew);
}

void RecipeBook::printAllSteak() const {
    printType(Type::steak);
}
void RecipeBook::printAllSandwiches() const {
    printType(Type::sandwich);
}
void RecipeBook::printAllDesserts() const{
    printType(Type::dessert);
}

void RecipeBook::printDifficulty(unsigned short difficulty) const {
    size_t size = recipes.getSize();
    for (int i = 0; i < size; ++i) {
        if (recipes[i]->getDifficulty() == difficulty)
            recipes[i]->print();
    }
}