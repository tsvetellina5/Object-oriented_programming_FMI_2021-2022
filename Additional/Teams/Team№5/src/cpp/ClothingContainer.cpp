#include"ClothingContainer.h"
#include<fstream>


ClothingContainer::ClothingContainer()
{
	capacityContainer = 2;
	capacityLog = 2;
	size = 0;
	logSize = 0;
	container = new ClothingItem * [capacityContainer];
	log = new String[capacityLog];
	logPrice = new double[capacityLog];
}

ClothingContainer::ClothingContainer(const ClothingContainer& other)
{
	copy(other);
}

ClothingContainer& ClothingContainer::operator=(const ClothingContainer& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

ClothingContainer::~ClothingContainer()
{
	free();
}

double ClothingContainer::getPrice(size_t index) const
{
	return container[index]->getPrice();
}

void ClothingContainer::addClothingItem(const ClothingItem& item) const
{

	for (size_t i = 0; i < size; i++)
	{
		if (container[i]->getName() == item.getName() && container[i]->getSize() == item.getSize() && container[i]->getGender() == item.getGender())
		{
			container[i]->setNumAvailable(container[i]->getNumAvailable() + item.getNumAvailable());
			return;
		}
	}
	if (size >= capacityContainer)
	{
		resizeContainer();
	}

	container[size++] = item.clone();
}

bool ClothingContainer::deleteClothingItem(size_t index) const
{
	if (index >= size)
	{
		return false;
	}

	if (logSize >= capacity)
	{
		resizeLog();
	}
	log[logSize] = container[index]->getData();
	logPrice[logSize++] = container[index]->getPrice();

	if (container[index]->getNumAvailable() > 1)
	{
		container[index]->setNumAvailable(container[index]->getNumAvailable() - 1);
		return true;
	}

	delete container[index];
	container[index] = container[size - 1];
	container[size - 1] = nullptr;
	size--;

	return true;
}

void ClothingContainer::listAvailableItems() const
{
	for (size_t i = 0; i < size; i++)
	{
		container[i]->print();
	}
}

void ClothingContainer::listSoldItems() const
{
	for (size_t i = 0; i < logSize; i++)
	{
		std::cout << log[i] << "\nPrice: " << logPrice[i] << std::endl;
	}
}

void ClothingContainer::exportSoldLog() const
{
	std::ofstream writeFile("logFile.txt", std::ios::app);
	for (size_t i = 0; i < logSize; i++)
	{
		writeFile << log[i] << "\nPrice: " << logPrice[i] << std::endl;
	}
}

void ClothingContainer::resizeContainer()
{
	ClothingItem** tempCont = new ClothingItem * [capacityContainer *= 2];
	for (size_t i = 0; i < size; i++)
	{
		tempCont[i] = container[i];
	}

	delete[] container;

	container = tempCont;
	
	tempCont = nullptr;
	
}
void ClothingContainer::resizeLog()
{
	String* tempLog = new String[capacityLog *= 2];
	double tempLogPrice = new double[capacityLog];
	for (size_t i = 0; i < logSize; i++)
	{
		tempLog[i] = log[i];
		tempLogPrice[i] = logPrice[i];
	}
	delete[] log;
	delete[] logPrice;
	log = tempLog;
	logPrice = tempLogPrice;
	tempLog = nullptr;
	tempLogPrice = nullptr;
}
void ClothingContainer::copy(const ClothingContainer& other)
{
	capacityContainer = other.capacityContainer;
	capacityLog = other.capacityLog;
	size = other.size;
	logSize = other.logSize;
	container = new ClothingItem * [capacityContainer];
	log = new String[capacityLog];
	logPrice = new double[capacityLog];

	for (size_t i = 0; i < size; i++)
	{
		container[i] = other.container[i]->clone();
	}

	for (size_t i = 0; i < logSize; i++)
	{
		log[i] = other.log[i];
		logPrice[i] = other.logPrice[i];
	}
}

void ClothingContainer::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete container[i];
	}

	delete[] container;
	delete[] log;
	delete[] logPrice;
}
