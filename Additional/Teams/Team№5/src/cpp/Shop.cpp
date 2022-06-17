#include"Shop.h"
#include"Casual.h"
#include"Couture.h"
#include"SportsWear.h"

Shop::Shop()
{
	profit = 0;

}
const String& Shop::getName() const
{
	return shopName;
}
const String& Shop::getAddress() const
{
	return address;
}
double Shop::getProfit() const
{
	return profit;
}

void Shop::setName(const String& name)
{
	shopName = name;
}
void Shop::setAddress(const String& address)
{
	this->address = address;
}
void Shop::addToProfit(const double profit)
{
	this->profit = this->profit + profit;
}

void Shop::displayShopInfo() const
{
	std::cout << "Shop: " << getName() << std::endl
		<< "Adddress: " << getAddress() << std::endl
		<< "Profit: " << getProfit() << std::endl;
}
void Shop::displayAddDialog() const
{
	std::cout << "Name of piece of clothing: \n>";
	String name;
	std::cin >> name;
	std::cout << "Gender (M for Man, W for Woman, U for Unisex: \n>";
	char gender;
	std::cin >> gender;
	std::cout << "Size (XS-XXL or O for Other): \n>";
	String size;
	std::cin >> size;
	std::cout << "Type (C for Casual, S for SportsWear, D for Couture/Designer): \n>";
	char type;
	std::cin >> type;
	std::cout << "Price: \n>";
	double price;
	std::cin >> price;
	if (price <= 0) {
		throw "Invalid value";
		return;
	}
	std::cout << "Count to add (number > 0): \n>";
	size_t countToAdd;
	std::cin >> countToAdd;

	if (type == 'c' || type == 'C')
	{
		Casual item(name, price, countToAdd);
		item.setGender(gender);
		item.setSize(size);
		listOfClothes.AddClothingItem(item);
	}

	if (type == 's' || type == 'S')
	{
		SportsWear item(name, price, countToAdd);
		item.setGender(gender);
		item.setSize(size);
		
		std::cout << "Sport: \n>";
		String sport;
		std::cin >> sport;
		item.setSport(sport);
		listOfClothes.AddClothingItem(item);
	}

	if (type == 'd' || type == 'D')
	{
		Couture item(name, price, countToAdd);
		item.setGender(gender);
		item.setSize(size);

		std::cout << "Designer: \n>";
		String designer;
		std::cin >> designer;
		item.setDesigner(designer);
		listOfClothes.AddClothingItem(item);
	}
}
void Shop::displayListDialog() const
{
	char command;
	std::cout << "Choose whether you want to: " << std::endl;
	std::cout << " a. List available items" << std::endl;
	std::cout << " b. List sold items" << std::endl;

	std::cout << "Write down your choice (a /b )" << std::endl;
	std::cout << ">";
	std::cin >> command;

	if (command == 'a' || command == 'A') {
		listOfClothes.ListAvailableItems();
	}
	else if (command == 'b' || command == 'B') {
		listOfClothes.ListSoldItems();
	}
	else {
		std::cout << "Invalid command!" << std::endl;
	}
}
void Shop::displaySellDialog() const
{
	size_t index;
	std::cout << "Write down the index of the clothing item you sold: ";
	std::cin >> index;
	addToProfit(listOfClothes.getPrice(index));
	listOfClothes.DeleteClothingItem(index);
}
void Shop::displayMenu()
{
	std::cout << "Welcome!" << std::endl;
	String cmd;
	while (!(cmd == "quit" || cmd == "Quit")) {
		std::cout <<  " You can choose one of the following options : " << std::endl;
		std::cout << " 1. Add" << std::endl;
		std::cout << " 2. Sell" << std::endl;
		std::cout << " 3. List" << std::endl;
		std::cout << " 4. Export sells report(log)" << std::endl;
		std::cout << " 5. Display info about the shop" << std::endl;
		std::cout << " 6. Quit" << std::endl;

		std::cout << "Write down your command: " << std::endl;
		std::cout << ">";
		std::cin >> cmd;

		if (cmd == "add" || cmd == "Add") {
			displayAddDialog();
		}
		else if (cmd == "sell" || cmd == "Sell") {
			displaySellDialog();
		}
		else if (cmd == "list" || cmd == "List") {
			displayListDialog();
		}
		else if (cmd == "export" || cmd == "Export") {
			listOfClothes.exportSoldLog();
		}
		else if (cmd == "display" || cmd == "Display") {
			displayShopInfo();
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}
}
