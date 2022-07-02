#include "StreamManipulation.h"

PCStore readComponents()
{
	std::ifstream file;
	file.open("components.txt");

	PCStore pcstore;

	char* line = new char[BUFFER_LINE];

	file.getline(line, BUFFER_LINE);
	pcstore.setMoney(readDoubleAtIndex(line, getIndexOfSpace(line, 1), strlen(line)));

	while (checkStartsWith(line, "End") == 0)
	{
		file.getline(line, BUFFER_LINE);

		if (checkStartsWith(line, "End"))
			break;

		if (checkStartsWith(line, "Motherboard"))
			pcstore.addMotherboard(readMotherboard(line));
		if (checkStartsWith(line, "CPU"))
			pcstore.addCpu(readCpu(line));
		if (checkStartsWith(line, "GPU"))
			pcstore.addGpu(readGpu(line));
		if (checkStartsWith(line, "RAM"))
			pcstore.addRam(readRam(line));

	}

	file.close();

	return pcstore;
}
Motherboard readMotherboard(const char* line)
{
	char* manufacturer = readStringAtIndex(line, getIndexOfSpace(line, 1), getIndexOfSpace(line, 2));
	char* model = readStringAtIndex(line, getIndexOfSpace(line, 2), getIndexOfSpace(line, 3));
	double price = readDoubleAtIndex(line, getIndexOfSpace(line, 3), getIndexOfSpace(line, 4));

	Socket socket = getSocketFromString(readStringAtIndex(line, getIndexOfSpace(line, 4), getIndexOfSpace(line, 5)));
	RamType ramType = getRamTypeFromString(readStringAtIndex(line, getIndexOfSpace(line, 5), strlen(line)));

	return Motherboard(manufacturer, model, price, socket, ramType);
}

Cpu readCpu(const char* line)
{
	char* manufacturer = readStringAtIndex(line, getIndexOfSpace(line, 1), getIndexOfSpace(line, 2));
	char* model = readStringAtIndex(line, getIndexOfSpace(line, 2), getIndexOfSpace(line, 3));
	double price = readDoubleAtIndex(line, getIndexOfSpace(line, 3), getIndexOfSpace(line, 4));

	Socket socket = getSocketFromString(readStringAtIndex(line, getIndexOfSpace(line, 4), getIndexOfSpace(line, 5)));
	size_t cores = readDoubleAtIndex(line, getIndexOfSpace(line, 5), strlen(line));

	return Cpu(manufacturer, model, price, socket, cores);
}

Gpu readGpu(const char* line)
{
	char* manufacturer = readStringAtIndex(line, getIndexOfSpace(line, 1), getIndexOfSpace(line, 2));
	char* model = readStringAtIndex(line, getIndexOfSpace(line, 2), getIndexOfSpace(line, 3));
	double price = readDoubleAtIndex(line, getIndexOfSpace(line, 3), getIndexOfSpace(line, 4));

	size_t videoMemory = readDoubleAtIndex(line, getIndexOfSpace(line, 4), strlen(line));

	return Gpu(manufacturer, model, price, videoMemory);
}

Ram readRam(const char* line)
{
	char* manufacturer = readStringAtIndex(line, getIndexOfSpace(line, 1), getIndexOfSpace(line, 2));
	char* model = readStringAtIndex(line, getIndexOfSpace(line, 2), getIndexOfSpace(line, 3));
	double price = readDoubleAtIndex(line, getIndexOfSpace(line, 3), getIndexOfSpace(line, 4));

	RamType ramType = getRamTypeFromString(readStringAtIndex(line, getIndexOfSpace(line, 4), getIndexOfSpace(line, 5)));

	size_t memoryCapacity = readDoubleAtIndex(line, getIndexOfSpace(line, 5), strlen(line));

	return Ram(manufacturer, model, price, ramType, memoryCapacity);
}

double readDoubleAtIndex(const char* line, int indexStart, int indexEnd)
{
	double number = 0.0;
	double fractional = 0.0;
	bool negative = false;

	for (size_t i = indexStart + 1; i < indexEnd; i++)
	{
		if (line[i] == '"')
			break;

		if (line[i] == '.')
		{
			for (size_t j = indexEnd - 1; j > i; j--)
			{
				fractional = fractional * 0.1 + (line[j] - '0');
			}
			fractional *= 0.1;
			number += fractional;
			break;
		}

		if (line[i] == '-')
			negative = true;
		else
			number = number * 10 + (line[i] - '0');
	}

	if (negative)
		return -number;
	else
		return number;
}

char* readStringAtIndex(const char* line, int indexStart, int indexEnd)
{
	char* color = new char[indexEnd - indexStart];
	int indexColor = 0;

	for (size_t i = indexStart + 1; i < indexEnd; i++)
	{
		color[indexColor++] = line[i];
	}
	color[indexColor] = '\0';
	return color;
}

int getIndexOfSpace(const char* line, int numberSpace)
{
	int spaceAt = 0;
	int l = strlen(line);

	size_t i = 0;

	for (; i < l; i++)
	{
		if (line[i] == ' ')
			spaceAt++;
		if (spaceAt == numberSpace)
			break;
	}

	return i;
}

bool checkStartsWith(const char* line, const char* check)
{
	int sizeCheck = strlen(check);

	int sizeInput = strlen(line);

	if (sizeInput < sizeCheck)
		return false;

	for (int i = 0; i < sizeCheck; i++)
	{
		if (line[i] != check[i])
			return false;
	}

	return true;
}

bool checkFileExists(const char* fileName)
{

	std::ifstream file;
	file.open(fileName);

	bool isOpen = file.is_open();

	file.close();

	return isOpen;
}

char* substr(const char* line, size_t index)
{
	char* str = new char[strlen(line) + 1 - index];
	size_t k = 0;
	for (size_t i = index; i < strlen(line); i++)
	{
		str[k++] = line[i];
	}
	str[k] = '\0';
	return str;
}