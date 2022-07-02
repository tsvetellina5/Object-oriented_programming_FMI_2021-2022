#include "Car.h"

Car::Car() : Vehicle()
{
    category = Category::Automobile;
    isSportsCar = false;
    isConvertable = false;
}

Car::Car(const MyString &brand, const MyString &model, const MyString &licensePlate, const size_t yearOfProduction,
         const size_t seatsCount, const size_t gearbox, const size_t engineType, const bool isSportsCar, const bool isConvertable)

    : Vehicle(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType),
      isSportsCar(isSportsCar), isConvertable(isConvertable)
{
    category = Category::Automobile;
}

const bool Car::getIsSportsCar() const
{
    return isSportsCar;
}
const bool Car::getIsConvertable() const
{
    return isConvertable;
}

void Car::setIsSportsCar(const bool isSportsCar)
{
    this->isSportsCar = isSportsCar;
}
void Car::setIsConvertable(const bool isConvertable)
{
    this->isConvertable = isConvertable;
}

Vehicle *Car::clone() const
{
    return new Car(*this);
}

void Car::print() const
{
    Vehicle::print();
    std::cout << "Is SportsCar: " << isSportsCar << "\n"
              << "Is Convertible: " << isConvertable << std::endl;
}

std::ofstream &Car::save(std::ofstream &ofstr) const
{
    Vehicle::save(ofstr);
    ofstr << 1 << '\n'
          << isSportsCar << '\n'
          << isConvertable << '\n';

    return ofstr;
}
