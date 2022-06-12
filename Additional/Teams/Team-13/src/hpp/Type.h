#ifndef TYPE_H
#define TYPE_H

#include "String.h"

enum class Type
{
	soup,
	salad,
	pastry,
	stew,
	steak,
	sandwitch,
	dessert,
	unknown
};

Type stringToType(const MyString& other);
MyString typeToString(const Type& other);

#endif