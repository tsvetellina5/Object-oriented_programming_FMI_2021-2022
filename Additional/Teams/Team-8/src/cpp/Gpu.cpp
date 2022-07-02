#include "Gpu.h"

Gpu::Gpu(const char* manufacturer, const char* model, const double price, const size_t videoMemory) : Component(manufacturer, model, price, GPU)
{
	this->videoMemory = videoMemory;
}

size_t Gpu::getVideoMemory() const
{
	return videoMemory;
}

void Gpu::showComponentInfo() const
{
	std::cout << "Gpu:" << std::endl;
	std::cout << "Manufacturer: " << manufacturer << std::endl;
	std::cout << "Model: " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Video Memory: " << videoMemory << " GB" << std::endl;
}

void Gpu::saveToFile(std::ofstream& file) const
{
	file << "GPU " << manufacturer << " " << model << " " << price << " " << videoMemory << std::endl;
}

Component* Gpu::clone() const
{
	return new Gpu(*this);
}
