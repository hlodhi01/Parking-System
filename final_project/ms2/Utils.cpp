/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.0
// Date
// Author
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Utils.h"

namespace sdds {
   void strncpy(char* des, const char* src, int len) {
      int i;
      for (i = 0; (len == -1 || i < len) && src[i]; i++) {
         des[i] = src[i];
      }
      des[i] = '\0';
   }

   bool isNumber(const std::string& str) {
      bool ok = true;
      for (unsigned int i = 0; i < str.length() && ok; i++) {
         ok = str[i] >= '0' && str[i] <= '9';
      }
      return ok;
   }

   int strlen(const char* str) {
      int lgth = 0;
      while (str[lgth]) {
         lgth++;
      }
      return lgth;
   }
}