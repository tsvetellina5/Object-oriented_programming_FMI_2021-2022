#include <cstring>
#include <iostream>
#include "String.h"
#pragma warning(disable: 4996)

void String::copyFrom(const String& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	size = other.size;
}
void String::free()
{
	delete[] str;
}

String::String(const char* data)
{
	if (data == nullptr)
	{
		str = new char[1];
		str[0] = '\0';
		size = 0;
	}
	else
	{
		size = strlen(data);
		str = new char[size + 1];
		strcpy(str, data);
	}
}

size_t getNumSize(size_t num)
{
	size_t res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return res;
}

String::String(size_t n)
{
	int numSize = getNumSize(n);
	str = new char[numSize + 1];

	str[numSize] = '\0';

	for (size_t i = 0; i < numSize; i++, n /= 10)
		str[numSize - 1 - i] = (n % 10) + '0';
	size = numSize;
}

String::String()
{
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

String::String(const String& other)
{
	copyFrom(other);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

String::~String()
{
	free();
}


size_t String::getSize() const
{
	return size;
}

const char* String::c_str() const
{
	return str;
}

bool String::contains(char symbol) const {

	int length = this->getSize();

	for (int i = 0; i < length; i++)
	{
		if (str[i] == symbol)
		{
			return true;
		}
	}

	return false;
}

int String::toInt() {

	int result = 0;
	int digitsCount = strlen(str);

	int i = 0;
	bool negative = false;

	if (str[0] == '-')
	{
		negative = true;
		i++;
	}

	while (i < digitsCount)
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}

	if (negative)
	{
		return -1 * result;
	}
	else
	{
		return result;
	}
}

Vector<String> String::split(const char seperator) {

	Vector<String> arguments;

	int length = this->getSize();

	for (int i = 0; i < length; i++)
	{
		if (str[i] == seperator)
		{
			continue;
		}

		char argument[1024];
		int argumentIndex = 0;

		while (str[i] != seperator && str[i] != '\0')
		{
			argument[argumentIndex] = str[i];
			argumentIndex++;
			i++;
		}

		argument[argumentIndex] = '\0';
	
		arguments.pushBack(String(argument));
	}

	return arguments;
}

Vector<String> String::split(const String& seperators) {

	Vector<String> arguments;

	int length = this->getSize();

	for (int i = 0; i < length; i++)
	{
		if (seperators.contains(str[i]))
		{
			continue;
		}

		char argument[1024];
		int argumentIndex = 0;

		while (!seperators.contains(str[i]) && str[i] != '\0')
		{
			argument[argumentIndex] = str[i];
			argumentIndex++;
			i++;
		}

		argument[argumentIndex] = '\0';

		arguments.pushBack(String(argument));
	}

	return arguments;
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	stream << str.str;
	return stream;
}

std::istream& operator>>(std::istream& stream, String& str)
{
	str.free();
	char buff[1024];
	stream.getline(buff, 1024);

	str.size = strlen(buff);
	str.str = new char[str.size + 1];
	strcpy(str.str, buff);

	return stream;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

String::String(String&& otherString)
{
	str = otherString.str;
	size = otherString.size;
	otherString.str = nullptr;
}

String& String::operator=(String&& otherString)
{

	if (this != &otherString)
	{
		free();
		str = otherString.str;
		otherString.str = nullptr;
		size = otherString.size;
	}
	return *this;
}
