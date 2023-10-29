
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__
#include "Vehicle.h"
#include <iostream>

using namespace std;
namespace sdds {
	class Car : public Vehicle {
		bool carwash = false;
		bool isEmpty = false;
	public:
		Car();
		Car(const char* licPlate, const char* makeModel);

		~Car();
		Car(const Car& car);
		Car& operator=(const Car& car);

		std::ostream& writeType(std::ostream&) const override;
		std::istream& read(std::istream&) override;
		std::ostream& write(std::ostream&) const override;

		void setEmpty();
	};
}
#endif