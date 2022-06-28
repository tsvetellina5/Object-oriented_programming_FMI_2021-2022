#include "../h/Container.h"

Container::Container() {
	data = nullptr;
	capacity = size = 0;
}

Container::Container(const Container& other) {
	copy(other);
}

Container::Container(Container&& other) {
	move(std::move(other));
}

Container& Container::operator=(const Container& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Container& Container::operator=(Container&& other) {
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

Container::~Container() {
	free();
}

size_t Container::getSize() const {
	return size;
}

size_t Container::getCapacity() const {
	return capacity;
}

void Container::pushBack(const Vehicle* element) {
	if (size + 1 > capacity)
		resize(size + 1);

	data[size++] = element -> clone();
}

void Container::pushAt(const Vehicle* element, const size_t index) {
	if (size + 1 > capacity)
		resize(size + 1);

	for (size_t i = size; i > index; i--)
		data[i] = data[i - 1];

	data[index] = element -> clone();
	size++;
}

Vehicle* Container::popBack() {
	if (empty())
		throw "Container is empty";

	return data[--size];
}

Vehicle* Container::popAt(size_t index) {
	if (index < 0 || index >= size)
		throw "Invalid index";

	Vehicle *temp = data[index];
	for (size_t i = index; i < size - 1; i++)
		data[i] = data[i + 1];

	size--;
	return temp;
}

Vehicle* Container::operator[](const size_t index) {
	if (index < 0 || index >= size)
		throw "Invalid index";

	return data[index];
}

const Vehicle* Container::operator[](const size_t index) const {
	if (index < 0 || index >= size)
		throw "Invalid index";

	return data[index];
}

bool Container::empty() const {
	return size == 0;
}

void Container::clear() {
	for(size_t i = 0; i < size; i++)
		delete data[i];
	delete[] data;
	capacity = DEFAULT_CAPACITY_CONTAINER;
	data = new Vehicle*[capacity];
	size = 0;
}

void Container::copy(const Container& other) {
	size = other.size;
	capacity = other.capacity;
	data = new Vehicle*[capacity];

	for (size_t i = 0; i < size; i++)
		data[i] = other[i] -> clone();
}


void Container::free() {
	for(size_t i = 0; i < size; i++)
		delete data[i];
	delete[] data;
	data = nullptr;
	capacity = size = 0;
}


void Container::move(Container&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.capacity = other.size = 0;
}

size_t Container::calculateCapacity(const size_t number) const {
	size_t result = DEFAULT_CAPACITY_CONTAINER;
	while (number > result)
		result *= 2;

	return result;
}


void Container::resize(const size_t expectedCapacityToFit) {
	capacity = calculateCapacity(expectedCapacityToFit);
	Vehicle** temp = new Vehicle*[capacity];

	for (size_t i = 0; i < size; i++)
		temp[i] = data[i];

	delete[] data;
	data = temp;
}