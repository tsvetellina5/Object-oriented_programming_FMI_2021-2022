#pragma once
#pragma warning(disable : 4996)
enum ComponentType
{
	MOTHERBOARD,
	CPU,
	GPU,
	RAM
};

enum Socket
{
	AM4,
	AM5,
	LGA1151,
	LGA1200
};

enum RamType
{
	DDR4,
	DDR5
};

char* getComponentTypeText(ComponentType componentType);
char* getSocketTypeText(Socket socket);
char* getRamTypeText(RamType ramType);

ComponentType getComponentTypeFromString(const char*);
Socket getSocketFromString(const char*);
RamType getRamTypeFromString(const char*);