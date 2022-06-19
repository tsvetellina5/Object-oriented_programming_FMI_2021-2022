#include "src/hpp/Recipe.h"

const double SIZE_T_LIMIT = 1e3; 
// limit for size_t validation (when the user input is a negative number,
// it might transform into a large positive number, because its type is size_t (unsigned long long)...)
// we don't need numbers bigger than 1000 in our project anyway, that's why we put such boundary

Recipe::Recipe(const MyString& name, int ID, const IngredientList& ingredients, size_t preparationTime,
               const MyString& instructions, size_t kcal, const MyString& typeToConvert)
{
	setName(name);
	setIngredients(ingredients);
	setPreparationTime(preparationTime);
	setInstructions(instructions);
	setID(ID);
	setInitialRatingState();
	setKcal(kcal);
	setType(typeToConvert);
}

void Recipe::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Number: " << ID << std::endl;
	std::cout << "Type of meal: " << typeToString(type) << std::endl;
	std::cout << "Rating: " << averageRating << std::endl;
	std::cout << "Ingredients: " << std::endl;
	for (size_t i = 0; i < ingredients.getSize(); ++i)
		std::cout << "- " << ingredients[i].getFirst() << ", " << ingredients[i].getSecond() << std::endl;
	std::cout << "Energy value: " << kcal << " kcal" << std::endl;
	std::cout << "Preparation time: " << preparationTime << " minutes" << std::endl;
	std::cout << "Cooking instructions: " << std::endl;
	std::cout << instructions << std::endl;
}

void Recipe::setName(const MyString& name)
{//40 characters is the limit
	if (name.c_str() != nullptr && name.getSize() > 0 && name.getSize() < 40)
	{
		this->name = name;
		if (isLowerCase(this->name[0]))
			toUpperCase(this->name[0]);
		return;
	}
	throw std::invalid_argument("Invalid name!");
}

void Recipe::setIngredients(const IngredientList& ingredients)
{
	if (ingredients.getSize() > 0)
	{
		this->ingredients = ingredients;
		return;
	}
	throw std::invalid_argument("Unknown ingredients!");
}

void Recipe::setPreparationTime(size_t preparationTime)
{//preparation time limit is 180 minutes
	if (preparationTime < SIZE_T_LIMIT && preparationTime > 0 && preparationTime < 180)
	{
		this->preparationTime = preparationTime;
		return;
	}
	throw std::invalid_argument("Invalid preparation data!");
}

void Recipe::setInstructions(const MyString& instructions)
{
	if (instructions.c_str() != nullptr && instructions.getSize() > 0)
	{
		this->instructions = instructions;
		return;
	}
	throw std::invalid_argument("No instructions!");
}

void Recipe::setID(int ID)
{
	this->ID = ID;
}

void Recipe::setInitialRatingState()
{
	averageRating = 0;
}

void Recipe::setKcal(size_t kcal)
{
	if (kcal >= 400 && kcal <= 1200)
	{	
		this->kcal = kcal;
		return;
	}
	throw std::invalid_argument("Invalid energy value!");
}

void Recipe::setType(const MyString& typeToConvert)
{
	type = stringToType(typeToConvert);
}

void Recipe::addRating(unsigned short rating)
{
	if (rating > 5)
		return;

	ratings.push_back(rating);
	
	size_t count = 0;
	double sum = 0.0;
	while (count < ratings.getSize())
	{
		sum += ratings[count];
		++count;
	}

	averageRating = sum / count;
}

const MyString& Recipe::getName() const
{
	return name;
}

const IngredientList& Recipe::getIngredients() const
{
	return ingredients;
}

size_t Recipe::getPreparationTime() const
{
	return preparationTime;
}

const MyString& Recipe::getInstructions() const
{
	return instructions;
}

int Recipe::getID() const
{
	return ID;
}

double Recipe::getRating() const
{
	return averageRating;
}

const Type& Recipe::getType() const
{
	return type;
}

size_t Recipe::getKcal() const
{
	return kcal;
}

void inputIngredients(IngredientList& ingredients)
{
	// an "IngredientList" has to be created before calling this function, 
	// then it is going to be filled with information, and then the list can
	// be used as a parameter of the recipe constructors
	size_t num = 0;
	std::cout << "Please, type the number of ingredients: ";
	while (true)
	{
		std::cin >> num;
		if (num > 0 && num < 50) // 50 is the limit
			break;
		else
			std::cout << "Invalid number of products. Please try again..." << std::endl;
	}

	for (size_t i = 0; i < num; ++i)
	{
		std::cout << "Ingredient: ";
		std::cin.ignore();
		MyString product;
		std::cin >> product;
		std::cout << "Number of ingredients of this type: ";
		size_t number;
		std::cin >> number;
		std::cout << std::endl;
		Pair<MyString, size_t> temp(product, number);
		ingredients.push_back(temp);
	}
}

bool isLowerCase(char s) {
    return s >= 'a' && s <= 'z';
}
void toUpperCase(char& s) {
    s -= 32;
}
