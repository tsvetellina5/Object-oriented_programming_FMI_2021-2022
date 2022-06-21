#include"ClothingItem.h"

ClothingItem::ClothingItem() : name(), price(0), numAvailable(0) {}
ClothingItem::ClothingItem(const String& name, const double price, const size_t numAvailable) : name(name), price(price), numAvailable(numAvailable) {}

void ClothingItem::setName(const String& name)
{
	this->name = name;
}
void ClothingItem::setPrice(const double price)
{
	this->price = price;
}
void ClothingItem::setNumAvailable(const size_t numAvailable)
{
	this->numAvailable = numAvailable;
}
void ClothingItem::setGender(const char& gender)
{
	if (gender == 'M' || gender == 'm')
		this->gender = Gender::MAN;

	else if (gender == 'W' || gender == 'w')
		this->gender = Gender::WOMAN;

	else if (gender == 'U' || gender == 'u')
		this->gender = Gender::UNISEX;
	else
		throw "Invalid data";
}
void ClothingItem::setSize(const String& size)
{
	if (size == "XS" || size == "xs")
		this->size = Size::XS;

	else if (size == "S" || size == "s")
		this->size = Size::S;

	else if (size == "M" || size == "m")
		this->size = Size::M;

	else if (size == "L" || size == "l")
		this->size = Size::L;

	else if (size == "XL" || size == "xl")
		this->size = Size::XL;

	else if (size == "XXL" || size == "xxl")
		this->size = Size::XXL;

	else
		this->size = Size::UNKNOWN;
}
ClothingItem::Type ClothingItem::getType() const
{
	return Type::UNKNOWN;
}
ClothingItem::Gender ClothingItem::getGender() const
{
	return gender;
}
ClothingItem::Size ClothingItem::getSize() const
{
	return size;
}
const String& ClothingItem::getName() const
{
	return name;
}
double ClothingItem::getPrice() const
{
	return price;
}
size_t ClothingItem::getNumAvailable() const
{
	return numAvailable;
}
const char* ClothingItem::typeToStr() const
{
	return "Unknown";
}
const char* ClothingItem::sizeToStr() const
{
	switch (size)
	{
	case ClothingItem::Size::XS:
		return "XS";
	case ClothingItem::Size::S:
		return "S";
	case ClothingItem::Size::M:
		return "M";
	case ClothingItem::Size::L:
		return "L";
	case ClothingItem::Size::XL:
		return "XL";
	case ClothingItem::Size::XXL:
		return "XXL";
	case ClothingItem::Size::UNKNOWN:
		return "Unknown";
	default:
		return "Unknown";
	}
}
const char* ClothingItem::genderToStr() const
{
	if(gender == Gender::MAN)
		return "Man";
	else if (gender == Gender::WOMAN)
		return "Woman";
	else if (gender == Gender::UNISEX)
		return "Unisex";
	else
		throw "Invalid data";
}
String ClothingItem::getData() const
{
	return ("\nName: " + name + "\nSize: " + sizeToStr() + "\nType: " + typeToStr() + "\nGender: " + genderToStr());
}
void ClothingItem::print() const
{
	std::cout << getData();
	std::cout << "\nPrice: " << price << std::endl << "Number available: " << numAvailable << std::endl;
}
