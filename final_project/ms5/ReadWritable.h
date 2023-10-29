
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__

#include <iostream>

using namespace std;
namespace sdds {
	class ReadWritable {
		bool isCSMode;
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
