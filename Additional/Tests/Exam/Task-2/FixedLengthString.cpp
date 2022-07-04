#include "FixedLengthString.h"

bool isStringLengthValid(const char*, size_t);
bool isStringValid(const char*);

FixedLengthString::FixedLengthString(size_t size)
{
	delete[] str;
	
	str = new char[size + 1];
	str[size] = '\0';

	for (size_t i = 0; i < size; i++) {
		str[i] = ' ';
	}

	this->size = size;
}

FixedLengthString::FixedLengthString(size_t size, const char* str)
{	
	if (isStringLengthValid(str, size) && isStringValid(str)) {
		setString(str);
	} else {
		delete[] str;
		
		this->str = new char[size + 1];
		this->str[size] = '\0';

		for (size_t i = 0; i < size; i++) {
			this->str[i] = ' ';
		}

		this->size = size;
	}
}

FixedLengthString& FixedLengthString::operator+=(const ExamString& other)
{
	throw std::out_of_range("FixedLengthString cannot be concatenated");

	return *this;
}


bool isStringLengthValid(const char* str, size_t size)
{
	return strlen(str) == size;
}

bool isStringValid(const char* str)
{
	return str != nullptr;
}
