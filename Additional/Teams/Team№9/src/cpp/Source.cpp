#include <iostream>
#include "Hotel.h"
using namespace std;
const int BUFFER_SIZE = 1024;

Reservation::Type stringToType(const String& other)
{
	if (other == "UAI")
		return Reservation::Type::UAI;
	else if (other == "AI")
		return Reservation::Type::AI;
	else if (other == "NO")
		return Reservation::Type::NO;
	return Reservation::Type::UNKNOWN;
}

int main()
{
	String name("Duni Royal Resort"), street("Na moreto");
	Hotel a(name, street);
	while (true) {
		cout << "Write one of the following commands and press enter: \n 1.Edit \n 2.List \n 3.Save \n 4.Display \n 5.Action \n 6.Quit \n";
		size_t command;
		cin >> command;
		cin.ignore();

		if (1 == command)
		{
			cout << endl << "Write one of the following commands and press enter: \n  1.Visitor\n  2.Reservation\n";
			size_t command2;
			cin >> command2;
			cin.ignore();
			cout << endl;

			if (1 == command2)
			{
				cout << "Write one of the following commands and press enter: \n   1.Add new visitor\n   2.Delete visitor\n";
				size_t second;
				cin >> second;
				cin.ignore();

				if (1 == second)
				{
					cout << "Name: ";
					String name;
					cin >> name;
					cout << "ID: ";
					char id[BUFFER_SIZE];
					cin.getline(id, BUFFER_SIZE);

					a.addVisitor(id, name);
					cout << "Visitor successfully added!" << endl;
					continue;
				}

				if (2 == second)
				{
					cout << "ID: ";
					char id[1024];
					cin.getline(id, BUFFER_SIZE);
					a.deleteVisitor(id);
					cout << "Visitor successfully deleted!" << endl;
					continue;
				}
			}

			if (2 == command2)
			{
				cout << "Write one of the following commands and press enter: \n   1.Add new reservation\n   2.Delete reservation\n";
				size_t second;
				cin >> second;
				cin.ignore();

				if (1 == second)
				{
					cout << "ID: ";
					char id[1024];
					cin.getline(id, BUFFER_SIZE);

					cout << "Type: ";
					String type;
					cin >> type;

					Reservation::Type t = stringToType(type);

					size_t days, room, beds;
					cout << "days: "; cin >> days;
					cout << "room: "; cin >> room;
					cout << "beds: "; cin >> beds;
					a.addReservation(id, t, days, room, beds);
					continue;
				}

				if (2 == second)
				{
					cout << "Index:";
					size_t index;
					cin >> index;
					cin.ignore();
					a.deleteReservation(index);
					cout << "Reservation successfully deleted!" << endl;
					continue;
				}
			}
		}

		else if (2 == command)
		{
			cout << "Write one of the following commands and press enter: \n  1.List all visitors\n  2.List all reservations\n  3.List visitor reservation\n ";
			size_t first;
			cin >> first;
			cin.ignore();

			if (1 == first)
			{
				a.listVisitors();
				continue;
			}

			if (2 == first)
			{
				a.listReservations();
				continue;
			}

			if (3 == first)
			{
				cout << "ID of the customer: ";
				char id[BUFFER_SIZE];
				cin.getline(id, BUFFER_SIZE);

				a.listVisitorReservation(id);
				continue;
			}

		}

		else if (3 == command)
		{
			cout << "Write file name: ";
			char buff[BUFFER_SIZE];
			cin.getline(buff, BUFFER_SIZE);

			a.exportVisitors(buff);
			cout << "Visitors successfully exported to file!" << endl;
			continue;
		}

		else if (4 == command)
		{
			a.display();
			continue;
		}

		else if (5 == command)
		{
			cout << "Index of reservation: ";
			size_t index;
			cin >> index;
			cin.ignore();

			cout << "Status for bar: ";
			cout << boolalpha << a.barStatus(index - 1);
			cout << endl;
			cout << "Status for restaurant: ";
			cout << boolalpha << a.restaurantStatus(index - 1);
			cout << endl;

			if ((a.barStatus(index - 1) && a.restaurantStatus(index - 1)) == 0)
			{
				cout << endl << "Write one of the following commands and press enter: \n 1.Pay to restaurant \n 2.Pay to bar\n";
				size_t pay;
				cin >> pay;
				cin.ignore();
				if (pay == 1)
				{
					a.payToRestaurant(index - 1);
					cout << endl;
					continue;
				}
				else if (pay == 2)
				{
					a.payToBar(index - 1);
					cout << endl;
					continue;
				}
			}
		}
		else if (6 == command)
		{
			return 0;
		}
	}
	return 0;
}