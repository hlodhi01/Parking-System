/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/
#ifndef READ_WRITE_H
#define READ_WRITE_H

#include <iostream>

namespace sdds {

   class ReadWritable {
      bool write_file;
   public:
      ReadWritable();
      virtual ~ReadWritable();

      bool isCsv() const;
      void setCsv(bool value);

      virtual std::istream& read(std::istream& is = std::cin) = 0;
      virtual std::ostream& write(std::ostream& os = std::cout) const = 0;

      friend std::istream& operator>>(std::istream& istr, ReadWritable& rw);
      friend std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw);
   };
}



#endif