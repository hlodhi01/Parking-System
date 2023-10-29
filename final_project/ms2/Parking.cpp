/*************************************
       Name: Harsh Lodhi
 Student-Id: 169677218
     E-mail: hlodhi1@myseneca.ca
**************************************/

#include "Parking.h"
#include <iostream>
#include "Utils.h"

namespace sdds
{

   Parking::Parking(const char* file) : menu_main(NULL, 0),
      menu_vehicle(NULL, 1)
   {
      valid_state = true;
      if (file != nullptr && file[0] != '\0')
      {
         file_name = new char[strlen(file) + 1];
         strncpy(file_name, file);
         valid_state = true;
      }
      else
      {
         valid_state = false;
         file_name = nullptr;
      }

      if (!loadDataFile())
      {
         valid_state = false;
         std::cout << "Error in data file" << std::endl;
      }

      if (valid_state)
      {
         menu_main = "Parking Menu, select an action:";
         menu_main << "Park Vehicle"
            << "Return Vehicle"
            << "List Parked Vehicles"
            << "Find Vehicle"
            << "Close Parking (End of day)"
            << "Exit Program";

         menu_vehicle = "Select type of the vehicle:";
         menu_vehicle << "Car"
            << "Motorcycle"
            << "Cancel";
      }
   }

   Parking::~Parking()
   {

      saveDataFile();
      delete[] file_name;
      file_name = nullptr;
   }

   int Parking::run()
   {

      int a = 0;
      if (valid_state)
      {
         bool stop = false;

         do
         {

            parkingStatus();
            int selecton = menu_main.run();

            if (selecton == 1)
            {
               parkVehicle();
            }
            else if (selecton == 2)
            {
               returnVehicle();
            }
            else if (selecton == 3)
            {
               listParkedVehicles();
            }
            else if (selecton == 4)
            {
               findVehicle();
            }
            else if (selecton == 5)
            {
               stop = closeParking();
            }
            else if (selecton == 6)
            {
               stop = exitParkingApp();
            }
         } while (!stop);

         a = 1;
      }
      return a;
   }

   bool Parking::isEmpty() const
   {
      return !valid_state;
   }

   void Parking::parkVehicle() const
   {
      int choice = menu_vehicle.run();

      std::cout << "---------------------------------\n";
      switch (choice)
      {
      case 1:
         std::cout << "Parking Car" << std::endl;
         break;
      case 2:
         std::cout << "Parking Motorcycle" << std::endl;
         break;
      case 3:
         std::cout << "Cancelled parking" << std::endl;
         break;
      }

      std::cout << "---------------------------------\n";
      std::cout << std::endl;
   }

   void Parking::returnVehicle() const
   {

      std::cout << "---------------------------------\n";
      std::cout << "Returning Vehicle" << std::endl;

      std::cout << "---------------------------------\n";
      std::cout << std::endl;
   }

   void Parking::listParkedVehicles() const
   {

      std::cout << "---------------------------------\n";
      std::cout << "Listing Parked Vehicles" << std::endl;
      std::cout << "---------------------------------\n";
      std::cout << std::endl;
   }

   void Parking::findVehicle() const
   {

      std::cout << "---------------------------------\n";
      std::cout << "Finding a Vehicle" << std::endl;
      std::cout << "---------------------------------\n";
      std::cout << std::endl;
   }

   void Parking::parkingStatus() const
   {
      std::cout << "****** Valet Parking ******\n";
   }

   void Parking::saveDataFile() const
   {
      if (valid_state)
      {
         std::cout << "---------------------------------\n";
         std::cout << "Saving data into " << file_name << std::endl;
         std::cout << "---------------------------------\n";
         std::cout << std::endl;
      }
   }

   bool Parking::loadDataFile()
   {
      bool a = false;
      if (valid_state)
      {
         std::cout << "---------------------------------\n";
         std::cout << "loading data from " << file_name << std::endl;
         std::cout << "---------------------------------\n";
         std::cout << std::endl;
         a = true;
      }


      return a;
   }

   bool Parking::closeParking() const
   {

      std::cout << "This will close the parking; All the vehicles will be removed!\n"
         << "Are you sure? (Y)es/(N)o: ";

      int a = -1;
      do
      {
         std::string input;
         std::cin >> input;
         if (input == "Y" || input == "y")
         {
            std::cout << "Ending application!" << std::endl;
            a = 1;
         }
         else if (input == "N" || input == "n")
            a = 0;
         else
            std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

      } while (a == -1);

      return a == 1;
   }

   bool Parking::exitParkingApp() const
   {
      std::cout << "This will terminate the application and save the data!\n"
         << "Are you sure? (Y)es/(N)o: ";

      int ret = -1;
      do
      {
         std::string input;
         std::cin >> input;
         if (input == "Y" || input == "y")
         {
            std::cout << "Exiting application!" << std::endl;
            ret = 1;
         }
         else if (input == "N" || input == "n")
            ret = 0;
         else
            std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

      } while (ret == -1);

      return ret == 1;
   }
}