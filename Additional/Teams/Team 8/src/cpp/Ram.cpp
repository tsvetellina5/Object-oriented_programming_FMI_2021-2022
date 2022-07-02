#include "Ram.h"

Ram::Ram(const char* manufacturer, const char* model, const double price, const RamType ramType, const size_t memoryCapacity) : Component(manufacturer, model, price, RAM)
{
	this->ramType = ramType;
	this->memoryCapacity = memoryCapacity;
}

RamType Ram::getRamType()
{
	return ramType;
}

size_t Ram::getMemoryCapacity() const
{
	return memoryCapacity;
}

void Ram::showComponentInfo() const
{
	std::cout << "Ram:" << std::endl;
	std::cout << "Manufacturer: " << manufacturer << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Ram Type: " << getRamTypeText(ramType) << std::endl;
	std::cout << "Memory Capacity: " << memoryCapacity << std::endl;
}

void Ram::saveToFile(std::ofstream& file) const
{
	file << "RAM " << manufacturer << " " << model << " " << price << " " << getRamTypeText(ramType) << " " << memoryCapacity << std::endl;
}

Component* Ram::clone() const
{
	return new Ram(*this);
}
