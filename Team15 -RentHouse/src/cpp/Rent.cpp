#include "Rent.h"

Rent::Rent(const MyString EGN, const MyString licensePlate, const Date &dateRented, const Date &dateToReturn)
    : EGN(EGN), licensePlate(licensePlate), dateRented(dateRented), dateToReturn(dateToReturn) {}

void Rent::increaseRentalTime(size_t days)
{
    dateToReturn.addDays(days);
}

std::ostream &operator<<(std::ostream &ostr, const Rent &rent)
{
    ostr << rent.EGN << " " << rent.licensePlate << " " << rent.dateRented << " " << rent.dateToReturn;
    return ostr;
}


const MyString& Rent::getEGN() const {
    return EGN;
}
void Rent::setEGN(const MyString& EGN) {
    this->EGN = EGN;
}

const MyString &Rent::getLicensePlate() const {
    return licensePlate;
}
void Rent::setLicensePlate(const MyString& licensePlate) {
    this->licensePlate = licensePlate;
}

Rent* Rent::clone() const {
    return new Rent(*this);
}
void Rent::print() const {
    std::cout << "Vehicle license plate: " << licensePlate << "; Customer's EGN: " << EGN << ";" << std::endl;
    std::cout << "Starting date: " << dateRented << "; Ending date: " << dateToReturn << ";" << std::endl;
}
