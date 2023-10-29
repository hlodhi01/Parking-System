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
#include "ReadWritable.h"

using namespace std;

namespace sdds {
	ReadWritable::ReadWritable() {
		is_cs_m = false;
	}
	ReadWritable::~ReadWritable()
	{
	}
	bool ReadWritable::isCsv() const
	{
		return is_cs_m;
	}
	void ReadWritable::setCsv(bool value)
	{
		is_cs_m = value;
	}
	std::istream& operator>>(std::istream& istr, ReadWritable& readWritable)
	{
		return readWritable.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& readWritable)
	{
		return readWritable.write(ostr);
	}
}