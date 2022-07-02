#include <iostream>
#include "StreamManipulation.h"
using namespace std;

int main()
{
	PCStore pcstore = readComponents();
	char* line = new char[BUFFER_LINE];
	
	while (strcmp(line, "exit"))
	{
		cin.getline(line, BUFFER_LINE);

		if (strcmp(line, "exit") == 0)
		{
			cout << "Exit" << endl;
			break;
		}

		if (strcmp(line, "print") == 0)
			pcstore.printComponentInfos();

		if (checkStartsWith(line, "buy Motherboard"))
		{
			double price = readDoubleAtIndex(line, getIndexOfSpace(line, 4), getIndexOfSpace(line, 5));

			if (pcstore.checkBalance(price))
			{
				pcstore.addMotherboard(readMotherboard(substr(line, 4)));
				pcstore.subtractFunds(price);
				cout << "Motherboard bought!" << endl;
			}
			else
			{
				cout << "Insufficient funds!" << endl;
			}
		}

		if (checkStartsWith(line, "buy CPU"))
		{
			double price = readDoubleAtIndex(line, getIndexOfSpace(line, 4), getIndexOfSpace(line, 5));

			if (pcstore.checkBalance(price))
			{
				pcstore.addCpu(readCpu(substr(line, 4)));
				pcstore.subtractFunds(price);
				cout << "CPU bought!" << endl;
			}
			else
			{
				cout << "Insufficient funds!" << endl;
			}
		}
		if (checkStartsWith(line, "buy GPU"))
		{
			double price = readDoubleAtIndex(line, getIndexOfSpace(line, 4), getIndexOfSpace(line, 5));

			if (pcstore.checkBalance(price))
			{
				pcstore.addGpu(readGpu(substr(line, 4)));
				pcstore.subtractFunds(price);
				cout << "GPU bought!" << endl;
			}
			else
			{
				cout << "Insufficient funds!" << endl;
			}
		}
		if (checkStartsWith(line, "buy RAM"))
		{
			double price = readDoubleAtIndex(line, getIndexOfSpace(line, 4), getIndexOfSpace(line, 5));

			if (pcstore.checkBalance(price))
			{
				pcstore.addRam(readRam(substr(line, 4)));
				pcstore.subtractFunds(price);
				cout << "RAM bought!" << endl;
			}
			else
			{
				cout << "Insufficient funds!" << endl;
			}
		}
		if (checkStartsWith(line, "sell"))
		{
			 size_t index = readDoubleAtIndex(line, getIndexOfSpace(line, 1), strlen(line));
			 pcstore.sellComponent(index - 1);
		}
		if (checkStartsWith(line, "build"))
		{
			pcstore.buildComputer();
		}
		if (checkStartsWith(line, "funds"))
		{
			cout << "Money: " << pcstore.getMoney() << std::endl;
		}
	}

	pcstore.writeToFile();
	return 0;
}