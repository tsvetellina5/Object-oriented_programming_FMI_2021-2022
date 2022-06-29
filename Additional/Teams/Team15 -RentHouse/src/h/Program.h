#pragma once
#include "RentHouse.h"
const MyString TXT_NAME = "data.txt";

class Program
{
private:
    RentHouse rentHouse;

public:
    void load();
    void StartMenu();

    void Menu_Add();
    void Menu_Print();
    void Menu_Rent();
    void Menu_Delete();

    void Print_MyStringArray(const MyString *, int, char) const;

    void Add_Customer();
    void Add_Vehicle();

    void Print_VehiclesByBrand() const;
    void Print_FreeCars();

    void Delete_Customer();
    void Delete_Vehicle();

    void Rent_RentVehicle();
    void Rent_EndRentVehicle();
    void Rent_ExtendRent();
    void Rent_ChangeOwner();

    void save();
};
