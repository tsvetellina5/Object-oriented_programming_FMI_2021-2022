#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle()
{
    category = Category::Motorcycle;
    doesHaveSideCar = false;
    hasStorageSpace = false;
}

Motorcycle::Motorcycle(const MyString &brand, const MyString &model, const MyString &licensePlate, const size_t yearOfProduction, const size_t seatsCount, const size_t gearbox, const size_t engineType, const bool doesHaveExtraHouse, const bool hasStorageSpace)
    : Vehicle(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType), doesHaveSideCar(doesHaveExtraHouse), hasStorageSpace(hasStorageSpace)
{
    category = Category::Motorcycle;
}

const bool Motorcycle::getDoesHaveSideCar() const
{
    return doesHaveSideCar;
}
const bool Motorcycle::getHasStorageSpace() const
{
    return hasStorageSpace;
}

void Motorcycle::setDoesHaveSideCar(const bool doesHaveExtraHouse)
{
    this->doesHaveSideCar = doesHaveExtraHouse;
}
void Motorcycle::setHasStorageSpace(const bool hasStorageSpace)
{
    this->hasStorageSpace = hasStorageSpace;
}

Vehicle *Motorcycle::clone() const
{
    return new Motorcycle(*this);
}

void Motorcycle::print() const
{
    Vehicle::print();
    std::cout << "Does it have extra house: " << doesHaveSideCar << "\n"
              << "Has storage space: " << hasStorageSpace << std::endl;
}

std::ofstream &Motorcycle::save(std::ofstream &ofstr) const
{
    Vehicle::save(ofstr);
    ofstr << 0 << '\n'
          << doesHaveSideCar << '\n'
          << hasStorageSpace << '\n';

    return ofstr;
}
