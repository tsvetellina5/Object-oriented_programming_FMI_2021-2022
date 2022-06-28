#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle()
{
    seatsCount = 0;
    yearOfProduction = 2000;
    gearbox = Vehicle::Gearbox::UnknownGearbox;
    engineType = Vehicle::EngineType::UnknownEngineType;
    category = Vehicle::Category::UnknownVehicleType;
}

Vehicle::Vehicle(const MyString &brand, const MyString &model, const MyString &licensePlate,
                 const size_t yearOfProduction, const size_t seatsCount, const size_t gearbox, const size_t engineType)
{
    setBrand(brand);
    setModel(model);
    setLicensePlate(licensePlate);
    setYearOfProduction(yearOfProduction);
    setSeatsCount(seatsCount);
    setGearbox(gearbox);
    setEngineType(engineType);
}

void Vehicle::setBrand(const MyString &brand)
{
    this->brand = brand;
}

void Vehicle::setLicensePlate(const MyString &licensePlate)
{
    this->licensePlate = licensePlate;
}

void Vehicle::setYearOfProduction(const size_t yearOfProduction)
{
    this->yearOfProduction = yearOfProduction;
}

void Vehicle::setSeatsCount(const size_t seatsCount)
{
    this->seatsCount = seatsCount;
}

void Vehicle::setModel(const MyString &model)
{
    this->model = model;
}

void Vehicle::setEngineType(const size_t index)
{
    engineType = (EngineType)index;
}

void Vehicle::setGearbox(const size_t index)
{
    gearbox = (Gearbox)index;
}

const MyString &Vehicle::getBrand() const
{
    return brand;
}

const MyString &Vehicle::getLicensePlate() const
{
    return licensePlate;
}

size_t Vehicle::getYearOfProduction() const
{
    return yearOfProduction;
}

size_t Vehicle::getSeatsCount() const
{
    return seatsCount;
}

const MyString &Vehicle::getModel() const
{
    return model;
}

const Vehicle::Category &Vehicle::getCategory() const
{
    return category;
}

const Vehicle::Gearbox &Vehicle::getGearbox() const
{
    return gearbox;
}

const Vehicle::EngineType &Vehicle::getEngineType() const
{
    return engineType;
}

bool Vehicle::isVehicleNew()
{
    const size_t newYear = 2010;
    return yearOfProduction >= newYear;
}

void Vehicle::print() const
{
    std::cout << "License plate: " << licensePlate
              << "Brand: " << brand
              << "Model: " << model
              << "Year of production: " << yearOfProduction << "\n"
              << "Number of seats: " << seatsCount << "\n";
}

std::ofstream &Vehicle::save(std::ofstream &ofstr) const
{
    ofstr << brand << model << licensePlate;
    ofstr << yearOfProduction << '\n'
          << seatsCount << '\n'
          << gearbox << '\n'
          << engineType << '\n';

    return ofstr;
}

std::ifstream &Vehicle::get(std::ifstream &ifstr)
{
    ifstr >> brand >> model >> licensePlate >> yearOfProduction >> seatsCount;

    return ifstr;
}
