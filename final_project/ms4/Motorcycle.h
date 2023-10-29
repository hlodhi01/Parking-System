/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/
#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"

namespace sdds
{

   class Motorcycle : public Vehicle
   {
      bool car_on_side;

   public:
      Motorcycle();
      Motorcycle(const char* license_plate, const char* make_model);

      Motorcycle(const Motorcycle& src);
      Motorcycle& operator=(const Motorcycle& src);
      ~Motorcycle();

      std::ostream& writeType(std::ostream& os) const;
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout) const;
   };
}

#endif