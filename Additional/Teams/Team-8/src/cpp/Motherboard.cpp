#include "Motherboard.h"

Motherboard::Motherboard(const char* manufacturer, const char* model, const double price, const Socket socket, const RamType ramType) : Component(manufacturer, model, price, MOTHERBOARD)
{
	this->socket = socket;
	this->ramType = ramType;
}

Socket Motherboard::getSocket() const
{
	return socket;
}

RamType Motherboard::getRamType() const
{
	return ramType;
}

void Motherboard::showComponentInfo() const
{
	std::cout << "Motherboard:" << std::endl;
	std::cout << "Manufacturer: " << manufacturer << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Socket: " << getSocketTypeText(socket) << std::endl;
	std::cout << "Ram Type: " << getRamTypeText(ramType) << std::endl;
}

void Motherboard::saveToFile(std::ofstream& file) const
{
	file << "Motherboard " << manufacturer << " " << model << " " << price << " " << getSocketTypeText(socket) << " " << getRamTypeText(ramType) << std::endl;
}

Component* Motherboard::clone() const
{
	return new Motherboard(*this);
}
