#include "Fauna.h"
#include "Flora.h"
#include "Fungi.h"
#include "RedBook.h"

#include "Vector.hpp"
#include "StringC.h"

void commandMenu(RedBook&);

void printMainCommands();
void printPrintCommands();
void printLevels();

int strToint(const StringC&);
bool isInteger(const StringC&);

int main()
{

	RedBook tempBook;

	commandMenu(tempBook);

	return 0;
}

void commandMenu(RedBook& tempBook)
{
	StringC consoleCom;
	while (true)
	{
		printMainCommands();
		std::cout << ">";
		consoleCom.getline(std::cin);

		if (consoleCom == "1" || consoleCom == "print" || consoleCom == "Print")
		{
			printPrintCommands();
			std::cout << "  >";
			consoleCom.getline(std::cin);
			if (consoleCom == "1" || consoleCom == "flora" || consoleCom == "Flora" || consoleCom == "print Flora")
			{
				std::cout << "  All plants in the book:" << std::endl;
				tempBook.printFlora();
			}
			else if (consoleCom == "2" || consoleCom == "fauna" || consoleCom == "Fauna" || consoleCom == "print Fauna")
			{
				std::cout << "  All animals in the book:" << std::endl;
				tempBook.printFauna();
			}
			else if (consoleCom == "3" || consoleCom == "fungi" || consoleCom == "Fungi" || consoleCom == "print Fungi")
			{
				std::cout << "  All fungi in the book:" << std::endl;
				tempBook.printFungi();
			}
			else if (consoleCom == "4" || consoleCom == "conservation" || consoleCom == "Conservation" || consoleCom == "print Conservation level")
			{
				printLevels();

				std::cout << "    conservation level" << std::endl;
				std::cout << "    >";
				consoleCom.getline(std::cin);

				int index = strToint(consoleCom.getString());

				if (index < 0 || index > 7)
				{
					std::cout << "    Conservation level must be from 0 to 7." << std::endl;
					continue;
				}

				std::cout << "    All species with conservation level " << consoleCom << std::endl;
				tempBook.printConservationLevel(index);
			}
			else if (consoleCom == "5" || consoleCom == "flora" || consoleCom == "Flora" || consoleCom == "print Flora")
			{
				std::cout << "    All species in the book:" << std::endl;
				tempBook.printAll();
			}
			else if (consoleCom == "0" || consoleCom == "quit")
				continue;

			else
				std::cout << "  Wrong command!" << std::endl;
		}

		else if (consoleCom == "2" || consoleCom == "add" || consoleCom == "remove" || consoleCom == "add/remove")
		{
			std::cout << "  1 - add organism" << std::endl;
			std::cout << "  2 - remove organism" << std::endl;
			std::cout << "  0 - quit" << std::endl;
			std::cout << "  >";
			consoleCom.getline(std::cin);

			if (consoleCom == "1" || consoleCom == "add" || consoleCom == "Add" || consoleCom == "add organism")
			{
				std::cout << "    1 - animal (fauna)" << std::endl;
				std::cout << "    2 - plant (flora)" << std::endl;
				std::cout << "    3 - fungus (fungi)" << std::endl;
				std::cout << "    0 - quit" << std::endl;
				std::cout << "    >";

				consoleCom.getline(std::cin);
				if (consoleCom == "1" || consoleCom == "animal" || consoleCom == "Animal" || consoleCom == "fauna")
				{
					if (!tempBook.addFaunaFromUserInput())
						std::cout << "Adding was unsuccessful." << std::endl;
					else
						std::cout << "Adding was successful." << std::endl;
				}
				else if (consoleCom == "2" || consoleCom == "plant" || consoleCom == "Plant" || consoleCom == "flora")
				{
					if (!tempBook.addFloraFromUserInput())
						std::cout << "Adding was unsuccessful." << std::endl;
					else
						std::cout << "Adding was successful." << std::endl;
				}
				else if (consoleCom == "3" || consoleCom == "fungus" || consoleCom == "Fungus" || consoleCom == "fungi")
				{
					if (!tempBook.addFungiFromUserInput())
						std::cout << "Adding was unsuccessful." << std::endl;
					else
						std::cout << "Adding was successful." << std::endl;
				}
				else if (consoleCom == "0" || consoleCom == "quit")
					continue;
				else
					std::cout << "	  Wrong command!" << std::endl;
			}

			else if (consoleCom == "2" || consoleCom == "remove" || consoleCom == "Remove" || consoleCom == "remove organism")
			{
				std::cout << "   name or index" << std::endl;
				std::cout << "   >";
				consoleCom.getline(std::cin);

				int index = tempBook.getIndexFromUserInput(consoleCom);

				if (!tempBook.isValidIndex(index))
				{
					std::cout << "    No such organism." << std::endl;
					continue;
				}

				else
				{
					tempBook.removeAtIndex(index);
					std::cout << "    Successful removal" << std::endl;
				}
			}
			else if (consoleCom == "0" || consoleCom == "quit" || consoleCom == "Quit")
				continue;
			else
				std::cout << "	  Wrong command!" << std::endl;
		}

		else if (consoleCom == "3" || consoleCom == "check" || consoleCom == "change" || consoleCom == "check/change")
		{
			std::cout << "	1 - check species" << std::endl;
			std::cout << "	2 - check conservation level" << std::endl;
			std::cout << "	3 - change species" << std::endl;
			std::cout << "	4 - change conservation level" << std::endl;
			std::cout << "	0 - quit" << std::endl;
			std::cout << "	>";

			consoleCom.getline(std::cin);

			if (consoleCom == "1" || consoleCom == "check species")
			{
				std::cout << "    name or index" << std::endl;
				std::cout << "    >";

				consoleCom.getline(std::cin);

				int index = tempBook.getIndexFromUserInput(consoleCom);

				if (!tempBook.isValidIndex(index))
				{
					std::cout << "    No such organism." << std::endl;
					continue;
				}

				tempBook.getSpeciesAt(index)->print();
			}
			else if (consoleCom == "2" || consoleCom == "check conservation" || consoleCom == "check conservation level")
			{
				std::cout << "    name or index" << std::endl;
				std::cout << "    >";
				consoleCom.getline(std::cin);


				int index = tempBook.getIndexFromUserInput(consoleCom);

				if (!tempBook.isValidIndex(index))
				{
					std::cout << "    No such organism." << std::endl;
					continue;
				}

				std::cout << "    " << tempBook.getSpeciesAt(index)->getConservationLevel() << std::endl;

			}
			else if (consoleCom == "3" || consoleCom == "change species")
			{
				std::cout << "    name or index" << std::endl;
				std::cout << "    >";
				consoleCom.getline(std::cin);

				int index = tempBook.getIndexFromUserInput(consoleCom);

				if (!tempBook.isValidIndex(index))
				{
					std::cout << "    No such organism." << std::endl;
					continue;
				}

				std::cout << "	  1 - add habitat" << std::endl;
				std::cout << "	  2 - remove habitat" << std::endl;
				std::cout << "	  0 - quit" << std::endl;
				std::cout << "	  >";
				consoleCom.getline(std::cin);

				if (consoleCom == "1" || consoleCom == "add habitat")
				{
					std::cout << "      new habitat" << std::endl;
					std::cout << "	    >";
					consoleCom.getline(std::cin);
					tempBook.addHabitatByIndex(index, consoleCom);
				}
				else if (consoleCom == "2" || consoleCom == "remove habitat")
				{
					std::cout << "      remove habitat" << std::endl;
					std::cout << "	    >";
					consoleCom.getline(std::cin);
					if (tempBook.removeHabitatByIndex(index, consoleCom))
						std::cout << "      Remove successful" << std::endl;
					else
						std::cout << "      Error in removing!" << std::endl;
				}
				else if (consoleCom == "0" || consoleCom == "quit")
					continue;
				else
					std::cout << "    Invalid command!" << std::endl;
			}

			else if (consoleCom == "4" || consoleCom == "change conservation" || consoleCom == "change conservation level")
			{
				std::cout << "    --levels:" << std::endl;
				std::cout << "    --least concern" << std::endl;
				std::cout << "    --near threatened" << std::endl;
				std::cout << "    --vulnerable" << std::endl;
				std::cout << "    --endangered" << std::endl;
				std::cout << "    --critically endangered" << std::endl;
				std::cout << "    --extinct in the wild" << std::endl;
				std::cout << "    --extinct" << std::endl;
				std::cout << "    --unknown" << std::endl;

				std::cout << "    name or index of species" << std::endl;
				std::cout << "    >";

				consoleCom.getline(std::cin);

				int index = tempBook.getIndexFromUserInput(consoleCom);

				if (!tempBook.isValidIndex(index))
				{
					std::cout << "    No such organism." << std::endl;
					continue;
				}

				std::cout << "    level" << std::endl;
				std::cout << "    >";
				consoleCom.getline(std::cin);

				if (isInteger(consoleCom))
				{
					std::cout << "    Level can't be a number." << std::endl;
					continue;
				}

				if (!tempBook.setConservationLevelByIndex(index, consoleCom))
					std::cout << "    Extinct species' level cannot be changed." << std::endl;
				else
					std::cout << "    Successful change" << std::endl;
			}
			else if (consoleCom == "0" || consoleCom == "quit")
				continue;
			else
				std::cout << "  Wrong command!" << std::endl;
		}

		else if (consoleCom == "0" || consoleCom == "quit" || consoleCom == "Quit")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}

		else
			std::cout << "Wrong command!" << std::endl;
	}
}

void printMainCommands()
{
	std::cout << "Available commands:" << std::endl;
	std::cout << "1 - print" << std::endl;
	std::cout << "2 - add/remove" << std::endl;
	std::cout << "3 - check/change" << std::endl;
	std::cout << "0 - quit" << std::endl;
}

void printPrintCommands()
{
	std::cout << "  1 - print Flora" << std::endl;
	std::cout << "  2 - print Fauna" << std::endl;
	std::cout << "  3 - print Fungi" << std::endl;
	std::cout << "  4 - print Conservation level" << std::endl;
	std::cout << "  5 - print all" << std::endl;
	std::cout << "  0 - quit" << std::endl;
}

void printLevels()
{
	std::cout << std::endl;
	std::cout << "    levels:" << std::endl;
	std::cout << "    least concern - 0" << std::endl;
	std::cout << "    near threatened - 1" << std::endl;
	std::cout << "    vulnerable - 2" << std::endl;
	std::cout << "    endangered - 3" << std::endl;
	std::cout << "    critically endangered - 4" << std::endl;
	std::cout << "    extinct in the wild - 5" << std::endl;
	std::cout << "    extinct - 6" << std::endl;
	std::cout << "    unknown - 7" << std::endl;
}