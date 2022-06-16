#pragma once
#include "RentHouse.h"

class Program
{
private:
    RentHouse rentHouse;

public:
    void StartMenu();

    void Menu_Add();
    void Menu_Print();
    void Menu_Rent();
    void Menu_Delete();

    void Print_MyStringArray(const MyString *, int, char) const;

    void Add_Customer();
    void Add_Vehicle();

    void Print_VehiclesByBrand() const;
    // we probably dont need this because they will invoke just one line function
    //  void Print_AllCustomers() const;
    //  void Print_AllCars() const;
    //  void Print_AllRents() const;
    //  void Print_CarsByPrice() const;
    //  void Print_RentsByStartDate() const;
    //  void Print_RentsByEndDate() const;

    void Delete_Customer();
    void Delete_Vehicle();

    void Rent_RentVehicle();
    void Rent_EndRentVehicle();
    void Rent_ExtendRent();
    void Rent_ChangeOwner();
};
