#pragma once
#include <fstream>

class ExamString
{
protected:
	char* str;
	size_t size;
public:
	ExamString();
	ExamString(size_t);
	ExamString(const char*);
	ExamString& operator=(const ExamString&);
	~ExamString();

	bool setString(const char*);
	size_t getSize() const;

	const char& operator[](size_t) const;
	char& operator[](size_t);
	virtual ExamString& operator+=(const ExamString&);

	friend std::ostream& operator<<(std::ostream&, const ExamString&);
	friend std::istream& operator>>(std::istream&, ExamString&);
private:
	void copy(const ExamString&);
	void free();

	void toDefaultData();
	void toString(const char*);
};

ExamString operator+(const ExamString&, const ExamString&);
