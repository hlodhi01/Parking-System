/************************************
* Name       : Harsh Lodhi
* Email      : hlodhi1@myseneca.ca
* Student-Id : 169677218
**************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <cstring>


namespace sdds {


   Vehicle::Vehicle() {
      m_model = nullptr;
      setEmpty();
   }

   Vehicle::Vehicle(const char* license_plate, const char* make_model) {
      m_model = nullptr;
      setEmpty();
      setLicensePlate(license_plate);
      setMakeModel(make_model);
      spot_no = 0;
   }

   Vehicle::Vehicle(const Vehicle& src) {
      m_model = nullptr;
      setEmpty();
      *this = src;
   }

   Vehicle& Vehicle::operator=(const Vehicle& src) {
      if (this != &src) {
         setEmpty();
         setLicensePlate(src.getLicensePlate());
         setMakeModel(src.getMakeModel());
         setParkingSpot(src.getParkingSpot());
         setCsv(src.isCsv());
      }
      return *this;
   }

   Vehicle::~Vehicle() {
      setEmpty();
   }

   void Vehicle::setEmpty() {
      plate_no[0] = '\0';

      if (m_model != nullptr) {
         delete[] m_model;
         m_model = nullptr;
      }
      spot_no = 0;
   }

   bool Vehicle::isEmpty() const {
      return plate_no[0] == '\0' || m_model == nullptr || spot_no < 0;
   }

   const char* Vehicle::getLicensePlate() const {
      return plate_no;
   }

   void Vehicle::setLicensePlate(const char* license_plate) {

      if (license_plate != nullptr && license_plate[0] != '\0') {

         size_t length = strlen(license_plate);
         int i = 0;
         while (license_plate[i] != '\0' && i < 8 && length <= 8) {
            plate_no[i] = license_plate[i];
            i++;
         }
         plate_no[i] = '\0';
      }
   }

   const char* Vehicle::getMakeModel() const {
      return m_model;
   }

   void Vehicle::setMakeModel(const char* model) {
      if (model != nullptr && strlen(model) >= 2) {
         delete[] m_model;
         m_model = new char[strlen(model) + 1];
         strcpy(m_model, model);
      }
   }

   int Vehicle::getParkingSpot() const {
      return spot_no;
   }

   void Vehicle::setParkingSpot(int p) {
      spot_no = p;
   }

   bool Vehicle::operator==(const char* license_plate) const {

      int length = strlen(license_plate);
      int length2 = strlen(plate_no);

      if (length == length2) {
         for (int i = 0; i < length; i++) {
            if (toupper(license_plate[i]) != toupper(plate_no[i])) {
               return false;
            }
         }
      }

      return true;

   }

   bool Vehicle::operator==(const Vehicle& v) const {
      return *this == v.getLicensePlate();
   }

   std::istream& Vehicle::read(std::istream& is) {
      if (isCsv()) {
         is >> spot_no;
         is.ignore(100, ',');

         is.getline(plate_no, 9, ',');


         size_t length = strlen(plate_no);
         for (size_t i = 0; i < length; i++)
         {
            plate_no[i] = toupper(plate_no[i]);
         }
         plate_no[length] = '\0';

         //is.ignore(100,',');


         char model[61];
         is.getline(model, 61, ',');

         setMakeModel(model);

         //is.ignore(100,',');


      }
      else {

         char buffer[100];
         std::cout << "Enter License Plate Number: ";
         while (true) {
            is.getline(buffer, 100, '\n');
            size_t len = strlen(buffer);

            if (len >= 1 && len <= 8) {
               for (size_t i = 0; i < len; i++)
               {
                  plate_no[i] = toupper(buffer[i]);
                  plate_no[i + 1] = '\0';
               }

               break;
            }
            else {
               std::cout << "Invalid License Plate, try again: ";
            }
         }



         std::cout << "Enter Make and Model: ";
         while (true)
         {
            is.getline(buffer, 100, '\n');
            size_t len = strlen(buffer);
            if (len >= 2 && len <= 60) {
               setMakeModel(buffer);
               break;
            }
            else {
               std::cout << "Invalid Make and model, try again: ";
            }
         }


      }
      return is;
   }


   std::ostream& Vehicle::write(std::ostream& os) const {
      if (isEmpty()) {
         os << "Invalid Vehicle Object" << std::endl;
      }
      else {
         writeType(os);
         if (isCsv()) {
            os << spot_no << "," << plate_no << "," << m_model << ",";
         }
         else {
            os << "Parking Spot Number: ";
            if (spot_no == 0)
               os << "N/A" << std::endl;
            else
               os << spot_no << std::endl;


            os << "License Plate: " << plate_no << std::endl;
            os << "Make and Model: " << m_model << std::endl;
         }
      }
      return os;
   }

}
