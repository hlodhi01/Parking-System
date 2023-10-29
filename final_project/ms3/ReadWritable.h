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

#ifndef SDDS_READWRITABLE_H__  
#define SDDS_READWRITABLE_H__ 

// System Library
#include <iostream> 

using namespace std;
namespace sdds {

	class ReadWritable {
		bool is_cs_m;
	public:
		ReadWritable();
		virtual ~ReadWritable();
		virtual std::istream& read(std::istream&) = 0;
		virtual  std::ostream& write(std::ostream&) const = 0;
		bool isCsv() const;
		void setCsv(bool);
		friend std::istream& operator >> (std::istream&, ReadWritable&);
		friend std::ostream& operator << (std::ostream&, const ReadWritable&);
	};
}
#endif
