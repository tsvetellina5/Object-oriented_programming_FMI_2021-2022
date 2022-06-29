#pragma once

#include "Vehicle.h"
#include "Container.h"
#include "Customer.h"
#include "Rent.h"

typedef Container<Vehicle> ListVehicles;
typedef Container<Customer> ListCustomers;
typedef Container<Rent> ListRents;

class RentHouse
{
private:
	ListVehicles vehicles;
	ListCustomers customers;
	ListRents rents;

public:
	bool addCustomer(const MyString &, const MyString &, const MyString &, const MyString &, const MyString &, const MyString &, const MyString &);

	void addCar(const MyString &, const MyString &, const MyString &, const size_t, const size_t, const size_t, const size_t, const bool, const bool);
	void addBus(const MyString &, const MyString &, const MyString &, const size_t, const size_t, const size_t, const size_t, const size_t, const bool);
	void addMotorcycle(const MyString &, const MyString &, const MyString &, const size_t, const size_t, const size_t, const size_t, const bool, const bool);

	void printAllVehicles() const;
	void printAllCustomers() const;
	void printAllRents() const;
	bool printVehiclesByBrand(const MyString &) const;

	bool deleteCustomer(const MyString &);
	bool deleteVechile(const MyString &);

	bool addRent(const MyString &, const MyString &, const Date &, const Date &);
	bool removeRent(const MyString &);
	bool increaseRentalTime(const MyString &, const size_t);
	bool changeOwners(const MyString &, const MyString &);

	void printRentsByStartDate() const;
	void printRentsByEndDate() const;
	bool printAllFreeCars() const;

	friend std::ifstream &operator>>(std::ifstream &, RentHouse &);
	friend std::ofstream &operator<<(std::ofstream &, const RentHouse &);

	bool addVehicles(Vehicle &&);
	bool isLicensePlateUnique(const MyString &);
	bool doesCustomerWithEGNExist(const MyString &);
	bool doesRentWithSameLicenseExist(const MyString &);
};
