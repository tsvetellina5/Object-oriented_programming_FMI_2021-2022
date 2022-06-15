#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Fauna.h"
#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Flora.h"
#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Fungi.h"
#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\RedBook.h"

#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\Vector.hpp"
#include "C:\Users\tswet\OneDrive\Documents\ФМИ\Object-oriented_programming_FMI_2021-2022\Additional\Teams\Team 3\h\StringC.h"

void commandMenu(RedBook&);

int strToint(const char*);

int main()
{

	RedBook tempBook;

	commandMenu(tempBook);

	//MENU 
	//!!!not finished for add!!!
	//finished until remove

	return 0;
}

void commandMenu(RedBook& tempBook)
{
	StringC consoleCom;
	std::cout << " Welcome" << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "1 - print" << std::endl;
	std::cout << "2 - add/remove" << std::endl;
	std::cout << "3 - check" << std::endl;
	std::cout << ">";
	consoleCom.getline(std::cin);

	while (true)
	{
		if (consoleCom == "1" || consoleCom == "print" || consoleCom == "Print")
		{
			std::cout << "	1 - print Flora" << std::endl;
			std::cout << "	2 - print Fauna" << std::endl;
			std::cout << "	3 - print Fungi" << std::endl;
			std::cout << "  4 - print all" << std::endl;
			std::cout << "	>";
			consoleCom.getline(std::cin);
			if (consoleCom == "1" || consoleCom == "flora" || consoleCom == "Flora" || consoleCom == "print Flora")
			{
				std::cout << "	All plants in the book:" << std::endl;
				tempBook.printFlora();
			}
			else if (consoleCom == "2" || consoleCom == "fauna" || consoleCom == "Fauna" || consoleCom == "print Fauna")
			{
				std::cout << "	All animals in the book:" << std::endl;
				tempBook.printFauna();
			}
			else if (consoleCom == "3" || consoleCom == "fungi" || consoleCom == "Fungi" || consoleCom == "print Fungi")
			{
				std::cout << "	All fungi in the book:" << std::endl;
				tempBook.printFungi();
			}
			else if (consoleCom == "4" || consoleCom == "flora" || consoleCom == "Flora" || consoleCom == "print Flora")
			{
				std::cout << "	All species in the book:" << std::endl;
				tempBook.printAll();
			}
			else
			{
				std::cout << "	Wrong command!" << std::endl;
				continue;
			}
		}
		else if (consoleCom == "2" || consoleCom == "add" || consoleCom == "remove" || consoleCom == "add/remove")
		{
			std::cout << "	1 - add organism" << std::endl;
			std::cout << "	2 - remove organism" << std::endl;
			std::cout << "	>";
			consoleCom.getline(std::cin);
			if (consoleCom == "1" || consoleCom == "add" || consoleCom == "Add" || consoleCom == "add organism")
			{
				std::cout << "	  1 - animal (flora)" << std::endl;
				std::cout << "    2 - plant (fauna)" << std::endl;
				std::cout << "    3 - fungus (fungi)" << std::endl;
				std::cout << "	  >";
				consoleCom.getline(std::cin);
				if (consoleCom == "1" || consoleCom == "animal" || consoleCom == "Animal" || consoleCom == "fauna")
				{
					Fauna temp;
				}
				else if (consoleCom == "2" || consoleCom == "plant" || consoleCom == "Plant" || consoleCom == "flora")
				{
					Flora temp;
				}
				else if (consoleCom == "3" || consoleCom == "fungus" || consoleCom == "Fungus" || consoleCom == "fungi")
				{
					Fungi temp;
				}
				else
				{
					std::cout << "	  Wrong command!" << std::endl;
					continue;
				}
			}
			else if (consoleCom == "2" || consoleCom == "remove" || consoleCom == "Remove" || consoleCom == "remove organism")
			{
				std::cout << "    name or index" << std::endl;
				std::cout << "    >";
				consoleCom.getline(std::cin);
				int conNum = strToint(consoleCom.getString());
				int index = tempBook.getSpeciesIndex(consoleCom);
				if (index == -1)
				{
					std::cout << "    Organism is not in the book." << std::endl;
					continue;
				}

				if (!tempBook.removeAtIndex(index))
				{
					std::cout << "    Error in removing!" << std::endl;
					continue;
				}
				std::cout << "    Successful removal" << std::endl;
				continue;



			}
		}
	}
}

int strToint(const char* str)
{
	int index = 0;
	int temp = 1;
	for (int i = StringC(str).getSize() - 1; i >= 0; i--)
	{
		index += (int(str[i]) - int(char('0'))) * temp;
		temp *= 10;
	}
	return index;
}