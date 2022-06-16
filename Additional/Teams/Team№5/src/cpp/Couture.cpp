#include "Couture.h"

Couture::Couture(const String& name, const double price, const size_t numAvailable) :ClothingItem(name, price, numAvailable)
{}

void Couture::setDesigner(const String& designer)
{
	this->designer = designer;
}

ClothingItem::Type Couture::getType() const
{
	return ClothingItem::Type::Couture;
}

const char* Couture::typeToStr() const
{
	return "Couture";
}

ClothingItem* Couture::clone() const
{
	return new Couture(*this);
}

void Couture::print() const
{
	ClothingItem::print();
	std::cout << "Designer: " << designer << std::endl;
}
