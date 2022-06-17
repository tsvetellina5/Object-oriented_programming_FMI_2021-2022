#include"String.h"
#include"ClothingItem.h"
#include"ClothingContainer.h"
#include<iostream>

class Shop {
private:
	String shopName;
	String address;
	double profit;
	ClothingContainer listOfClothes;
public:
	Shop();

	const String& getName() const;
	const String& getAddress() const;
	double getProfit() const;

	void setName(const String&);
	void setAddress(const String&);
	void addToProfit(const double);

	void displayMenu();
	
private:
	void displayAddDialog() const;
	void displayListDialog() const;
	void displaySellDialog() const;
	void displayShopInfo() const;
};
