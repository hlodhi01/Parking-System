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

#define _CRT_SECURE_NO_WARNINGS 

// User-defined Library
#include "Vehicle.h"

// System Library
#include <cctype>
#include <cstring> 
#include <iostream> 

using namespace std;
namespace sdds {
	Vehicle::Vehicle()
	{
		setEmpty();
	}
	Vehicle::Vehicle(const char* license_pt, const char* m_model) : ReadWritable()
	{
		if (license_pt && m_model && strlen(m_model) >= 2 && strlen(license_pt) > 0 && strlen(license_pt) <= 8) {
			m_parking_s_no = 0;
			setLicensePlate(license_pt);
			setMakeModel(m_model);
		}
		else {
			setEmpty();
		}

	}
	Vehicle::~Vehicle() {
		delete[] m_liscence;
		delete[] m_m_model;
	}
	void Vehicle::setEmpty()
	{
		delete[] m_liscence;
		delete[] m_m_model;
		m_liscence = nullptr;
		m_m_model = nullptr;
		m_parking_s_no = -1;
	}
	bool Vehicle::isEmpty() const
	{
		if (m_parking_s_no < 0) {
			return true;
		}
		return false;
	}
	const char* Vehicle::getLicensePlate() const
	{
		return m_liscence;
	}
	const char* Vehicle::getMakeModel() const
	{
		return m_m_model;
	}
	void Vehicle::setMakeModel(const char* m_model)
	{
		if (m_model && strlen(m_model) >= 2) {
			delete[] m_m_model;
			m_m_model = new char[strlen(m_model) + 1];
			strcpy(m_m_model, m_model);
		}
		else {
			setEmpty();
		}
	}

	void Vehicle::setLicensePlate(const char* liscence_pt)
	{
		delete[] m_liscence;
		m_liscence = new char[strlen(liscence_pt) + 1];
		strcpy(m_liscence, liscence_pt);
		for (int i = 0; m_liscence[i]; i++) {
			m_liscence[i] = toupper(m_liscence[i]);
		}
	}

	int Vehicle::getParkingSpot() const
	{
		return m_parking_s_no;
	}
	void Vehicle::setParkingSpot(int parking_Spt)
	{
		if (parking_Spt >= 0) {
			m_parking_s_no = parking_Spt;
		}
		else {
			setEmpty();
		}
	}
	bool Vehicle::operator==(const char* liscence_pt) const
	{
		bool isEqual = true;
		if (m_liscence && liscence_pt && (strlen(m_liscence) == strlen(liscence_pt))) {
			int license_pt_lgth = strlen(m_liscence);
			for (int i = 0; i < license_pt_lgth; i++) {
				if (toupper(m_liscence[i]) != toupper(liscence_pt[i])) {
					isEqual = false;
					break;
				}
			}
		}
		else {
			isEqual = false;
		}
		return isEqual;
	}
	bool Vehicle::operator==(const Vehicle& s_vehicle) const
	{
		return s_vehicle == m_liscence;
	}
	std::istream& Vehicle::read(std::istream& istr)
	{
		int parking_s_no = 0;

		char tmp_liscence[10];
		char tmp_make_model[62];

		if (isCsv()) {
			istr >> parking_s_no;
			istr.ignore();
			istr.get(tmp_liscence, 9, ',');
			istr.ignore(1024, ',');
			istr.get(tmp_make_model, 61, ',');
			istr.ignore(1024, ',');
		}
		else {
			cout << "Enter Licence Plate Number: ";
			istr.get(tmp_liscence, 10);
			istr.ignore(1024, '\n');
			while (strlen(tmp_liscence) > 8) {
				cout << "Invalid Licence Plate, try again: ";
				istr.get(tmp_liscence, 10);
				istr.ignore(1024, '\n');
			}
			cout << "Enter Make and Model: ";
			istr.get(tmp_make_model, 62);
			istr.ignore(1024, '\n');
			while (strlen(tmp_make_model) > 60 || strlen(tmp_make_model) < 2) {
				cout << "Invalid Make and model, try again: ";
				istr.get(tmp_make_model, 62);
				istr.ignore(1024, '\n');
			}
		}
		if (istr.fail()) {
			setEmpty();
			istr.clear();
		}
		else {
			setMakeModel(tmp_make_model);
			setParkingSpot(parking_s_no);
			setLicensePlate(tmp_liscence);
		}
		return istr;
	}
	std::ostream& Vehicle::write(std::ostream& ostr) const
	{
		if (isEmpty()) {
			ostr << "Invalid Vehicle Object" << endl;
		}
		else {
			writeType(ostr);
			if (isCsv()) {
				if (m_parking_s_no == 0) {
					ostr << "N/A" << "," << m_liscence << "," << m_m_model << ",";
				}
				else {
					ostr << m_parking_s_no << "," << m_liscence << "," << m_m_model << ",";
				}
			}
			else {
				ostr << "Parking Spot Number: ";
				if (m_parking_s_no == 0) {
					ostr << "N/A";
				}
				else {
					ostr << m_parking_s_no;
				}
				ostr << endl;

				ostr << "Licence Plate: " << m_liscence << endl;

				ostr << "Make and Model: " << m_m_model << endl;
			}
		}
		return ostr;
	}
}
