/*************************************
       Name: Harsh Lodhi
 Student-Id: 169677218
     E-mail: hlodhi1@myseneca.ca
**************************************/

#ifndef MENU_H
#define MENU_H
#include <iostream>
#define MAX_NO_OF_ITEMS 10

namespace sdds
{

   class Menu;

   class Menu
   {
   private:
      class MenuItem
      {
         char menu_text[50 + 1];
         friend class Menu;

      public:
         MenuItem(const char* text);

         MenuItem(const MenuItem&) = delete;
         MenuItem& operator=(const MenuItem&) = delete;

         void display(std::ostream& os = std::cout) const;
      };

      char heading[50 + 1];
      MenuItem* m_items[MAX_NO_OF_ITEMS];
      int n_items;
      int indentation;
      bool invalid;

      void printIndentation(std::ostream& os) const;

   public:
      Menu(const char* title, int indentation = 0);

      Menu(const Menu&) = delete;
      Menu& operator=(const Menu&) = delete;

      operator bool() const;
      operator int()  const;
      Menu& operator<<(const char* text);
      Menu& operator=(const char* title);

      bool isEmpty() const;
      void add(const char* text);

      int run() const;
      void display(std::ostream& os = std::cout) const;
      void clear();

      ~Menu();
   };

};

#endif
