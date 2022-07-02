#include <iostream>
#include "Lion.h"
#include "CaloforniaCondor.h"
#include "Penguin.h"
#include "Tiger.h"
#include "Food.h"
#include "Zoo.h"
#include "WhiteTiger.h"
#include "WhiteLion.h"
#include "BrownBear.h"
#include "Sloth.h"
#include "Deer.h"
#include "Fish.h"
#include "Leaves.h"
#include "Pig.h"
#include "Squid.h"

using namespace std;

void run();

int main()
{
	run();
}

void run()
{
	Zoo zoo;

	String command;
	cout << "> ";
	cin >> command;

	while (!(command == "Stop"))
	{
		try
		{
			Vector<String> args = command.split(' ');

			if (args[0] == "printInfo")
			{
				zoo.print();
			}
			else if (args[0] == "saveToFile")
			{
				zoo.saveToFile();
			}
			else if (args[0] == "printInfoFood")
			{
				zoo.printInfoFood();
			}
			else if (args[0] == "printSounds")
			{
				zoo.printSounds();
			}
			else if (args[0] == "printFood")
			{
				zoo.printAvailableFood();
			}
			else if (args[0] == "add")
			{
				Animal* animal = nullptr;

				if (!(args[1] == "Lion" || args[1] == "Tiger" || args[1] == "CaliforniaCondor" || args[1] == "Penguin"
					|| args[1] == "WhiteLion" || args[1] == "WhiteTiger" || args[1] == "Sloth" || args[1] == "BrownBear"))
				{
					throw "Invalid animal!";
				}

				int age = args[2].toInt();
				int weight = args[3].toInt();
				int calories = args[4].toInt();
				String name = args[5];

				if (age < 0 || weight < 0 || calories < 0 || name == "")
				{
					throw "Invalid argument";
				}

				if (args[1] == "Lion")
				{
					int speed = args[6].toInt();

					if (speed < 0)
					{
						throw "Invalid argument";
					}

					animal = new Lion(age, weight, calories, name, speed);
				}
				else if (args[1] == "Tiger")
				{
					int speed = args[6].toInt();

					if (speed < 0)
					{
						throw "Invalid argument";
					}

					animal = new Tiger(age, weight, calories, name, speed);
				}
				else if (args[1] == "Penguin")
				{
					animal = new Penguin(age, weight, calories, name);
				}
				else if (args[1] == "CaliforniaCondor")
				{
					int wingspan = args[6].toInt();

					if (wingspan < 0)
					{
						throw "Invalid argument";
					}

					animal = new CaliforniaCondor(age, weight, calories, name, wingspan);
				}
				else if (args[1] == "BrownBear")
				{
					int speed = args[6].toInt();

					if (speed < 0)
					{
						throw "Invalid argument";
					}

					animal = new BrownBear(age, weight, calories, name, speed);
				}
				else if (args[1] == "Sloth")
				{
					int speed = args[6].toInt();

					if (speed < 0)
					{
						throw "Invalid argument";
					}

					animal = new Sloth(age, weight, calories, name, speed);
				}
				else if (args[1] == "WhiteTiger")
				{
					int speed = args[6].toInt();

					if (speed < 0)
					{
						throw "Invalid argument";
					}

					animal = new WhiteTiger(age, weight, calories, name, speed);
				}
				else if (args[1] == "WhiteLion")
				{
					int speed = args[6].toInt();

					if (speed < 0)
					{
						throw "Invalid argument";
					}

					animal = new WhiteLion(age, weight, calories, name, speed);
				}

				zoo.addAnimal(animal);
			}
			else if (args[0] == "remove")
			{
				int index = args[1].toInt();
				zoo.removeAnimal(index);
			}
			else if (args[0] == "feed")
			{
				int index = args[1].toInt();

				String foodName = args[2];
				zoo.feedAnimal(index, foodName);

			}
			else if (args[0] == "restock")
			{
				int amount = args[1].toInt();
				Food* food = nullptr;
				if (args[2] == "Leaves") 
				{
					food = new Leaves();
				}
				else if (args[2] == "Deer") {
					food = new Deer();
				}
				else if (args[2] == "Fish") 
				{
					food = new Fish();
				}
				else if (args[2] == "Pig") 
				{
					food = new Pig();
				}
				else if (args[2] == "Squid") 
				{
					food = new Squid();
				}
				zoo.restock(amount, food);
			}
			else if (args[0] == "letPlay")
			{
				int index = args[1].toInt();
				int time = args[2].toInt();

				zoo.letAnimalPlay(index, time);
			}
			else if (args[0] == "fastestCat")
			{
				zoo.showFastestCat();
			}
			else if (args[0] == "changeName")
			{
				int index = args[1].toInt();
				String newName = args[2];

				zoo.changeAnimalName(index, newName);
			}
			else if (args[0] == "allFed")
			{
				bool areFed = zoo.areAllAnimalsFed();

				if (areFed)
				{
					cout << "All animals are fed" << std::endl;
				}
				else
				{
					cout << "There are still animals that need to eat more!" << endl;
				}
			}
			else if (args[0] == "havePlayed")
			{
				bool allPlayed = zoo.allAnimalsPlayedEnough();

				if (allPlayed)
				{
					cout << "All animals have played enough" << endl;
				}
				else
				{
					cout << "There are still animls that need to play more!" << endl;
				}
			}
			else
			{
				throw "Invalid command";
			}
		}
		catch (const char* ex)
		{
			cout << ex << endl;
		}

		cout << "> ";
		cin >> command;
	}
}
