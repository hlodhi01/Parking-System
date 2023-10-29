/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/
#ifndef VEHICLE_H
#define VEHICLE_H

#include "ReadWritable.h"

namespace sdds
{

   class Vehicle : public ReadWritable
   {
      char plate_no[9];
      char* m_model;
      int spot_no;

   protected:
      void setEmpty();
      bool isEmpty() const;

      const char* getMakeModel() const;
      void setMakeModel(const char* model);

      const char* getLicensePlate() const;

   public:
      Vehicle();
      Vehicle(const char* license_plate, const char* make_model);

      Vehicle(const Vehicle& src);
      Vehicle& operator=(const Vehicle& src);
      ~Vehicle();

      void setLicensePlate(const char* license_plate);

      int getParkingSpot() const;
      void setParkingSpot(int p);

      bool operator==(const char* license_plate) const;
      bool operator==(const Vehicle& v) const;

      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout) const;
      virtual std::ostream& writeType(std::ostream& os) const = 0;
   };
}

#endif