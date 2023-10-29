
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include "ReadWritable.h"
#include <iostream>

using namespace std;
namespace sdds {
	class Vehicle : public ReadWritable {
	private:
		char* m_licensePlate;
		char* m_makeModel;
		int m_parkingSpotNumber;
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char*);
		void setLicensePlate(const char*);

	public:
		Vehicle();
		Vehicle(const char* licPlate, const char* makeModel);
		~Vehicle();
		int getParkingSpot() const;
		void setParkingSpot(int);
		bool operator==(const char*) const;
		bool operator==(const Vehicle&) const;
		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;
		virtual std::ostream& writeType(std::ostream&) const = 0;
	};
}
#endif