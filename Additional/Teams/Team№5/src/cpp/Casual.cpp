#include "Casual.h"

Casual::Casual(const String& name, const double price, const size_t numAvailable) :ClothingItem(name, price, numAvailable)
{}

ClothingItem::Type Casual::getType() const
{
	return ClothingItem::Type::Casual;
}


const char* Casual::typeToStr() const
{
	return "Casual";
}

ClothingItem* Casual::clone() const
{
	return new Casual(*this);
}

String Casual::getData() const
{
	return ClothingItem::getData();
}

void Casual::print() const
{
	ClothingItem::print();
}
