/*************************************
       Name: Harsh Lodhi
 Student-Id: 169677218
     E-mail: hlodhi1@myseneca.ca
**************************************/

#ifndef PARKING_H
#define PARKING_H
#include "Menu.h"

namespace sdds
{
   class Parking
   {

   private:
      char* file_name;
      Menu menu_main;
      Menu menu_vehicle;
      bool valid_state;


      bool isEmpty() const;
      void parkingStatus() const;
      void parkVehicle()const;
      void returnVehicle()const;
      void listParkedVehicles() const;
      void findVehicle() const;
      bool closeParking()const;
      bool exitParkingApp() const;
      bool loadDataFile();
      void saveDataFile() const;

   public:
      Parking(const char* file);

      Parking(const Parking& src) = delete;
      Parking& operator=(const Parking& src) = delete;

      ~Parking();
      int run();

   };
}

#endif