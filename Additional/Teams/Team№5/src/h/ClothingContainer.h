#pragma once
#include"ClothingItem.h"

class ClothingContainer
{
private:
	ClothingItem** container;
	String* log;
	double* logPrice;
	size_t capacity;
	size_t size;
	size_t logSize;
public:
	ClothingContainer();
	ClothingContainer(const ClothingContainer&);
	ClothingContainer& operator=(const ClothingContainer&);
	~ClothingContainer();

	double getPrice(size_t) const;
	void addClothingItem(ClothingItem&) const;
	bool deleteClothingItem(size_t) const;
	void listAvailableItems() const;
	void listSoldItems() const;
	void exportSoldLog() const;

private:
	void resize();
	void copy(const ClothingContainer&);
	void free();
};
