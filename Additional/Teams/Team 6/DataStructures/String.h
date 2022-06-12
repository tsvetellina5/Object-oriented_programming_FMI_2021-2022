#pragma once
#pragma once
#include <fstream>
#include "Vector.h"

class String
{
	char* str;
	size_t size;

	void copyFrom(const String& other);
	void free();

public:
	String();
	String(const char*);
	String(size_t n);

	String(const String&);

	String(String&&);

	String& operator=(const String& other);
	String& operator=(String&& other);

	~String();

	size_t getSize() const;

	int toInt();
	bool contains(char) const;
	Vector<String> split(const String&);
	Vector<String> split(const char);

	const char* c_str() const;

	friend std::ostream& operator<<(std::ostream& stream, const String& str);
	friend std::istream& operator>>(std::istream& stream, String& str);

};

bool operator==(const String& lhs, const String& rhs);
