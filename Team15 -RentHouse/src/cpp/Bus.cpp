#include "Bus.h"

Bus::Bus() : Vehicle()
{
    category = Category::Bus;
    rating = 1;
    hasAC = false;
}

Bus::Bus(const MyString& brand, const MyString& model, const MyString& licensePlate, const size_t yearOfProduction,
         const size_t seatsCount, const size_t gearbox, const size_t engineType, const size_t rating, const bool hasAC)
    : Vehicle(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType), rating(rating), hasAC(hasAC)
{
    category = Category::Bus;
}

const size_t Bus::getRating() const
{
    return rating;
}
void Bus::setRating(const size_t rating)
{
    this->rating = rating;
}

const bool Bus::getHasAC() const
{
    return hasAC;
}
void Bus::setHasAC(const bool hasAC)
{
    this->hasAC = hasAC;
}

Vehicle *Bus::clone() const
{
    return new Bus(*this);
}

void Bus::print() const
{
    Vehicle::print();
    std::cout << "Rating: " << rating << "; Has AC: " << hasAC << std::endl;
}

// new

std::ifstream &operator>>(std::ifstream &ifstr, Bus &B)
{
    MyString temp;
    ifstr >> temp;
    B.setBrand(temp);
    ifstr >> temp;
    B.setLicensePlate(temp);
    ifstr >> temp;
    B.setModel(temp);
    ifstr >> temp;
    B.setYearOfProduction(temp.convertToInt());
    ifstr >> temp;
    B.setSeatsCount(temp.convertToInt());
    ifstr >> temp;
    // B.setIsRented(temp.convertToInt());
    // ifstr >> temp;
    B.setEngineType(temp.convertToInt());
    ifstr >> temp;
    B.setGearbox(temp.convertToInt());
    ifstr >> temp;
    B.setRating(temp.convertToInt());
    ifstr >> temp;
    B.setHasAC(temp.convertToInt());

    return ifstr;
}

std::ofstream &operator<<(std::ofstream &ofstr, const Bus &B)
{
    MyString newLine("\n");
    ofstr << "2" << newLine;
    ofstr << B.getBrand();
    ofstr << B.getLicensePlate();
    ofstr << B.getModel();
    ofstr << B.getYearOfProduction() << newLine;
    ofstr << B.getSeatsCount() << newLine;
    //    ofstr << B.getIsRented() << newLine;
    ofstr << B.engineType << newLine;
    ofstr << B.gearbox << newLine;
    ofstr << B.rating << newLine;
    ofstr << B.hasAC << newLine;

    return ofstr;
}
