#include <iostream>
#include <fstream>

const int MAX_SIZE = 1024;

int main()
{
	std::ifstream inputFile("task1.cpp"); //open file to read
	
	if (!inputFile.is_open()) //if file was not found/did not open
	{
		std::cout << "Error!" << std::endl;
		return -1; //end program
	}
	
	while (!inputFile.eof()) //Loop till end of file
	{
		char buffer[MAX_SIZE];
		inputFile.getline(buffer, MAX_SIZE); //store line in buffer
		std::cout << buffer << std::endl; //print line by line in console/terminal
	}
	
	inputFile.close(); //no further actions with the file = close file
	return 0;
}
