/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/

#include "ReadWritable.h"

namespace sdds {

   ReadWritable::ReadWritable() {
      write_file = false;
   }

   ReadWritable::~ReadWritable() {
   }

   bool ReadWritable::isCsv() const {
      return write_file;
   }

   void ReadWritable::setCsv(bool value) {
      write_file = value;
   }

   std::istream& operator>>(std::istream& istr, ReadWritable& rw) {
      return rw.read(istr);
   }

   std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw) {
      return rw.write(ostr);
   }

}