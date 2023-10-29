/*  Name                : Harsh Lodhi
    Seneca E-mail       : hlodhi1@myseneca.ca
    Student ID          : 169677218
    Date                : 12 november 2022
 */

// I hereby declare that all the work is completed by me and no part of this is shared with anyone.
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
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds {

    MenuItem::MenuItem()
    {
        setEmpty();
    }


    ostream& MenuItem::display(ostream& refVal) const
    {
        if (TLeValue[0] != 0) {
            refVal << TLeValue << endl;
        }
        return refVal;
    }

    MenuItem::MenuItem(const char* inVal)
    {
        if (inVal != nullptr) {
            strncpy(TLeValue, inVal, 50);
            TLeValue[50] = 0;
        }
        else {
            setEmpty();
        }
    }



    void MenuItem::setEmpty()
    {
        TLeValue[0] = 0;
    }




    Menu::Menu()
    {
        setEmpty();
    }



    Menu::operator bool() const
    {
        return (title_value[0] != 0);
    }


    bool Menu::isEmpty() const
    {
        return (title_value[0] == 0);
    }


    Menu::Menu(const char* inVal, int indentation)
    {
        if (inVal != nullptr) {
            strncpy(title_value, inVal, 50);
            title_value[50] = 0;
            items = 0;
            val = indentation;
        }
        else {
            setEmpty();
        }
    }

    void Menu::setEmpty()
    {
        title_value[0] = 0;
        for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
            list_obj[i].TLeValue[0] = '\0';
        }
        items = 0;
        val = 0;
    }



    std::ostream& Menu::indent(std::ostream& refVal) const
    {

        if (val != 0) {
            for (int i = 0; i < val; i++)
            {
                refVal << "    ";
            }
        }
        return refVal;
    }

    Menu& Menu::operator=(const char* title)
    {
        if (title != nullptr) {
            strncpy(title_value, title, 50);
            title_value[50] = 0;
        }
        return *this;
    }

    std::ostream& Menu::display(std::ostream& refVal) const
    {
        if (title_value[0] == 0)
        {
            refVal << "Invalid Menu!" << endl;
        }
        else if (items == 0)
        {
            refVal << title_value << endl;
            refVal << "No Items to display!" << endl;
        }
        else {
            indent(refVal);
            refVal << title_value << endl;
            for (int i = 0; i < items; i++)
            {
                indent(refVal);
                refVal << i + 1 << "-";
                refVal << " " << list_obj[i].TLeValue << endl;
            }
            indent(refVal);
            refVal << "> ";
        }
        return refVal;
    }


    Menu& Menu::operator<<(const char* item)
    {
        if (item != nullptr) {
            add(item);
        }
        else {
            setEmpty();
        }
        return *this;

    }
    void Menu::add(const char* item)
    {
        if (list_obj[9].TLeValue[0] != '\0' || isEmpty()) {

        }
        else {
            if (item == nullptr) {
                setEmpty();
            }
            else {
                if (list_obj[items].TLeValue[0] == '\0') {
                    strncpy(list_obj[items].TLeValue, item, 50);
                    items++;
                }
            }
        }
    }


    void Menu::clear()
    {
        setEmpty();
    }


    int Menu::run() const
    {
        int AA;
        display();
        if (items == 0 || isEmpty())
        {
            AA = 0;
        }
        else
        {

            do {
                do {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "Invalid Integer, try again: ";
                    }
                    cin >> AA;
                    cin.ignore(1000, '\n');
                } while (cin.fail());
                if (AA < 1 || AA > items) {
                    cout << "Invalid selection, try again: ";
                }
            } while (AA < 1 || AA > items);
        }

        return AA;
    }
    Menu::operator int() const
    {
        return run();
    }
}