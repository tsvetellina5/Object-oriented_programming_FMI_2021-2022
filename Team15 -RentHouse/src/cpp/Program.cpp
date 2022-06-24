#include "Program.h"

void Program::load()
{
    std::ifstream file(TXT_NAME.getText());
    file >> rentHouse;
    file.close();
}

void Program::StartMenu()
{
    const int size = 5;
    const MyString commands[size] = {
        "Add", "Print", "Rent", "Delete", "Quit"};
    char char_counter = '1';

    std::cout << "Welcome!\n";

    bool mustEnd = false;
    int ForceBreak = 0; // can be deleted

    while (!mustEnd && ForceBreak++ < 50)
    {
        Print_MyStringArray(commands, size, char_counter);
        std::cout << "> ";

        MyString line;
        line.getLine(std::cin);

        if (line.isChar(char_counter))
        {
            Menu_Add();
        }
        else if (line.isChar(char_counter + 1))
        {
            Menu_Print();
        }
        else if (line.isChar(char_counter + 2))
        {
            Menu_Rent();
        }
        else if (line.isChar(char_counter + 3))
        {
            Menu_Delete();
        }
        else if (line.isChar(char_counter + 4))
        {
            save();
            mustEnd = true;
        }
        else
        {
            std::cout << "Invalid First Command!\n";
        }
    }
}

void Program::Print_MyStringArray(const MyString *arr, int size, char char_counter) const
{
    std::cout << "Choose one of the following:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "   " << char_counter++ << ". ";
        std::cout << arr[i];
    }
}

void Program::Menu_Add()
{
    const int size = 2;
    const MyString commands[size] =
        {"Customer", "Vehicle"};
    char char_counter = 'a';

    Print_MyStringArray(commands, size, char_counter);

    std::cout << "   > ";

    MyString line;
    line.getLine(std::cin);

    if (line.isChar(char_counter))
    {
        Add_Customer();
    }
    else if (line.isChar(char_counter + 1))
    {
        Add_Vehicle();
    }
    else
    {
        std::cout << "Invalid Second Command!\n";
    }
}

void Program::Menu_Print()
{
    const int size = 7;

    const MyString commands[size] =
        {"All customers", "All vehicles", "All rents", "Cars by model",
         "Rents by start date", "Rents by end date", "All free cars"};

    char char_counter = 'a';

    Print_MyStringArray(commands, size, char_counter);

    std::cout << "   > ";

    MyString line;
    line.getLine(std::cin);

    if (line.isChar(char_counter))
    {
        rentHouse.printAllCustomers();
    }
    else if (line.isChar(char_counter + 1))
    {
        rentHouse.printAllVehicles();
    }
    else if (line.isChar(char_counter + 2))
    {
        rentHouse.printAllRents();
    }
    else if (line.isChar(char_counter + 3))
    {
        Print_VehiclesByBrand();
    }
    else if (line.isChar(char_counter + 4))
    {
        rentHouse.printRentsByStartDate();
    }
    else if (line.isChar(char_counter + 5))
    {
        rentHouse.printRentsByEndDate();
    }
    else if (line.isChar(char_counter + 6))
    {
        Print_FreeCars();
    }
    else
    {
        std::cout << "Invalid Second Command!\n";
    }
}

void Program::Menu_Rent()
{
    const int size = 4;

    const MyString commands[size] =
        {"Rent a vehicle", "Extend rent", "Change owner", "End rent"};

    char char_counter = 'a';

    Print_MyStringArray(commands, size, char_counter);

    std::cout << "   > ";

    MyString line;
    line.getLine(std::cin);

    if (line.isChar(char_counter))
    {
        Rent_RentVehicle();
    }
    else if (line.isChar(char_counter + 1))
    {
        Rent_ExtendRent();
    }
    else if (line.isChar(char_counter + 2))
    {
        Rent_ChangeOwner();
    }
    else if (line.isChar(char_counter + 3))
    {
        Rent_EndRentVehicle();
    }
    else
    {
        std::cout << "Invalid Second Command!\n";
    }
}

void Program::Menu_Delete()
{
    const int size = 2;
    const MyString commands[size] =
        {"Customer", "Vehicle"};
    char char_counter = 'a';

    Print_MyStringArray(commands, size, char_counter);

    std::cout << "   > ";

    MyString line;
    line.getLine(std::cin);

    if (line.isChar(char_counter))
    {
        Delete_Customer();
    }
    else if (line.isChar(char_counter + 1))
    {
        Delete_Vehicle();
    }
    else
    {
        std::cout << "Invalid Second Command!\n";
    }
}

void Program::Add_Customer()
{
    MyString name, email, EGN, city, phone, username, password;

    std::cout << "Enter name: ";
    name.getLine(std::cin);

    std::cout << "Enter email: ";
    email.getLine(std::cin);

    std::cout << "Enter EGN: ";
    EGN.getLine(std::cin);

    std::cout << "Enter city: ";
    city.getLine(std::cin);

    std::cout << "Enter phone: ";
    phone.getLine(std::cin);

    std::cout << "Enter username: ";
    username.getLine(std::cin);

    std::cout << "Enter password: ";
    password.getLine(std::cin);

    if (rentHouse.addCustomer(name, email, EGN, city, phone, username, password))
    {
        std::cout << "Customer added successfully!\n";
        return;
    }
    std::cout << "Error while adding Customer!\n";
}

void Program::Add_Vehicle()
{
    MyString category;
    MyString brand;
    MyString model;
    MyString licensePlate;
    MyString temp;
    size_t yearOfProduction;
    size_t seatsCount;
    size_t gearbox;
    size_t engineType;

    std::cout << "Enter the type of a vehivle ('Motorcycle', 'Car' or 'Bus'): ";
    category.getLine(std::cin);

    std::cout << "Enter the brand: ";
    brand.getLine(std::cin);

    std::cout << "Enter the model: ";
    model.getLine(std::cin);

    std::cout << "Enter the license plate: ";
    licensePlate.getLine(std::cin);

    std::cout << "Enter the year of production: ";
    temp.getLine(std::cin);
    yearOfProduction = temp.convertToInt();

    std::cout << "Enter the seats count: ";
    temp.getLine(std::cin);
    seatsCount = temp.convertToInt();

    std::cout << "Enter the gearbox type (Manual - 0, Auto - 1): ";
    temp.getLine(std::cin);
    gearbox = temp.convertToInt();

    std::cout << "Enter the engine type (Diesel - 0, Petrol - 1, Electric - 2): ";
    temp.getLine(std::cin);
    engineType = temp.convertToInt();

    if (category == "Motorcycle")
    {
        bool param1, param2;

        std::cout << "Enter whether the motorcycle has a side car (0/1): ";
        temp.getLine(std::cin);
        param1 = temp.convertToInt();

        std::cout << "Enter whether the motorcycle has storage space (0/1): ";
        temp.getLine(std::cin);
        param2 = temp.convertToInt();

        rentHouse.addMotorcycle(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType, param1, param2);
    }
    else if (category == "Car")
    {
        bool param1, param2;

        std::cout << "Enter whether the car is a sports one (0/1): ";
        temp.getLine(std::cin);
        param1 = temp.convertToInt();

        std::cout << "Enter whether the car is a convertible or not (0/1): ";
        temp.getLine(std::cin);
        param2 = temp.convertToInt();

        rentHouse.addCar(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType, param1, param2);
    }
    else if (category == "Bus")
    {
        size_t param1;
        bool param2;

        std::cout << "Enter the rating: ";
        temp.getLine(std::cin);
        param1 = temp.convertToInt();

        std::cout << "Enter whether the bus has an AC or not (0/1): ";
        temp.getLine(std::cin);
        param2 = temp.convertToInt();

        rentHouse.addBus(brand, model, licensePlate, yearOfProduction, seatsCount, gearbox, engineType, param1, param2);
    }
    else
    {
        std::cout << "No such vehicle! Enter 'Motorcycle', 'Car' or 'Bus'!" << std::endl;
        return;
    }

    std::cout << "Vehicle successfully added!" << std::endl;
}

void Program::Print_VehiclesByBrand() const
{
    std::cout << "Enter brand: ";
    MyString brand;
    brand.getLine(std::cin);

    if (!rentHouse.printVehiclesByBrand(brand))
    {
        std::cout << "Brand does not exist!\n";
    }
}

void Program::Delete_Customer()
{
    std::cout << "Enter EGN: ";
    MyString EGN;
    EGN.getLine(std::cin);

    if (rentHouse.deleteCustomer(EGN))
    {
        std::cout << "Customer deleted successfully!\n";
        return;
    }

    std::cout << "Customer deletion failed!\n";
}

void Program::Delete_Vehicle()
{
    std::cout << "Enter License plate: ";
    MyString plate;
    plate.getLine(std::cin);

    if (rentHouse.deleteVechile(plate))
    {
        std::cout << "Vehicle deleted successfully!\n";
        return;
    }

    std::cout << "Vehicle deletion failed!\n";
}

void Program::Rent_RentVehicle()
{
    std::cout << "Enter customer's EGN: ";
    MyString EGN;
    EGN.getLine(std::cin);

    if (!rentHouse.doesCustomerWithEGNExist(EGN))
    {
        std::cout << "No customer found\n";
        return;
    }

    std::cout << "Enter License plate: ";
    MyString plate;
    plate.getLine(std::cin);

    if (rentHouse.isLicensePlateUnique(plate))
    {
        std::cout << "Car does not exist!\n";
        return;
    }

    if (rentHouse.doesRentWithSameLicenseExist(plate))
    {
        std::cout << "Car is already in use\n";
        return;
    }

    std::cout << "Enter start date: ";
    Date StartDate;

    do
    {
        std::cin >> StartDate;
    } while (!StartDate.isValidDate());

    std::cout << "Enter end date: ";
    Date EndDate;

    do
    {
        std::cin >> EndDate;
    } while (!EndDate.isValidDate());

    MyString trash;
    trash.getLine(std::cin);

    if (StartDate >= EndDate)
    {
        std::cout << "End date is before Start date!";
        return;
    }

    rentHouse.addRent(EGN, plate, StartDate, EndDate);
    std::cout << "Rent added successfuly!\n";
}

void Program::Rent_EndRentVehicle()
{
    std::cout << "Enter License plate: ";
    MyString plate;
    plate.getLine(std::cin);

    if (rentHouse.removeRent(plate))
    {
        std::cout << "Rent ended successfully!\n";
        return;
    }
    std::cout << "There is no vehicle with this license plate!\n";
}

void Program::Rent_ExtendRent()
{
    std::cout << "Enter License plate: ";
    MyString plate;
    plate.getLine(std::cin);

    if (!rentHouse.doesRentWithSameLicenseExist(plate))
    {
        std::cout << "Rent not found!\n";
        return;
    }

    std::cout << "Enter days to extend: ";
    MyString daysStr;
    daysStr.getLine(std::cin);

    if (!daysStr.isOnlyNumbers())
    {
        std::cout << "Incorrect format days!\n";
        return;
    }
    size_t days = daysStr.convertToInt();

    if (rentHouse.increaseRentalTime(plate, days))
    {
        std::cout << "Rent days increased successfully!\n";
        return;
    }
    std::cout << "Rent days failed to be increased!\n";
}

void Program::Rent_ChangeOwner()
{
    std::cout << "Enter License plate: ";
    MyString plate;
    plate.getLine(std::cin);

    if (!rentHouse.doesRentWithSameLicenseExist(plate))
    {
        std::cout << "Rent not found!\n";
        return;
    }

    std::cout << "Enter Customer's EGN to change the car to: ";
    MyString EGN;
    EGN.getLine(std::cin);

    if (!rentHouse.doesCustomerWithEGNExist(EGN))
    {
        std::cout << "Customer not found!\n";
        return;
    }

    if (rentHouse.changeOwners(EGN, plate))
    {
        std::cout << "Rent owner changed successfully!\n";
        return;
    }

    std::cout << "Rent owner change failed!\n";
}
void Program::Print_FreeCars() {
    if(!rentHouse.printAllFreeCars()) {
        std::cout << "No free cars!\n";
    }
}

void Program::save()
{
    std::ofstream file(TXT_NAME.getText());
    file << rentHouse;
    file.close();
}
