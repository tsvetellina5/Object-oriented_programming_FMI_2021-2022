#pragma once
#include <fstream>

class String
{
	char* str;
	size_t size;

	void copyFrom(const String& other);
	void free();
	void concatFrom(const String& other);

public:
	String();
	String(const char*);
	String(const String&);
	String(size_t n);

	String& operator=(const String& other);

	~String();

	size_t getSize() const;

	const char* c_str() const;

	bool compare(const String& string) const {
		return strcmp(this->str, string.str) == 0;
	}

	String& operator+=(const String& other);

	friend std::ostream& operator<<(std::ostream& stream, const String& str);
	friend std::istream& operator>>(std::istream& stream, String& str);

};

String operator+(const String& lhs, const String& rhs);

bool operator==(const String& lhs, const String& rhs);