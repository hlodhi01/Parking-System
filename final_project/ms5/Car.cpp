
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds {


	Car::Car() : Vehicle()
	{
		setEmpty();
	}

	Car::Car(const char* licPlate, const char* makeModel) : Vehicle(licPlate, makeModel)
	{
		if (!(licPlate && makeModel && strlen(makeModel) >= 2 && strlen(licPlate) > 0 && strlen(licPlate) <= 8)) {
			setEmpty();
		}
	}

	Car::~Car()
	{
	}

	Car::Car(const Car& car)
	{
		*this = car;
	}

	Car& Car::operator=(const Car& car)
	{
		this->setLicensePlate(car.getLicensePlate());
		this->setMakeModel(car.getMakeModel());
		this->setParkingSpot(car.getParkingSpot());
		this->setCsv(car.isCsv());

		this->isEmpty = car.isEmpty;
		this->carwash = car.carwash;
		return *this;
	}

	std::ostream& Car::writeType(std::ostream& os) const
	{
		if (isCsv()) {
			os << "C,";
		}
		else {
			os << "Vehicle type: Car" << endl;
		}
		return os;
	}
	std::istream& Car::read(std::istream& is)
	{
		if (isCsv()) {
			Vehicle::read(is);
			is >> carwash;
			is.ignore(1024, '\n');
		}
		else {
			char userResponse[3];
			cout << endl << "Car information entry" << endl;
			Vehicle::read(is);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			is.get(userResponse, 3);
			is.ignore(1024, '\n');
			while (strlen(userResponse) != 1 || (userResponse[0] != 'Y' && userResponse[0] != 'N' && userResponse[0] != 'y' && userResponse[0] != 'n')) {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				is.get(userResponse, 3);
				is.ignore(1024, '\n');
			}
			if (userResponse[0] == 'y' || userResponse[0] == 'Y') {
				carwash = true;
			}
			else {
				carwash = false;
			}
		}
		isEmpty = false;
		return is;
	}
	std::ostream& Car::write(std::ostream& os) const
	{
		if (isEmpty) {
			os << "Invalid Car Object" << endl;
		}
		else {
			Vehicle::write(os);
			if (isCsv()) {
				os << carwash << endl;
			}
			else {
				if (carwash) {
					os << "With Carwash" << endl;
				}
				else {
					os << "Without Carwash" << endl;
				}
			}
		}
		return os;
	}
	void Car::setEmpty()
	{
		isEmpty = true;
	}
}
