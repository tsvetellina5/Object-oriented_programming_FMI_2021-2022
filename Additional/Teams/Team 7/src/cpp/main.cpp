#include "Zoopark.h"
#include <iostream>
using namespace std;

const int BUFFER_SIZE = 1024;

int main()
{
	cout << "What is the name of the zoopark? ";
	char name[BUFFER_SIZE];
	std::cin.getline(name, BUFFER_SIZE);
	Zoopark zoopark(name);

	zoopark.menu();
}
