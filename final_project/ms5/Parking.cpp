#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Parking.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"

using namespace std;

namespace sdds {
	Parking::Parking(const char* p_filename, int noOfSpots)
	{
		if (p_filename != nullptr && strlen(p_filename) > 0 && noOfSpots >= 10 && noOfSpots <= MAX_PARKINGS_SPOTS) {
			numberOfTotalSpots = noOfSpots;
			setFilename(p_filename);
			if (loadData()) {
				parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles"
					<< "Find Vehicle" << "Close Parking (End of day)" << "Exit Program";
				vehicleMenu << "Car" << "Motorcycle" << "Cancel";
			}

		}
		else {
			cout << "Error in data file" << endl;
			setEmpty();
		}

	}

	void Parking::setFilename(const char* p_filename) {
		delete[] filename;
		filename = new char[strlen(p_filename) + 1];
		strcpy(filename, p_filename);
	}

	Parking::~Parking()
	{
		saveData();
		for (int i = 0; i < numberOfTotalSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				delete parkingSpots[i];
				parkingSpots[i] = nullptr;
			}
		}
		delete[] filename;
	}
	int Parking::run()
	{
		if (!isEmpty()) {
			bool isParkingClosed = false;
			bool isParkingExited = false;
			while (true) {
				isParkingClosed = false;
				isParkingExited = false;
				parkingStatus();
				int choice = parkingMenu.run();
				switch (choice) {
				case 1:
					parkVehicle();
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					listParkedVehicles();
					break;
				case 4:
					findVehicle();
					break;
				case 5:
					isParkingClosed = closeParking();
					break;
				case 6:
					isParkingExited = exitParking();
					break;
				}

				if (isParkingClosed) {

					//	cin.ignore(1024, '\n');
					break;
				}
				if (isParkingExited) {
					cout << "Exiting program!" << endl;
					cin.ignore(1024, '\n');
					break;
				}

			}
			return 0;
		}
		return 1;
	}

	bool Parking::isEmpty()
	{
		return parkingMenu.isEmpty();
	}

	void Parking::parkingStatus()
	{
		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: " << setw(4) << std::left << (numberOfTotalSpots - numberOfParkedVehciles) << " *****" << endl;
	}

	void Parking::parkVehicle()
	{
		if (numberOfTotalSpots != numberOfParkedVehciles) {
			int selection = vehicleMenu.run();
			switch (selection) {
			case 1:
			{
				Car* car = new Car();
				car->read(cin);
				for (int i = 0; i < numberOfTotalSpots; i++) {
					if (parkingSpots[i] == nullptr) {
						parkingSpots[i] = car;
						car->setParkingSpot(i + 1);
						car->setCsv(false);
						numberOfParkedVehciles++;
						cout << endl << "Parking Ticket" << endl;
						parkingSpots[i]->write(cout);
						break;
					}
				}
				cout << endl << "Press <ENTER> to continue....";
				cin.get();
			}
			break;
			case 2:
			{
				Motorcycle* m = new Motorcycle();
				m->read(cin);
				for (int i = 0; i < numberOfTotalSpots; i++) {
					if (parkingSpots[i] == nullptr) {
						parkingSpots[i] = m;
						m->setParkingSpot(i + 1);
						m->setCsv(false);
						numberOfParkedVehciles++;
						cout << endl << "Parking Ticket" << endl;
						parkingSpots[i]->write(cout);
						break;
					}
				}
				cout << endl << "Press <ENTER> to continue....";
				cin.get();
			};
			break;
			case 3:
				cout << "Parking Cancelled" << endl;
			}
		}
		else {
			cout << "Parking is full" << endl;
		}
	}

	void Parking::returnVehicle()
	{
		char license[10];
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		cin.get(license, 10);
		cin.ignore(1024, '\n');
		while (strlen(license) > 8) {
			cout << "Invalid License Plate, try again: ";
			cin.get(license, 10);
			cin.ignore(1024, '\n');
		}
		int length = strlen(license);
		for (int i = 0; i < length; i++) {
			license[i] = toupper(license[i]);
		}
		bool isFound = false;
		int foundIndex = 0;
		for (int i = 0; i < numberOfTotalSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				if (parkingSpots[i]->operator==(license)) {
					isFound = true;
					cout << endl << "Returning:" << endl;
					parkingSpots[i]->setCsv(false);
					parkingSpots[i]->write(cout);
					foundIndex = i;
					break;
				}
			}
		}
		if (!isFound) {
			cout << endl << "License plate " << license << " Not found" << endl;
		}
		else {
			numberOfParkedVehciles--;
			delete parkingSpots[foundIndex];
			parkingSpots[foundIndex] = nullptr;
		}
		cout << endl;
		cout << "Press <ENTER> to continue....";
		cin.get();
	}

	void Parking::listParkedVehicles()
	{
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < numberOfTotalSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				parkingSpots[i]->setCsv(false);
				parkingSpots[i]->write(cout);
				cout << "-------------------------------" << endl;
			}
		}
		cout << "Press <ENTER> to continue....";
		cin.get();
	}

	void Parking::findVehicle()
	{
		char license[10];
		cout << "Vehicle Search" << endl;
		cout << "Enter Licence Plate Number: ";
		cin.get(license, 10);
		cin.ignore(1024, '\n');
		while (strlen(license) > 8) {
			cout << "Invalid Licence Plate, try again: ";
			cin.get(license, 10);
			cin.ignore(1024, '\n');
		}
		int length = strlen(license);
		for (int i = 0; i < length; i++) {
			license[i] = toupper(license[i]);
		}
		bool isFound = false;
		for (int i = 0; i < numberOfTotalSpots; i++) {
			if (parkingSpots[i] != nullptr) {
				if (parkingSpots[i]->operator==(license)) {
					isFound = true;
					cout << endl << "Vechicle found: " << endl;
					parkingSpots[i]->setCsv(false);
					parkingSpots[i]->write(cout);
					break;
				}
			}
		}
		if (!isFound) {
			cout << endl << "License plate " << license << " Not found" << endl;
		}
		cout << endl;
		cout << "Press <ENTER> to continue....";
		cin.get();
	}

	bool Parking::closeParking()
	{
		if (numberOfParkedVehciles != 0) {
			cout << "This will This will Remove and tow all remaining vehicles from the parking!!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			char selection;
			while (true) {
				selection = cin.get();
				selection = tolower(selection);
				if (selection == 'y' || selection == 'n') {
					if (selection == 'y') {
						cout << "Closing Parking" << endl << endl;
						for (int i = 0; i < numberOfTotalSpots; i++) {
							if (parkingSpots[i] != nullptr) {
								cout << "Towing request" << endl;
								cout << "*********************" << endl;
								parkingSpots[i]->setCsv(false);
								parkingSpots[i]->write(cout);
								if (i != numberOfTotalSpots - 1) {
									cout << endl;
								}
								delete parkingSpots[i];
								parkingSpots[i] = nullptr;
							}
						}
						return true;
					}
					else {
						return false;
					}
				}
				else {
					cout << "Invalid response, only(Y)es or (N)o are acceptable, retry: ";

				}
				//cin.ignore(1000, '\n');

			}
		}
		else {
			cout << "Closing Parking" << endl;
			return true;
		}

		return false;
	}

	bool Parking::exitParking()
	{
		//cout << "This will terminate the program!" << endl;
		cout << "This will This will terminate the program!!" << endl;

		cout << "Are you sure? (Y)es/(N)o: ";
		char selection;
		while (true) {
			selection = cin.get();
			selection = tolower(selection);
			if (selection == 'y' || selection == 'n') {
				if (selection == 'y') {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				cout << "Invalid response, only(Y)es or (N)o are acceptable, retry: ";

			}
			cin.ignore(1000, '\n');

		}

		return false;
	}

	bool Parking::loadData()
	{
		if (!this->isEmpty()) {

			ifstream file(filename);
			string line;
			int i = 0;
			while (!file.fail()) {
				char c = file.get();
				if (c == 'M') {
					file.get();
					Motorcycle* m = new Motorcycle();
					m->setCsv(true);
					m->read(file);
					parkingSpots[m->getParkingSpot() - 1] = m;
					numberOfParkedVehciles++;
				}
				else if (c == 'C') {
					file.get();
					Car* car = new Car();
					car->setCsv(true);
					car->read(file);
					parkingSpots[car->getParkingSpot() - 1] = car;
					numberOfParkedVehciles++;
				}
				else {
					file.ignore(1024, '\n');
				}
				i++;
			}
			file.close();
			return true;
		}
		return false;
	}


	void Parking::saveData()
	{
		if (!this->isEmpty()) {
			ofstream file(filename);
			for (int i = 0; i < numberOfTotalSpots; i++) {
				if (parkingSpots[i] != nullptr) {
					parkingSpots[i]->setCsv(true);
					parkingSpots[i]->write(file);
				}
			}
			file.close();

		}
	}
	void Parking::setEmpty()
	{
		parkingMenu.setEmptyState();
		for (int i = 0; i < MAX_PARKINGS_SPOTS; i++) {
			parkingSpots[i] = nullptr;
		}

	}
}
