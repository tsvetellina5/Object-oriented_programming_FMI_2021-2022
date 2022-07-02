#pragma once
#include<iostream>
#include "Constants.h"

class String {
private:
	char* str;
	size_t size;
public:
	String();
	String(const char*);
	String(const size_t);
	String(const String&);
	String& operator=(const String&);
	~String();

	void setStr(const char*);
	size_t getSize() const;
	const char* getStr() const;

	void concat(const String&);
	String& operator+=(const String&);
	void getLine(std::istream& outFile);
	char operator[](const size_t);

	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);

private:
	void copy(const String&);
	void free();
};

String operator+(const String& lhs, const String& rhs);
bool operator==(const String& lhs, const String& rhs);
