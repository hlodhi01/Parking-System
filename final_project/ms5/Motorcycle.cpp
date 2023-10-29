
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Motorcycle.h"

using namespace std;

namespace sdds {
   Motorcycle::Motorcycle() : Vehicle()
   {
      setEmpty();
   }
   Motorcycle::Motorcycle(const char* licPlate, const char* makeModel) : Vehicle(licPlate, makeModel)
   {
      if (!(licPlate && makeModel && strlen(makeModel) >= 2 && strlen(licPlate) > 0 && strlen(licPlate) <= 8)) {
         setEmpty();

      }
   }
   Motorcycle::~Motorcycle()
   {

   }
   Motorcycle::Motorcycle(const Motorcycle& motorcycle)
   {
      *this = motorcycle;
   }
   Motorcycle& Motorcycle::operator=(const Motorcycle& motorcycle)
   {
      this->setLicensePlate(motorcycle.getLicensePlate());
      this->setMakeModel(motorcycle.getMakeModel());
      this->setParkingSpot(motorcycle.getParkingSpot());
      this->setCsv(motorcycle.isCsv());

      this->isEmpty = motorcycle.isEmpty;
      this->hasSideCar = motorcycle.hasSideCar;
      return *this;
   }
   std::ostream& Motorcycle::writeType(std::ostream& os) const
   {
      if (isCsv()) {
         os << "M,";
      }
      else {
         os << "Vehicle type: Motorcycle" << endl;
      }
      return os;
   }
   std::istream& Motorcycle::read(std::istream& is)
   {
      if (isCsv()) {
         Vehicle::read(is);
         is >> hasSideCar;
         is.ignore(1024, '\n');
      }
      else {
         char userResponse[3];
         cout << endl << "Motorcycle information entry" << endl;
         Vehicle::read(is);
         cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
         is.get(userResponse, 3);
         is.ignore(1024, '\n');
         while (strlen(userResponse) != 1 || (userResponse[0] != 'Y' && userResponse[0] != 'N' && userResponse[0] != 'y' && userResponse[0] != 'n')) {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            is.get(userResponse, 3);
            is.ignore(1024, '\n');
         }
         if (userResponse[0] == 'y' || userResponse[0] == 'Y') {
            hasSideCar = true;
         }
         else {
            hasSideCar = false;
         }
      }
      isEmpty = false;
      return is;
   }
   std::ostream& Motorcycle::write(std::ostream& os) const
   {
      if (isEmpty) {
         os << "Invalid Motorcycle Object" << endl;
      }
      else {
         Vehicle::write(os);
         if (isCsv()) {
            os << hasSideCar << endl;
         }
         else {
            if (hasSideCar) {
               os << "With Sidecar" << endl;
            }
         }
      }
      return os;
   }
   void Motorcycle::setEmpty()
   {
      isEmpty = true;
   }
}
