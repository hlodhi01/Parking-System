
/***********************************************************************
// Utils Module
// File  utils.h
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

#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <string>
namespace sdds {

   void strncpy(char* des, const char* src, int len = -1);
   int strlen(const char* str);
   bool isNumber(const std::string& str);

}
#endif // !