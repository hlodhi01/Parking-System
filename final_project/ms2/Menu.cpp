/*************************************
       Name: Harsh Lodhi
 Student-Id: 169677218
     E-mail: hlodhi1@myseneca.ca
**************************************/
#include "Menu.h"
#include "Utils.h"

namespace sdds
{

   Menu::MenuItem::MenuItem(const char* text)
   {
      if (text == nullptr)
         menu_text[0] = '\0';
      else
         strncpy(menu_text, text, 50);
   }

   void Menu::MenuItem::display(std::ostream& os) const
   {
      if (menu_text[0] != '\0')
         os << menu_text << std::endl;
   }

   // Menu class

   Menu::Menu(const char* title, int indentation)
   {
      if (title == nullptr)
         invalid = true;
      else
      {
         strncpy(this->heading, title, 50);
         this->invalid = false;
      }

      this->indentation = indentation;
      this->n_items = 0;
   }

   Menu::operator bool() const
   {
      return !invalid;
   }

   bool Menu::isEmpty() const
   {
      return invalid;
   }

   void Menu::add(const char* text)
   {
      if (!invalid)
      {
         if (text == nullptr)
            invalid = true;
         else if (n_items < MAX_NO_OF_ITEMS)
         {
            m_items[n_items] = new MenuItem(text);
            n_items++;
         }
      }
   }

   Menu& Menu::operator<<(const char* text)
   {
      add(text);
      return *this;
   }

   Menu& Menu::operator=(const char* title)
   {
      if (title == nullptr)
         invalid = true;
      else
      {
         strncpy(this->heading, title, 50);
         this->invalid = false;
      }
      return *this;
   }

   void Menu::display(std::ostream& os) const
   {
      if (invalid)
      {
         std::cout << "Invalid Menu!" << std::endl;
      }
      else if (n_items == 0)
      {
         printIndentation(os);
         os << heading << std::endl;
         std::cout << "No Items to display!" << std::endl;
      }
      else
      {
         printIndentation(os);
         os << heading << std::endl;

         for (int i = 1; i <= n_items; i++)
         {
            printIndentation(os);
            os << i << "- ";
            m_items[i - 1]->display(os);
         }
         printIndentation(os);
         os << "> ";
      }
   }

   void Menu::printIndentation(std::ostream& os) const
   {
      for (int i = 0; i < indentation; i++)
      {
         os << "    ";
      }
   }

   int Menu::run() const
   {

      int choice = 0;

      display();
      if (!invalid && n_items > 0)
      {
         std::string input;
         do
         {

            std::cin >> input;
            if (isNumber(input))
            {
               choice = std::stoi(input);
               if (choice < 1 || choice > n_items)
               {
                  std::cout << "Invalid selection, try again: ";
                  choice = 0;
               }
               else
                  std::cin.ignore(1, '\n');
            }
            else
            {
               std::cout << "Invalid Integer, try again: ";
            }

         } while (!choice);
      }
      return choice;
   }

   Menu::operator int() const
   {
      return run();
   }

   void Menu::clear()
   {
      for (int i = 0; i < n_items; i++)
      {
         delete m_items[i];
         m_items[i] = nullptr;
      }
      n_items = 0;
   }

   Menu::~Menu()
   {
      for (int i = 0; i < n_items; i++)
         delete m_items[i];
   }

}