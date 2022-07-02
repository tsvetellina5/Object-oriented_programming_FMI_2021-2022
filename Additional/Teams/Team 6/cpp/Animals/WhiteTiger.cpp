#include "WhiteTiger.h"

WhiteTiger::WhiteTiger() : Tiger()
{}

WhiteTiger::WhiteTiger(const int age, const int weight, const int calories, const String& name, const int speed)
	: Tiger(age, weight, calories, name, speed)
{
	setColoring("Completely white");
}