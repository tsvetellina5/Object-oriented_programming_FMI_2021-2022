#include <iomanip>
#include <stdlib.h>
#include "ExamString.h"
#pragma warning (disable: 4996)

bool isStringValid(const char*);
size_t length(size_t);

ExamString::ExamString()
{
	toDefaultData();
}
ExamString::ExamString(size_t number)
{
	size = length(number);
	str = new char[size + 1];
	itoa(number, str, 10);
}
ExamString::ExamString(const char* str)
{
	if (isStringValid(str)) {
		toString(str);
	} else {
		toDefaultData();
	}
}
ExamString& ExamString::operator=(const ExamString& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}
ExamString::~ExamString()
{
	free();
}

bool ExamString::setString(const char* str)
{
	if (!isStringValid(str)) {
		return false;
	}

	free();
	toString(str);
	return true;
}
size_t ExamString::getSize() const
{
	return size;
}

const char& ExamString::operator[](size_t index) const
{
	if (index > size - 1)
		throw std::out_of_range("Invalid index");

	return str[index];
}
char& ExamString::operator[](size_t index)
{
	if (index > size - 1)
		throw std::out_of_range("Invalid index");

	return str[index];
}
ExamString& ExamString::operator+=(const ExamString& other)
{
	size += other.size;
	char* temp = new char[size + 1];

	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;

	return *this;
}

void ExamString::toDefaultData()
{
	size = 0;
	str = new char[1];
	str[0] = '\0';
}
void  ExamString::toString(const char* str)
{
	size = strlen(str);
	this->str = new char[size + 1];
	strcpy(this->str, str);
}

ExamString operator+(const ExamString& lhs, const ExamString& rhs)
{
	ExamString copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}
std::ostream& operator<<(std::ostream& stream, const ExamString& str)
{
	stream << str.str;
	return stream;
}
std::istream& operator>>(std::istream& stream, ExamString& str)
{
	char buffer[1024];
	stream >> std::setw(1024) >> buffer;

	str.free();
	str.size = strlen(buffer);
	str.str = new char[str.size + 1];
	strcpy(str.str, buffer);

	return stream;
}

void ExamString::copy(const ExamString& other)
{
	size = other.size;
	str = new char[size + 1];
	strcpy(str, other.str);
}
void ExamString::free()
{
	delete[] str;
}

bool isStringValid(const char* str)
{
	return str != nullptr;
}
size_t length(size_t number)
{
	size_t numberOfDigits = 0;
	while (number) 
	{
		number /= 10;
		numberOfDigits++;
	}

	return numberOfDigits;
}

