#include <iostream>
#include "../h/Transport.h"
#include "../h/MyString.h"
#include "../h/InterCityBus.h"
#include "../h/ElectricCar.h"
#include "../h/ElectricScooter.h"
#include "../h/CityBus.h"

using namespace std;


Vector<Driver> Transport::drivers;
Container Transport::vehicles;

void Transport::menu(){

    MyString command;
    cout << "-> Welcome to Electric Public Transport. <-\n";
    while(true){
        cout << "Please enter one of the following commands: \n -> travel, add, remove, print, exit\n";
        cout << "Enter command\n> ";
        cin >> command;

        if(command == "exit") break;
        if(command == "print") print();
        if(command == "add") add();
        if(command == "remove") remove();
        if(command == "travel") travel();

    }
}

void Transport::travel()
{
    MyString inCity, start, end;
    double km;
    cout << "If you want to travel in your city, enter - city\n If you want to get to another destination, enter - other:\n> ";
    cin >> inCity;
    cout << "Please enter where you are traveling from:\n> ";
    cin >> start;
    cout << "Please enter final destination:\n> ";
    cin >> end;
    cout << "Enter the distance: \n> ";
    cin >> km;
    
    if(inCity == "city")
    {
        cout << "City transport\n";
        for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
       {    
            if(Transport::vehicles[i] -> getType() == Vehicle::E_CITY_BUS && dynamic_cast<CityBus *>(Transport::vehicles[i]) -> rideFromTo(start, end) && Transport::vehicles[i]->driveVehicle(km))
            {
                cout << "You can take " << Transport::vehicles[i]->getTypeString() << '\n';
                break;
            }
            if(Transport::vehicles[i] -> getType() != Vehicle::E_INTERCITY_BUS && Transport::vehicles[i]->driveVehicle(km)){

                cout << "You can take " << Transport::vehicles[i]->getTypeString() << '\n';
                break;

            }
       }
    }
    else
    {
        for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
        {    
            if (Transport::vehicles[i]->getType() == Vehicle::E_INTERCITY_BUS && dynamic_cast<IntercityBus *>(Transport::vehicles[i])->rideFromTo(start, end) && Transport::vehicles[i]->driveVehicle(km))
            {
                cout << "You can take " << Transport::vehicles[i]->getTypeString() << '\n';
                break;
            }
       }
       
    }  
     
}

void Transport::print(){
    for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
       {    
            cout << i + 1 << ". ";
            Transport::vehicles[i] -> display();
            cout << endl;
       }

}
void Transport::add(){

    MyString input;
    cout << "Possible commands:\n \t - driverB - a driver for an electric car;\n \t - driverD - a driver for an electric bus;\n \t - bus - add an electric intercity bus;\n \t - cityBus - an electric city bus;\n \t - car - an electric taxi/car;\n \t - scooter - an electric scooter;";
    cin >> input;

    if(input == "driverB"){

        MyString name;

        size_t id, age;
        cout << "\t Name: ";
        cin >> name;
        cout << "\t Id: "; 
        cin >> id;
        cout << "\t Age: ";
        cin >> age;
        Transport::drivers.pushBack(Driver(name, id, age, Driver::B));
    }
    else if(input == "driverD"){

        MyString name;

        size_t id, age;
        cout << "\t Name: ";
        cin >> name;
        cout << "\t Id: "; 
        cin >> id;
        cout << "\t Age: ";
        cin >> age;
        Transport::drivers.pushBack(Driver(name, id, age, Driver::D));
    }
    else if(input == "bus"){

        MyString model, start, end, breakStop;
        size_t idDriver, idVehicle, sH, sM, fH, fM, bH, bM, breakMinutes;
        double range, rate;
        cout << "Id of the driver: ";
        cin >> idDriver;
        cout << "Registration number of the vehicle: ";
        cin >> idVehicle;
        cout << "Model of the bus: ";
        cin >> model;
        cout << "Possible battery range: ";
        cin >> range;
        cout << "Charging rate (ex. 1.5 (km per min)): ";
        cin >> rate;
        cout << "First destination: ";
        cin >> start;
        cout << "Last destination: ";
        cin >> end;
        cout << "Starting hour: ";
        cin >> sH;
        cout << "Starting minutes: ";
        cin >> sM;
        cout << "Final arrival hour: ";
        cin >> fH;
        cout << "Final Arrival minutes: ";
        cin >> fM;
        cout << "Break time hour: ";
        cin >> bH;
        cout << "Break time minutes: ";
        cin >> bM;
        cout << "How long will be the break: ";
        cin >> breakMinutes;
        cout << "Break stop destination: ";
        cin >> breakStop;
        Transport::vehicles.pushBack(new IntercityBus(idDriver, idVehicle, model, range, rate, start, end, sH, sM, fH, fM, bH, bM, breakMinutes, breakStop));
    }
    else if(input == "cityBus"){

        MyString model, start, end;
        size_t idDriver, idVehicle, sH, sM, fH, fM, capacity;
        double range, rate;
        cout << "Id of the driver: ";
        cin >> idDriver;
        cout << "Registration number of the vehicle: ";
        cin >> idVehicle;
        cout << "Model of the bus: ";
        cin >> model;
        cout << "Possible battery range: ";
        cin >> range;
        cout << "Charging rate (ex. 1.5 (km per min)): ";
        cin >> rate;
        cout << "First destination: ";
        cin >> start;
        cout << "Last destination: ";
        cin >> end;
        cout << "Starting hour: ";
        cin >> sH;
        cout << "Starting minutes: ";
        cin >> sM;
        cout << "Final arrival hour: ";
        cin >> fH;
        cout << "Final Arrival minutes: ";
        cin >> fM;
        cout << "The Capacity of the Battery: ";
        cin >> capacity;
        Transport::vehicles.pushBack(new CityBus(idDriver, idVehicle, model, range, rate, start, end, sH, sM, fH, fM, capacity));
    }
    else if(input == "car"){

        MyString model;
        size_t idDriver, idVehicle, seats;
        double range, rate;
        cout << "Id of the driver: ";
        cin >> idDriver;
        cout << "Registration number of the vehicle: ";
        cin >> idVehicle;
        cout << "Model of the bus: ";
        cin >> model;
        cout << "Possible battery range: ";
        cin >> range;
        cout << "Charging rate (ex. 1.5 (km per min)): ";
        cin >> rate;
        cout << "How many seats will be there: ";
        cin >> seats;
        Transport::vehicles.pushBack(new ElectricCar(idDriver, idVehicle, seats, model, range, rate));
    }
    else if(input == "scooter"){

        MyString model;
        size_t idVehicle;
        double range, rate;
        cin >> idVehicle;
        cout << "Model of the bus: ";
        cin >> model;
        cout << "Possible battery range: ";
        cin >> range;
        cout << "Charging rate (ex. 1.5 (km per min)): ";
        cin >> rate;
        Transport::vehicles.pushBack(new ElectricScooter(idVehicle, model, range, rate));
    }
    

    cout << "Successfully created " << input << ".\n";
    
}

void Transport::remove(){

    size_t index;
    cout << "Please enter the number of the vehicle: ";
    cin >> index;

    --index;

    if(Transport::vehicles.getSize() <= index){

        cout << "There is no vehicle number " << index + 1 << "!\n";
        return;
    }

    Transport::vehicles.popAt(index);
    cout << "Erased a vehicle" << ".\n"; 
}

/*

print
add
scooter
12
lime
100
5
print
travel
city
studentski
fmi
10

*/