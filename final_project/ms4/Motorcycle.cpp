/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/
#include "Motorcycle.h"
#include <sstream>
namespace sdds
{

   Motorcycle::Motorcycle() : Vehicle()
   {
      car_on_side = false;
   }

   Motorcycle::Motorcycle(const char* license_plate, const char* make_model) : Vehicle(license_plate, make_model)
   {
      car_on_side = false;
   }

   Motorcycle::Motorcycle(const Motorcycle& src) : Vehicle(src)
   {
      car_on_side = src.car_on_side;
   }

   Motorcycle& Motorcycle::operator=(const Motorcycle& src)
   {
      if (this != &src)
      {
         Vehicle::operator=(src);
         car_on_side = src.car_on_side;
      }
      return *this;
   }

   Motorcycle::~Motorcycle()
   {
   }

   std::ostream& Motorcycle::writeType(std::ostream& os) const
   {
      if (isCsv())
         os << "M,";
      else
         os << "Vehicle type: Motorcycle" << std::endl;

      return os;
   }

   std::istream& Motorcycle::read(std::istream& is)
   {
      if (isCsv())
      {
         Vehicle::read(is);
         int temperature;
         is >> temperature;
         car_on_side = temperature == 1;
         is.ignore(1000, '\n');
      }
      else
      {
         std::cout << "\nMotorcycle information entry" << std::endl;
         Vehicle::read(is);
         std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

         std::string temperature;
         bool done = false;

         while (!done)
         {
            std::getline(std::cin, temperature);
            if (temperature == "Y" || temperature == "y")
            {
               car_on_side = true;
               done = true;
            }
            else if (temperature == "N" || temperature == "n")
            {
               car_on_side = false;
               done = true;
            }
            else
               std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
         }
      }
      return is;
   }

   std::ostream& Motorcycle::write(std::ostream& os) const
   {
      if (isEmpty())
      {
         os << "Invalid Motorcycle Object" << std::endl;
      }
      else
      {
         if (isCsv())
         {
            Vehicle::write(os);
            os << car_on_side << std::endl;
         }
         else
         {

            Vehicle::write(os);
            if (car_on_side)
               os << "With Sidecar\n";


         }
      }
      return os;
   }

}