#include "Enums.h"
#include<iostream>
char* getComponentTypeText(const ComponentType& componentType)
{
	char* type = new char[20];
	switch (componentType)
	{
	case MOTHERBOARD: strcpy(type, "Motherboard"); break;
	case CPU: strcpy(type, "CPU"); break;
	case GPU: strcpy(type, "GPU"); break;
	case RAM: strcpy(type, "RAM"); break;
	}

	return type;
}

char* getSocketTypeText(const Socket& socket)
{
	char* type = new char[10];
	switch (socket)
	{
	case AM4: strcpy(type, "AM4"); break;
	case AM5: strcpy(type, "AM5"); break;
	case LGA1151: strcpy(type, "LGA1151"); break;
	case LGA1200: strcpy(type, "LGA1200"); break;
	}

	return type;
}

char* getRamTypeText(const RamType& ramType)
{
	char* type = new char[5];
	switch (ramType)
	{
	case DDR4: strcpy(type, "DDR4"); break;
	case DDR5: strcpy(type, "DDR5"); break;
	}
	return type;
}

ComponentType getComponentTypeFromString(const char* input)
{
	if(strcmp(input, "Motherboard") == 0)
		return MOTHERBOARD;
	if(strcmp(input, "CPU") == 0)
		return CPU;
	if(strcmp(input, "GPU") == 0)
		return GPU;
	if(strcmp(input, "RAM") == 0)
		return RAM;
}

Socket getSocketFromString(const char* input)
{
	if (strcmp(input, "AM4") == 0)
		return AM4;
	if (strcmp(input, "AM5") == 0)
		return AM5;
	if (strcmp(input, "LGA1151") == 0)
		return LGA1151;
	if (strcmp(input, "LGA1200") == 0)
		return LGA1200;
}

RamType getRamTypeFromString(const char* input)
{
	if (strcmp(input, "DDR4") == 0)
		return DDR4;
	if (strcmp(input, "DDR5") == 0)
		return DDR5;
}
