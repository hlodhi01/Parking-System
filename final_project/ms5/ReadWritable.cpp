
#define _CRT_SECURE_NO_WARNINGS
#include "ReadWritable.h"

using namespace std;

namespace sdds {
	ReadWritable::ReadWritable() {
		isCSMode = false;
	}
	ReadWritable::~ReadWritable()
	{
	}
	bool ReadWritable::isCsv() const
	{
		return isCSMode;
	}
	void ReadWritable::setCsv(bool value)
	{
		isCSMode = value;
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