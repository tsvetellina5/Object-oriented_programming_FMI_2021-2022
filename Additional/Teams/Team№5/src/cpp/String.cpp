#include"String.h"
#include<cstring>
#pragma warning (disable: 4996)

void String::copy(const String& other)
{
	this->size = other.size;
	str = new char[size + 1];
	strcpy(str, other.str);
}
void String::free()
{
	delete[] str;
}

String::String()
{
	size = 0;
	str = new char[1];
	str[0] = '\0';
}
String::String(const size_t size)
{
	this->size = size;
	str = new char[size + 1];
	str[size] = '\0';
}
String::String(const char* data)
{
	size = strlen(data);
	str = new char[size + 1];
	strcpy(str, data);
}
String::String(const String& other)
{
	copy(other);
}
String& String::operator=(const String& other)
{
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}
String::~String()
{
	free();
}

void String::setStr(const char* data)
{
	delete[] str;
	size = strlen(data);
	str = new char[size + 1];
	strcpy(str, data);
}
size_t String::getSize() const
{
	return size;
}
const char* String::getStr() const
{
	return str;
}

void String::concat(const String& other)
{
	size = size + other.size;
	char* temp = new char[size + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
}

String& String::operator+=(const String& other)
{
	concat(other.str);
	return *this;
}
void String::getLine(std::istream& outFile)
{
	delete[] str;
	char buff[BUFF_SIZE];

	outFile.getline(buff, BUFF_SIZE, '\n');
	size_t len = strlen(buff);
	str = new char[len + 1];
	for (size_t i = 0; i < len; i++)
		str[i] = buff[i];
	str[len] = '\0';
	size = len;
}
char String::operator[](const size_t index)
{
	if (index < 0 || index >= size)
		throw "Invalid index";

	return str[index];
}

std::ostream& operator<<(std::ostream& out, const String& obj)
{
	out << obj.str;
	return out;
}
std::istream& operator>>(std::istream& in, String& obj)
{
	char buffer[BUFF_SIZE];
	in >> buffer;

	obj.free();
	obj.size = strlen(buffer);
	obj.str = new char[obj.size + 1];
	strcpy(obj.str, buffer);

	return in;
}

String operator+(const String& lhs, const String& rhs)
{
	String temp(lhs);
	temp += rhs;
	return temp;
}

bool operator==(const String& lhs, const String& rhs) {
	return strcmp(lhs.getStr(), rhs.getStr()) == 0;
}
