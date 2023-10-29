/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/
#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
namespace sdds
{

   class Car : public Vehicle
   {
      bool car_for_wash;

   public:
      Car();
      Car(const char* license_plate, const char* make_model);

      Car(const Car& src);
      Car& operator=(const Car& src);
      ~Car();

      std::ostream& writeType(std::ostream& os) const;
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout) const;

   };
}
#endif