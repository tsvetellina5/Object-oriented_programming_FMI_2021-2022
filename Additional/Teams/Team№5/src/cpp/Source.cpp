#include"Shop.h"
#include"String.h"
#include<iostream>

int main() {
	Shop shop;
	String name;
	String address;
	std::cout << "Add shop name: " << std::endl;
	std::cin >> name;
	shop.setName(name);

	std::cout << "Add shop address: " << std::endl;
	std::cin >> address;
	shop.setAddress(address);

	shop.displayMenu();

	return 0;
}
