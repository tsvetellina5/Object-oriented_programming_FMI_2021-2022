#pragma once
#include <fstream>

class MyString
{
	char *str;
	size_t size;

	void copyFrom(const MyString &other);
	void free();

	void concatFrom(const MyString &other);

public:
	MyString();
	MyString(const char *);
	MyString(size_t n);

	MyString(const MyString &);

	MyString(MyString &&);

	MyString &operator=(const MyString &other);
	MyString &operator=(MyString &&other);

	~MyString();

	size_t getSize() const;

	const char *c_str() const;
	MyString *clone() const;
	void getLine(std::istream &);

	MyString &operator+=(const MyString &other);

	friend std::ostream &operator<<(std::ostream &stream, const MyString &str);
	friend std::istream &operator>>(std::istream &stream, MyString &str);
	friend std::ifstream &operator>>(std::ifstream &, MyString &);

	int convertToInt() const;
	bool isOnlyNumbers() const;
	bool isInt() const;

	double convertToDouble() const;
	size_t findDotInDouble() const;
	bool isDouble() const;
	bool isChar(const char) const;

	char *getText() const;
};

MyString operator+(const MyString &lhs, const MyString &rhs);

bool operator==(const MyString &lhs, const MyString &rhs);
bool operator<=(const MyString &lhs, const MyString &rhs);
bool operator<(const MyString &lhs, const MyString &rhs);