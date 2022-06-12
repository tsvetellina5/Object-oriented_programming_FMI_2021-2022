#pragma once
#include "String.h"

class Log
{
	String data;

public:

	void setData(const String& data)
	{
		this->data = data;
	}
	String getData() const
	{
		return data;
	}
};