
#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__
#include "Menu.h"
#include "Vehicle.h"
#include <iostream>

using namespace std;
namespace sdds {
	class Parking {
		const static int MAX_PARKINGS_SPOTS = 100;

		int numberOfTotalSpots = 0;

		Vehicle* parkingSpots[MAX_PARKINGS_SPOTS] = { nullptr };

		int numberOfParkedVehciles = 0;

		char* filename{};

		Menu parkingMenu{ "Parking Menu, select an action:",0 };
		Menu vehicleMenu{ "Select type of the vehicle:", 1 };

		void setFilename(const char*);
		bool isEmpty();
		void parkingStatus();
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles();
		void findVehicle();
		bool closeParking();
		bool exitParking();
		bool loadData();
		void saveData();
		void setEmpty();

	public:
		Parking(const char*, int);
		~Parking();
		Parking(const Parking&) = delete;
		void operator=(const Parking&) = delete;
		int run();
	};
}
#endif
