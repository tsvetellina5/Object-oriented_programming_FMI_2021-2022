#include <iostream>
#include <fstream>
#include "Student.h"
#pragma warning (disable: 4996)

size_t getFileSize(std::ifstream& f)
{
	size_t currentPos = f.tellg();
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size;
}

void readFromFile(Student*& ptr, size_t& studentsCount, std::ifstream& f)
{
	size_t sizeOfFile = getFileSize(f);
	studentsCount = sizeOfFile / sizeof(Student);
	ptr = new Student[studentsCount];
	f.read((char*)ptr, sizeOfFile);
}

bool isNameValid(const char* name)
{
	size_t len = strlen(name);
	return len == 0 || len > MAX_NAME_SIZE;
}

void initStudent(Student& st, const char* name, size_t fn, bool isMale)
{
	if(!isNameValid(name)) {
		strcpy(st.name, "Unknown");
	} else {
		strcpy(st.name, name);
	}

	st.isMale = isMale;
	st.fn = fn;
}

void saveToFile(const Student* students, size_t count, std::ofstream& file)
{
	file.write((const char*)students, count * sizeof(Student));
}

void writeExample()
{
	const size_t studentsCount = 4;
	Student* arr = new Student[studentsCount];
	initStudent(arr[0], "Ivan", 1, true);
	initStudent(arr[1], "Petur", 2, true);
	initStudent(arr[2], "Alex", 3, true);
	initStudent(arr[3], "Katerina", 4, false);

	std::ofstream file("students.dat", std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		delete[] arr;
		return;
	}

	saveToFile(arr, studentsCount, file);

	delete[] arr;
}

void readExample()
{
	Student* arr;
	size_t count;
	std::ifstream file("students.dat");

	if (!file.is_open())
	{
		std::cout << "error while opening the file!" << std::endl;
		return;
	}

	readFromFile(arr, count, file);

	for (size_t i = 0; i < count; i++) {
		std::cout << "name: " << arr[i].name << ", fn: " << arr[i].fn << ", is male: " << arr[i].isMale << std::endl;
	}

	delete[] arr;
}

//int main()
//{
//	writeExample();
//	
//	readExample();
//}