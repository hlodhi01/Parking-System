/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/8  Preliminary release
2022/11/8  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/#ifndef SDDS_MENU_H_

#define SDDS_MENU_H_
#define MAX_NO_OF_ITEMS 10
#include <iostream>
namespace sdds {
    class MenuItem {
        char TLeValue[51];
        MenuItem();
        MenuItem(const char* inVal);
        std::ostream& display(std::ostream& refVal = std::cout)const;
        void setEmpty();


        MenuItem(const MenuItem& refPassed) = delete;
        MenuItem& operator=(const MenuItem& refPassed) = delete;

    public:
        friend class Menu;
    };
    class Menu {
        char title_value[51];
        MenuItem list_obj[MAX_NO_OF_ITEMS];
        int items;
        int val;
    public:
        Menu();
        Menu(const char* inVal, int indentation = 0);
        operator bool()const;
        bool isEmpty()const;
        std::ostream& display(std::ostream& refVal = std::cout)const;
        std::ostream& indent(std::ostream& refVal = std::cout)const;
        Menu& operator=(const char* title);
        void setEmpty();
        Menu& operator<<(const char* item);
        Menu& operator=(const Menu& refPassed) = delete;
        int run()const;
        operator int()const;
        void add(const char* item);
        void clear();

        Menu(const Menu& refPassed) = delete;
    };
}
#endif