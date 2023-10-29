/*
Name:		Harsh Lodhi
Email:		hlodhi1@myseneca.ca
Student ID:	169677218
Date:		26 Nov, 2022
Section:	OPP244-NDD

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/

#ifndef SDDS_VEHICLE_H__ 
#define SDDS_VEHICLE_H__ 

// User-defined Library
#include "ReadWritable.h" 

// System Library
#include <iostream> 

using namespace std;
namespace sdds {
	class Vehicle : public ReadWritable {
	private:
		char* m_liscence{ 0 };
		char* m_m_model{ 0 };
		int m_parking_s_no;

	public:
		Vehicle();
		Vehicle(const char*, const char*);
		~Vehicle();
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char*);
		void setLicensePlate(const char*);
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

