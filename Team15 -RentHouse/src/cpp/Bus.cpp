#include "Bus.h"

Bus::Bus() : Vehicle()
{
    category = Category::Bus;
    rating = 1;
    hasAC = false;
}

Bus::Bus(const MyString &brand, const MyString &model, const MyString &licensePlate, const size_t yearOfProduction,
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
    std::cout << "Rating: " << rating << "\n"
              << "Has AC: " << hasAC << std::endl;
}

std::ofstream &Bus::save(std::ofstream &ofstr) const
{
    Vehicle::save(ofstr);
    ofstr << 2 << '\n'
          << rating << '\n'
          << hasAC << '\n';

    return ofstr;
}
