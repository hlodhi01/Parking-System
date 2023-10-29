/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/
#include "Car.h"

namespace sdds
{

   Car::Car() : Vehicle()
   {
      car_for_wash = false;
   }

   Car::Car(const char* license_plate, const char* make_model) : Vehicle(license_plate, make_model)
   {
      car_for_wash = false;
   }

   Car::Car(const Car& src) : Vehicle(src)
   {
      car_for_wash = src.car_for_wash;
   }

   Car& Car::operator=(const Car& src)
   {
      if (this != &src)
      {
         Vehicle::operator=(src);
         car_for_wash = src.car_for_wash;
      }
      return *this;
   }

   Car::~Car()
   {
   }

   std::ostream& Car::writeType(std::ostream& os) const
   {

      if (isCsv())
         os << "C,";
      else
         os << "Vehicle type: Car" << std::endl;

      return os;
   }

   std::istream& Car::read(std::istream& is)
   {
      if (isCsv())
      {
         Vehicle::read(is);
         int temperature;
         is >> temperature;
         car_for_wash = temperature == 1;

         is.ignore(1000, '\n');
      }
      else
      {
         std::cout << "\nCar information entry" << std::endl;
         Vehicle::read(is);
         std::cout << "Carwash while parked? (Y)es/(N)o: ";

         std::string temperature;

         bool completed = false;
         while (!completed)
         {
            is >> temperature;
            if (temperature == "Y" || temperature == "y")
            {
               car_for_wash = true;
               completed = true;
            }
            else if (temperature == "N" || temperature == "n")
            {
               car_for_wash = false;
               completed = true;
            }
            else
               std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
         }
      }
      return is;
   }

   std::ostream& Car::write(std::ostream& os) const
   {
      if (isEmpty())
      {
         os << "Invalid Car Object" << std::endl;
      }
      else
      {
         if (isCsv())
         {
            Vehicle::write(os);
            os << car_for_wash << std::endl;
         }
         else
         {

            Vehicle::write(os);
            if (car_for_wash)
               os << "With Carwash" << std::endl;
            else
               os << "Without Carwash" << std::endl;
         }
      }
      return os;
   }
}