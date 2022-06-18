#include "RentHouse.h"

#include "Car.h"
#include "Bus.h"
#include "Motorcycle.h"

bool RentHouse::addVehicles(Vehicle &&vechile)
{
	if (isLicensePlateUnique(vechile.getLicensePlate()))
	{
		vehicles.addElemenet(vechile);
		return true;
	}
	return false;
}

void RentHouse::addCar(const MyString& brand, const MyString& model,
					   const MyString& licensePlate, const size_t yearOfProduction,
						const size_t gearbox, const size_t engineType,
					   const size_t seatsCount, const bool isSportsCar,
					   const bool isConvertable)
{
	addVehicles(Car(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType, isSportsCar, isConvertable));
}

void RentHouse::addBus(const MyString &brand, const MyString &model,
					   const MyString &licensePlate, const size_t yearOfProduction,
						const size_t gearbox, const size_t engineType,
					   const size_t seatsCount, const size_t rating, const bool hasAC)
{
	addVehicles(Bus(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType, rating, hasAC));
}

void RentHouse::addMotorcycle(const MyString &brand, const MyString &model,
							  const MyString &licensePlate, const size_t yearOfProduction,
							const size_t gearbox, const size_t engineType,
							  const size_t seatsCount, const bool doesHaveExtraHouse,
							  const bool hasStorageSpace)
{
	addVehicles(Motorcycle(brand, model,  licensePlate, yearOfProduction,
						   seatsCount, gearbox, engineType, doesHaveExtraHouse, hasStorageSpace));
}

bool RentHouse::addCustomer(const MyString &name, const MyString &email,
							const MyString &EGN, const MyString &city, const MyString &phone,
							const MyString &username, const MyString &password)
{
	if (doesCustomerWithEGNExist(EGN))
	{
		return false;
	}

	Customer customer(name, email, EGN, city, phone, username, password);
	customers.addElemenet(customer);

	return true;
}

bool RentHouse::isLicensePlateUnique(const MyString &plate)
{
	for (size_t i = 0; i < vehicles.getCount(); i++)
	{
		if (plate == vehicles[i]->getLicensePlate())
		{
			return false;
		}
	}
	return true;
}

void RentHouse::printAllVehicles() const
{
	std::cout << "Number of vehicles: " << vehicles.getCount() << std::endl;
	for (size_t i = 0; i < vehicles.getCount(); i++)
	{
		vehicles[i]->print();
	}
}

void RentHouse::printAllCustomers() const
{
	std::cout << "Number of customers: " << customers.getCount() << std::endl;
	for (size_t i = 0; i < customers.getCount(); i++)
	{
		customers[i]->print();
	}
}

std::ifstream &operator>>(std::ifstream &ifstr, RentHouse &RH)
{
	
	return ifstr;
}

std::ofstream &operator<<(std::ofstream &ofstr, const RentHouse &RH)
{
	MyString newLine("\n");
	size_t carsCount = RH.vehicles.getCount();
	ofstr << carsCount << newLine;
	for (size_t i = 0; i < carsCount; i++)
	{
		ofstr << RH.vehicles[i];
	}

	size_t customersCount = RH.customers.getCount();
	ofstr << customersCount << newLine;
	for (size_t i = 0; i < customersCount; i++)
	{
		ofstr << RH.customers[i];
	}
	/*
	size_t rentsCount = RH.rents.getCount();
	ofstr << rentsCount << newLine;
	for (size_t i = 0; i < rentsCount; i++)
	{
		ofstr << RH.rents[i];
	}
	*/
	return ofstr;
}

bool RentHouse::printVehiclesByBrand(const MyString &brand) const
{
	bool doesBrandExist = false;
	for (size_t i = 0; i < vehicles.getCount(); i++)
	{
		if (vehicles[i]->getBrand() == brand)
		{
			doesBrandExist = true;
		}
	}

	if (!doesBrandExist)
	{
		return false;
	}

	std::cout << "Vehicles made by " << brand << std::endl;
	for (size_t i = 0; i < vehicles.getCount(); i++)
	{
		if (vehicles[i]->getBrand() == brand)
		{
			vehicles[i]->print();
		}
	}
	return true;
}

bool RentHouse::deleteCustomer(const MyString &EGN)
{
	if (!doesCustomerWithEGNExist(EGN))
	{
		return false;
	}

	for (size_t i = 0; i < rents.getCount(); i++)
	{
		if (rents[i]->getEGN() == EGN)
		{
			rents.removeElement(i);
			i--;
		}
	}

	for (size_t k = 0; k < customers.getCount(); k++)
	{
		if (customers[k]->getEGN() == EGN)
		{
			if (customers.removeElement(k))
			{
				return true;
			}
		}
	}
	return false;
}

bool RentHouse::doesRentWithSameLicenseExist(const MyString &licensePlate)
{
	for (size_t i = 0; i < rents.getCount(); i++)
	{
		if (rents[i]->getLicensePlate() == licensePlate)
		{
			return true;
		}
	}
	return false;
}

bool RentHouse::deleteVechile(const MyString &licensePlate)
{
	if (doesRentWithSameLicenseExist(licensePlate))
	{
		return false;
	}

	for (size_t k = 0; k < vehicles.getCount(); k++)
	{
		if (vehicles[k]->getLicensePlate() == licensePlate)
		{
			if (vehicles.removeElement(k))
			{
				return true;
			}
		}
	}
	return false;
}

bool RentHouse::addRent(const MyString &EGN, const MyString &licensePlate,
						const Date &dateS, const Date &dateE)
{
	// already done in Program, can be void
	if (doesRentWithSameLicenseExist(licensePlate))
	{
		return false;
	}

	Rent rent(EGN, licensePlate, dateS, dateE);
	rents.addElemenet(rent);

	return true;
}

bool RentHouse::removeRent(const MyString &licensePlate)
{
	if (!doesRentWithSameLicenseExist(licensePlate))
	{
		return false;
	}

	for (size_t i = 0; i < rents.getCount(); i++)
	{
		if (rents[i]->getLicensePlate() == licensePlate)
		{
			rents.removeElement(i);
			return true;
		}
	}

	return false;
}

bool RentHouse::increaseRentalTime(const MyString &licensePlate, const size_t days)
{
	if (!doesRentWithSameLicenseExist(licensePlate))
	{
		return false;
	}

	for (size_t i = 0; i < rents.getCount(); i++)
	{
		if (rents[i]->getLicensePlate() == licensePlate)
		{
			rents[i]->increaseRentalTime(days);
			return true;
		}
	}
	return false;
}

bool RentHouse::doesCustomerWithEGNExist(const MyString &EGN)
{
	for (size_t i = 0; i < customers.getCount(); i++)
	{
		if (customers[i]->getEGN() == EGN)
		{
			return true;
		}
	}
	return false;
}

bool RentHouse::changeOwners(const MyString &toEGN, const MyString &licensePlate)
{
	// already done in Program, can be void
	if (!doesRentWithSameLicenseExist(licensePlate) && !doesCustomerWithEGNExist(toEGN))
	{
		return false;
	}

	for (size_t i = 0; i < rents.getCount(); i++)
	{
		if (rents[i]->getLicensePlate() == licensePlate)
		{
			rents[i]->setEGN(toEGN);
			return true;
		}
	}
	return false;
}

void RentHouse::printAllRents() const
{
	for (size_t i = 0; i < rents.getCount(); i++)
	{
		rents[i]->print();
	}
}

void RentHouse::printRentsByStartDate() const
{
	size_t minIndex;
	size_t* rentsSortedByStartDate = new size_t[rents.getCount()]{0};

	for (size_t i = 0; i + 1 < rents.getCount(); i++)
	{
		minIndex = i;
		for (size_t j = i + 1; j < rents.getCount(); j++)
		{
			if (rents[j]->getDateRented() < rents[minIndex]->getDateRented())
			{
				minIndex = j;
			}
		}
		rentsSortedByStartDate[i] = minIndex;
	}

	for (size_t i = 0; i < rents.getCount(); i++)
	{
		rents[rentsSortedByStartDate[i]]->print();
	}

	delete[] rentsSortedByStartDate;
}

void RentHouse::printRentsByEndDate() const
{
	size_t minIndex;
	size_t* rentsSortedByEndDate = new size_t[rents.getCount()]{0};

	for (size_t i = 0; i + 1 < rents.getCount(); i++)
	{
		minIndex = i;
		for (size_t j = i + 1; j < rents.getCount(); j++)
		{
			if (rents[j]->getDateToReturn() < rents[minIndex]->getDateToReturn())
			{
				minIndex = j;
			}
		}
		rentsSortedByEndDate[i] = minIndex;
	}

	for (size_t i = 0; i < rents.getCount(); i++)
	{
		rents[rentsSortedByEndDate[i]]->print();
	}

	delete[] rentsSortedByEndDate;
}

void RentHouse::printAllFreeCars() const
{
	bool isRented;
	for (size_t i = 0; i < vehicles.getCount(); i++)
	{
		isRented = false;
		for (size_t j = 0; j < rents.getCount(); j++)
		{
			if (vehicles[i]->getLicensePlate() == rents[j]->getLicensePlate())
			{
				isRented = true;
				break;
			}
		}
		if (!isRented)
		{
			vehicles[i]->print();
		}
	}
}
