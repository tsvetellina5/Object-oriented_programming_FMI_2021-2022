#include "Car.h"

Car::Car() : Vehicle()
{
    category = Category::Automobile;
    isSportsCar = false;
    isConvertable = false;
}

Car::Car(const MyString &brand, const MyString& model, const MyString &licensePlate, const size_t yearOfProduction,
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
    std::cout << "Is SportsCar: " << isSportsCar << "; Is Convertible: " << isConvertable << std::endl;
}

// new

std::ifstream &operator>>(std::ifstream &ifstr, Car &C)
{
    MyString temp;
    ifstr >> temp;
    C.setBrand(temp);
    ifstr >> temp;
    C.setLicensePlate(temp);
    ifstr >> temp;
    C.setModel(temp);
    ifstr >> temp;
    C.setYearOfProduction(temp.convertToInt());
    ifstr >> temp;
    C.setSeatsCount(temp.convertToInt());
    //    ifstr >> temp;
    //    C.setIsRented(temp.convertToInt());
    ifstr >> temp;
    C.setEngineType(temp.convertToInt());
    ifstr >> temp;
    C.setGearbox(temp.convertToInt());
    ifstr >> temp;
    C.setIsSportsCar(temp.convertToInt());
    ifstr >> temp;
    C.setIsConvertable(temp.convertToInt());

    return ifstr;
}

std::ofstream &operator<<(std::ofstream &ofstr, const Car &C)
{
    MyString newLine("\n");
    ofstr << "1" << newLine;
    ofstr << C.getBrand();
    ofstr << C.getLicensePlate();
    ofstr << C.getModel();
    ofstr << C.getYearOfProduction() << newLine;
    ofstr << C.getSeatsCount() << newLine;
    //    ofstr << C.getIsRented() << newLine;
    ofstr << C.engineType << newLine;
    ofstr << C.gearbox << newLine;
    ofstr << C.isSportsCar << newLine;
    ofstr << C.isConvertable << newLine;

    return ofstr;
}
