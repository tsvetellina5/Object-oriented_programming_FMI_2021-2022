#include "WhiteLion.h"

WhiteLion::WhiteLion() : Lion()
{}

WhiteLion::WhiteLion(const int age, const int weight, const int calories, const String& name, const int speed)
	: Lion(age, weight, calories, name, speed)
{
	setColoring("Completely white");
}