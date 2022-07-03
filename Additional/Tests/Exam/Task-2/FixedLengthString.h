#pragma once
#include "ExamString.h"

class FixedLengthString : public ExamString
{
public:
	FixedLengthString(size_t);
	FixedLengthString(size_t, const char*);

	FixedLengthString& operator+=(const ExamString&) override;
};