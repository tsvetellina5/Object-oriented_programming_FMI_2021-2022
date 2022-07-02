#include "Cpu.h"

Cpu::Cpu(const char* manufacturer, const char* model, const double price, const Socket socket, const size_t cores) : Component(manufacturer, model, price, CPU)
{
	this->socket = socket;
	this->cores = cores;
}

Socket Cpu::getSocket() const
{
	return socket;
}

size_t Cpu::getCores() const
{
	return cores;
}

void Cpu::showComponentInfo() const
{
	std::cout << "Cpu:" << std::endl;
	std::cout << "Manufacturer: " << manufacturer << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Socket: " << getSocketTypeText(socket) << std::endl;
	std::cout << "Cores: " << cores << std::endl;
}

void Cpu::saveToFile(std::ofstream& file) const
{
	file << "CPU " << manufacturer << " " << model << " " << price << " " << getSocketTypeText(socket) << " " << cores << std::endl;
}

Component* Cpu::clone() const
{
	return new Cpu(*this);
}
