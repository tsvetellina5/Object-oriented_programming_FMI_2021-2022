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

	String getName() const;
	String getAddress() const;
	double getProfit() const;

	void setName(const String&);
	void setAddress(const String&);
	void addToProfit(const double);

	void displayMenu();
	
private:
	void diplayAddDialog();
	void displayListDialog();
	void displaySellDialog();
	void displayShopInfo() const;
};
