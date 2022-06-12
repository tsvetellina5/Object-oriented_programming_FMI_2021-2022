#include"ClothingContainer.h"
#include<fstream>


ClothingContainer::ClothingContainer()
{
	capacity = 2;
	size = 0;
	logSize = 0;
	container = new ClothingItem * [capacity];
	log = new String[capacity];
	logPrice = new double[capacity];
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

double ClothingContainer::getPrice(size_t index)
{
	return container[index]->getPrice();
}

void ClothingContainer::AddClothingItem(ClothingItem& item)
{
	if (size >= capacity)
	{
		resize();
	}

	for (size_t i = 0; i < size; i++)
	{
		if (container[i]->getName() == item.getName() && container[i]->getSize() == item.getSize() && container[i]->getGender() == item.getGender())
		{
			container[i]->setNumAvailable(container[i]->getNumAvailable() + item.getNumAvailable());
			return;
		}
	}

	container[size++] = item.clone();
}

bool ClothingContainer::DeleteClothingItem(size_t index)
{
	if (index >= size)
	{
		return false;
	}

	if (logSize >= capacity)
	{
		resize();
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

void ClothingContainer::ListAvailableItems()
{
	for (size_t i = 0; i < size; i++)
	{
		container[i]->print();
	}
}

void ClothingContainer::ListSoldItems()
{
	for (size_t i = 0; i < logSize; i++)
	{
		std::cout << log[i] << "\nPrice: " << logPrice[i] << std::endl;
	}
}

void ClothingContainer::ExportSoldLog()
{
	std::ofstream writeFile("logFile.txt", std::ios::app);
	for (size_t i = 0; i < logSize; i++)
	{
		writeFile << log[i] << "\nPrice: " << logPrice[i] << std::endl;
	}
}

void ClothingContainer::resize()
{
	ClothingItem** tempCont = new ClothingItem * [capacity * 2];
	String* tempLog = new String[capacity * 2];
	double* tempLogPrice = new double[capacity * 2];

	for (size_t i = 0; i < size; i++)
	{
		tempCont[i] = container[i];
		tempLog[i] = log[i];
		tempLogPrice[i] = logPrice[i];
	}

	delete[] container;
	delete[] log;
	delete[] logPrice;
	container = tempCont;
	log = tempLog;
	logPrice = tempLogPrice;
	tempCont = nullptr;
	tempLog = nullptr;
	tempLogPrice = nullptr;
}

void ClothingContainer::copy(const ClothingContainer& other)
{
	capacity = other.capacity;
	size = other.size;
	logSize = other.logSize;
	container = new ClothingItem * [capacity];
	log = new String[capacity];
	logPrice = new double[capacity];

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
