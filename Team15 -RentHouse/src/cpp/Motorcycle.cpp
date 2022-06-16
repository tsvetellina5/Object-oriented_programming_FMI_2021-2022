#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle()
{
    category = Category::Motorcycle;
    doesHaveExtraHouse = false;
    hasStorageSpace = false;
}

Motorcycle::Motorcycle(const MyString &brand, const MyString &licensePlate, const size_t yearOfProduction, const size_t seatsCount, const bool doesHaveExtraHouse, const bool hasStorageSpace)
    : Vehicle(brand, licensePlate, yearOfProduction, seatsCount), doesHaveExtraHouse(doesHaveExtraHouse), hasStorageSpace(hasStorageSpace)
{
    category = Category::Motorcycle;
}

const bool Motorcycle::getDoesHaveExtraHouse() const
{
    return doesHaveExtraHouse;
}
const bool Motorcycle::getHasStorageSpace() const
{
    return hasStorageSpace;
}

void Motorcycle::setDoesHaveExtraHouse(const bool doesHaveExtraHouse)
{
    this->doesHaveExtraHouse = doesHaveExtraHouse;
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
    std::cout << "Does it have extra house: " << doesHaveExtraHouse << "; Has storage space: " << hasStorageSpace << std::endl;
}

// new

std::ofstream &operator<<(std::ofstream &ofstr, const Motorcycle &M)
{
    MyString newLine("\n");
    ofstr << "0" << newLine;
    ofstr << M.getBrand();
    ofstr << M.getLicensePlate();
    ofstr << M.getModel();
    ofstr << M.getYearOfProduction() << newLine;
    ofstr << M.getSeatsCount() << newLine;
//    ofstr << M.getIsRented() << newLine;
    ofstr << M.engineType << newLine;
    ofstr << M.gearbox << newLine;
    ofstr << M.doesHaveExtraHouse << newLine;
    ofstr << M.hasStorageSpace << newLine;

    return ofstr;
}

std::ifstream &operator>>(std::ifstream &ifstr, Motorcycle &M)
{
    MyString temp;
    ifstr >> temp;
    M.setBrand(temp);
    ifstr >> temp;
    M.setLicensePlate(temp);
    ifstr >> temp;
    M.setModel(temp);
    ifstr >> temp;
    M.setYearOfProduction(temp.convertToInt());
    ifstr >> temp;
    M.setSeatsCount(temp.convertToInt());
//    ifstr >> temp;
//    M.setIsRented(temp.convertToInt());
    ifstr >> temp;
    M.setEngineType(temp.convertToInt());
    ifstr >> temp;
    M.setGearbox(temp.convertToInt());
    ifstr >> temp;
    M.setDoesHaveExtraHouse(temp.convertToInt());
    ifstr >> temp;
    M.setHasStorageSpace(temp.convertToInt());

    return ifstr;
}
