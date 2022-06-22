#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
#include"String.h"
#include"src/hpp/RecipeBook.h"
#include "src/hpp/HotMeal.h"
#include "src/hpp/ColdMeal.h"

#pragma warning(disable:4996)
using namespace std;

RecipeBook recipebook;

const int maxCharacters = 1024;
const int minPassLength = 8;
const int minUserLength = 5;
MyString sampleUser = "SAMPLEUSER";
MyString samplePass = "SAMPLEPASS";
void commander(MyString& user, MyString& pass);
void menu(MyString& user, MyString& pass);

bool compare(const MyString& a, const MyString& b) {
	if (a == b) {
		return true;
	}
	return false;
}

/*int stringToNum(char* str)
{
	int number = 0;
	if (str[0] >= '0' && str[0] <= '9') {
		number = str[0] - '0';
	}
	else if (str[0] == '1' && str[1] == '0') {
		number = 10;
	}
	return number;
}*/


void setAccount(MyString& user, MyString& pass) {
	ofstream saveAcc("accounts.txt", ios::app);
	if (!saveAcc.is_open()) {
		cout << "Error while opening the file..." << endl;
		return;
	}
	saveAcc << user << ":" << pass << endl;
	saveAcc.close();
}

bool checkExistingUser(MyString& user) {
	MyString cutUsername;
	ifstream checkAcc("accounts.txt");
	char buffer[maxCharacters];
	checkAcc.seekg(0, std::ios::end);
	size_t countSymbols = checkAcc.tellg();
	checkAcc.seekg(0, std::ios::beg);
	if (!checkAcc.is_open() || countSymbols <= 1) {
		//cout << "Error while opening the file..." << endl;
		return false;
	}
	while (!checkAcc.eof()) {
		cutUsername = "";
		checkAcc.getline(buffer, maxCharacters);
		for (int i = 0; buffer[i] != ':'; i++) {
			char temp[2];
			temp[0] = buffer[i];
			temp[1] = '\0';
			cutUsername += temp;
		}
		for (int i = 0; i < user.getSize() + 1; i++) {
			if (cutUsername[i] == user[i]) {
				if (i + 1 == (user.getSize())) {

					return true;
					//break;
				}
			}
			else {
				break;
			}
		}
	}
	checkAcc.close();
	return false;
}


bool checkPassword(MyString& user, MyString& passWord) {
	bool flag = false;
	const int lnUser = user.getSize();
	const int lnPass = passWord.getSize();
	MyString cutUsername;
	MyString cutPass;
	ifstream checkAcc("accounts.txt");
	checkAcc.seekg(0, std::ios::end);
	size_t countSymbols = checkAcc.tellg();
	checkAcc.seekg(0, std::ios::beg);
	char buffer[maxCharacters];
	if (!checkAcc.is_open()) {
		cout << "Error while opening the file..." << endl;
		//return -1;
	}
	while (!checkAcc.eof()) {
		checkAcc.getline(buffer, maxCharacters);
		cutUsername = "";
		cutPass = "";
		for (int i = 0; buffer[i] != ':'; i++) {
			char temp[2];
			temp[0] = buffer[i];
			temp[1] = '\0';
			cutUsername += temp;
		}
		for (int i = 0; i < lnUser; i++) {
			if (cutUsername[i] == user[i]) {
				if (cutUsername[i] == user[lnUser - 1]) {
					for (int i = 0; i < strlen(buffer); i++) {
						char temp[2];
						temp[0] = buffer[i + lnUser + 1];
						temp[1] = '\0';
						cutPass += temp;
						//cutPass[i] = buffer[i + lnUser + 1];

						if (i == lnPass - 1) {
							break;
						}


					}
					if ((strlen(buffer) - cutPass.getSize() - 1) != cutUsername.getSize()) {
						flag = true;
						break;
					}
					flag = false;

					for (int j = 0; j < lnPass; j++) {
						if (cutPass[j] == passWord[j]) {
							if (cutPass[j] == passWord[lnPass - 1]) {
								return true;
							}

						}
						else {
							break;
						}
					}

				}
			}
			else {
				break;
			}
		}
	}
	if (flag == true) {
		return false;
	}

	checkAcc.close();
	return false;

}

void SignUp(MyString& username, MyString& password) {
	cout << "Choose a username: ";
	// cin.ignore();
	MyString userName;
	cin >> userName;
	cout << "Choose a password: ";
	// cin.ignore();
	MyString pass;
	cin >> pass;
	username = userName;
	password = pass;
	if (checkExistingUser(username)) {
		cout << "Username already exists! Please, choose another." << endl;
		SignUp(userName, pass);
		return;
	}
	if (pass.getSize() < minPassLength) {
		cout << "Password must be at least 8 symbols long! Please, choose another." << endl;
		SignUp(userName, pass);
		return;
	}
	if (username.getSize() < minUserLength) {
		cout << "Username must be at least 5 symbols long! Please, choose another." << endl;
		SignUp(userName, pass);
		return;
	}
	setAccount(username, password);
	cout << "All done! Now please log into your account." << endl;
}

void GreetText() {
	MyString agree;
	cout << "Nothing to eat at home? Huh?" << endl;
	cout << "Want to be saved from starvation? You've come to the right place!" << endl;
	cout << "Would you like to start browsing recipes?" << endl;
	cout << ">";
	cin >> agree;
	if (compare(agree, "yes") || compare(agree, "Yes")) {
		cout << "Great! On you go! " << endl;
	}
	else if (compare(agree, "no") || compare(agree, "No")) {
		cout << "Ok, please don't die of famine!" << endl;
	}
	else {
		cout << "Not a valid command. Try again." << endl;
		GreetText();
		return;
	}

}
void logIn() {
	MyString userName;
	MyString pass;
	cout << "Please enter your username: ";
	cin >> userName;

	if (!(checkExistingUser(userName))) {
		cout << "Username doesn't  exist! Please, choose another or create a new one." << endl;
		commander(userName, pass);
		return;
	}
	cout << "Please enter your password: ";
	cin >> pass;
	if (checkPassword(userName, pass)) {
		cout << "Welcome, " << userName << "!" << endl;
		menu(userName, pass);
	}
	else {
		cout << "Incorrect password. Please try again." << endl;
		commander(userName, pass);
		return;
	}

}

void addRecipe() {
	cout << "Here you can add your own recipe to the book!" << endl;
	cout << "Are you going to write a recipe for a cold meal or for a hot meal?" << endl;
	cout << "NOTE: type cold/hot" << endl;
	//IngredientList ingredients;
	//Vector<MyString> appliencies;
	MyString command;
	MyString name;
	size_t preperationTime;
	MyString instructions;
	size_t calories;
	size_t cookingTemperature;
	size_t cookingTime;
	MyString type;
	double storingTemperature;
	cin >> command;
	if (compare(command, "hot")) {
		cout << "Let's get started then!" << endl;
		cout << "Name your invention: ";
		cin >> name;
		cout << "List of all the ingredients: ";
		IngredientList ingredients;
		inputIngredients(ingredients);
		cout << "Preparation time(in minutes): ";
		cin >> preperationTime;
		cout << "Instructions on how to prepare: ";
		cin.ignore();
		cin >> instructions;
		cout << "Overall calories per meal: ";
		cin >> calories;
		cout << "Choose a type: ";
		cout << "Choose between: soup, salad, pastry, stew, steak, dessert, sandwich or other: ";
		cin.ignore();
		cin >> type;
		stringToType(type);
		cout << "Cooking temperature: ";
		cin >> cookingTemperature;
		cout << "Cooking time: ";
		cin >> cookingTime;
		cout << "Used appliances: ";
		Vector<MyString> appliances;
		inputAppliances(appliances);
        try{
            recipebook.addHotMeal(name, ingredients, preperationTime, instructions, calories, type, cookingTemperature, cookingTime, appliances);
        }
        catch (invalid_argument& e) {
            cout << e.what() << endl;
        }
	}
	else if (compare(command, "cold")) {
		cout << "Let's get started then!" << endl;
		cout << "Name your invention: ";
		cin >> name;
		cout << "List of all the ingredients: ";
		IngredientList ingredients;
		inputIngredients(ingredients);
		cout << "Preparation time(in minutes): ";
		cin >> preperationTime;
		cout << "Instructions on how to prepare: ";
		cin.ignore();
		cin >> instructions;
		cout << "Overall calories per meal: ";
		cin >> calories;
		cout << "Choose a type: ";
		cout << "Choose between: soup, salad, pastry, stew, steak, dessert, sandwich or other: ";
		cin.ignore();
		cin >> type;
		stringToType(type);
		cout << "Storing temperature: ";
		cin >> storingTemperature;

		try{
            recipebook.addColdMeal(name, ingredients, preperationTime, instructions, calories, type, storingTemperature);
        }
        catch (invalid_argument& e) {
            cout << e.what() << endl;
        }
        cin.ignore();
	}
	else {
		cout << "Not a valid input. Please try again." << endl;
	}
}

void removeRecipe(MyString& user, MyString& pass) {
	cout << "Choose a recipe to remove" << endl;
	MyString ind;
	cin >> ind;
	recipebook.removeRecipe(ind.parseInt());
}

void printRecipe() {
	cout << "Here are all the recipes we can offer you." << endl;
	cout << "Choose wisely!" << endl;
	cout << "(Although everything in here is an addition that shouldn't be missed out on!)" << endl;
	recipebook.printAll();
}

void printByDifficultyRecipe() {
    cout << "You can also decide how difficult you want the recipes to be. " << endl;
    cout << "Choose difficulty between: 1, 2, 3, 4, 5." << endl;
    MyString difficulty;
    cin >> difficulty;
    recipebook.printDifficulty(difficulty.parseInt());
}

void sortedMenuRecipe() {
	cout << "Choose a type of food you would like to introduce to your menu:  " << endl;
	cout << "Choose between: soup, salad, stew, steak, dessert, sandwich or other." << endl;
	MyString choice;
	//cin.ignore();
	cin >> choice;
	if (choice == "soup") {
		cout << "Here are all the soups: " << endl;
		recipebook.printAllSoups();
	}
	else if (choice == "salad") {
		cout << "Here are all the salads: " << endl;
		recipebook.printAllSalads();
	}
	else if (choice == "dessert") {
		cout << "Here are all the desserts: " << endl;
		recipebook.printAllDesserts();
	}
	else if (choice == "stew") {
		cout << "Here are all the stews: " << endl;
		recipebook.printAllStew();
	}
	else if (choice == "steak") {
		cout << "Here are all the steaks: " << endl;
		recipebook.printAllSteak();
	}
	else if (choice == "sandwich") {
		cout << "Here are all the sandwiches: " << endl;
		recipebook.printAllSandwiches();
	}
	else {
		cout << "We don't have that category! " << endl;
		printRecipe();
	}
}

void openBookMenu(MyString& user, MyString& pass) {
	cout << endl << "Please choose a command: " << endl;
	cout << "add - add a new recipe" << endl;
	cout << "remove - remove a recipe" << endl;
	cout << "print - print all the recipes" << endl;
	cout << "printByDifficulty - sort the recipes by difficulty" << endl;
	cout << "sortedMenu - choose a specific course dish recipe. " << endl;
	cout << "logout - log out of the account" << endl;
	cout << "quit - quit the program" << endl;
	cout << endl;
	MyString command;
	cout << ">";
	cin >> command;

	if (compare("add", command)) {
		addRecipe();
		openBookMenu(user, pass);
		return;
	}
	else if (compare("remove", command)) {
		removeRecipe(user, pass);
		openBookMenu(user, pass);
		return;
	}
	else if (compare("print", command)) {
		printRecipe();
		openBookMenu(user, pass);
		return;
	}
	else if (compare("printByDifficulty", command)) {
		printByDifficultyRecipe();
		openBookMenu(user, pass);
		return;
	}
	else if (compare("sortedMenu", command)) {
		sortedMenuRecipe();
		openBookMenu(user, pass);
		return;
	}
	else if (compare("logout", command)) {
		cout << "Logging out..." << endl;
		commander(user, pass);
		return;
	}
	else if (compare("quit", command)) {
		cout << "Goodbye! Don't forget to eat!" << endl;
		return;
	}
	else {
		cout << "Not a valid command. Please choose another." << endl;
		openBookMenu(user, pass);
		return;
	}
}


void menu(MyString& user, MyString& pass) {
	cout << endl << "Please choose a command: " << endl;
	cout << "openBook - open the recipe book" << endl;
	cout << "logout - log out of the account" << endl;
	cout << "quit - quit the program" << endl;
	cout << endl;
	MyString command;
	cout << ">";
	cin >> command;
	if (compare("openBook", command)) {
		openBookMenu(user, pass);
		return;
	}
	else if (compare("logout", command)) {
		cout << "Logging out..." << endl;
		commander(user, pass);
		return;
	}
	else if (compare("readLabel", command)) {
		cout << "Want to learn how to cook something more extravagant?" << endl;
		cout << "Want to know more than a recipe on ho to build a sandwich?" << endl;
		cout << "Want to eat your own hog-washes?" << endl;
		cout << "That's just the place for you!" << endl;
		cout << "Here you can find recipes for every taste!" << endl;
		cout << "If you are into vegan food, we have delicious offers!" << endl;
		cout << "If you have a sweet tooth, there are plenty of pastries to try out!" << endl;
		cout << "If you just want some low-calorie lunch ideas to conform to your diet, we have it!" << endl;
		cout << "Now, go and find your food passion!" << endl;

		menu(user, pass);
		//commander(user, pass);
		return;
	}
	else if (compare("quit", command)) {
		cout << "Goodbye! Don't forget to eat!" << endl;
		return;
	}
	else {
		cout << "Not a valid command. Please choose another." << endl;
		menu(user, pass);
		return;
	}
}


void commander(MyString& user, MyString& pass) {
	cout << endl << "Please choose a command: signup, login, quit" << endl;
	cout << "login - to log into the system" << endl;
	cout << "signup - to create an account in the system" << endl;
	cout << "quit - to quit the programme" << endl;
	MyString command;
	cout << ">";
	cin >> command;
	if (command == "signup") {
		SignUp(user, pass);
		commander(user, pass);
		return;
	}
	else if (command == "login") {
		logIn();
		//menu(user, pass);
		return;
	}
	else if (command == "quit") {
		cout << "Goodbye!" << endl;
		return;
	}
	else {
		cout << "Not a valid command. Please choose another." << endl;
		commander(user, pass);
		return;
	}
}


int main() {
	GreetText();
	commander(sampleUser, samplePass);
	return 0;
}