
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {

	MenuItem::MenuItem() {
		strcpy(content, "");
	}

	MenuItem::MenuItem(const char* c) {
		setMenuItem(c);
	}

	void MenuItem::setMenuItem(const char* c) {
		if (c != nullptr && strlen(c) > 0) {
			strcpy(content, c);
			emptyState = false;
		}
		else {
			emptyState = true;
		}
	}

	void MenuItem::printMenuItem() const {
		if (!emptyState) {
			cout << content << endl;
		}
	}

	void MenuItem::clearMenuItem() {
		strcpy(content, "");
	}


	Menu::Menu(const char* newTitle, int indentation) {

		if (newTitle != nullptr && strlen(newTitle) > 0 && indentation >= 0) {
			strcpy(title, newTitle);
			currentIndexOfMenuItems = 0;
			this->indentation = indentation;
		}
		else {
			setEmptyState();
		}
	}



	Menu::operator bool() const {
		if (title != nullptr && indentation >= 0) {
			return true;
		}
		return false;
	}


	bool Menu::isEmpty() const {
		if (title != nullptr && indentation >= 0) {
			return false;
		}
		return true;
	}



	void Menu::setEmptyState() {
		strcpy(title, "");
		indentation = -1;
		currentIndexOfMenuItems = -1;
	}


	void Menu::display() const {
		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else {
			for (int i = 0; i < indentation * 4; i++) {
				cout << " ";
			}
			cout << title << endl;
			if (currentIndexOfMenuItems <= 0) {
				cout << "No Items to display!" << endl;
			}
			else {

				for (int i = 0; i < currentIndexOfMenuItems; i++) {
					for (int i = 0; i < indentation * 4; i++) {
						cout << " ";
					}
					cout << i + 1 << "- ";
					menuItems[i].printMenuItem();
				}
				for (int i = 0; i < indentation * 4; i++) {
					cout << " ";
				}
				cout << "> ";
			}
		}
	}


	Menu& Menu::operator=(const char* newTitle) {
		if (strlen(newTitle) > 0) {
			strcpy(title, newTitle);
		}
		else {
			setEmptyState();
		}
		return *this;
	}


	void Menu::add(const char* c) {
		if (currentIndexOfMenuItems < 10 && !isEmpty() && c != nullptr) {
			menuItems[currentIndexOfMenuItems].setMenuItem(c);
			currentIndexOfMenuItems++;
		}
		else {
			setEmptyState();
		}
	}

	void Menu::clear() {
		strcpy(title, "");
		for (int i = 0; i < currentIndexOfMenuItems; i++) {
			menuItems[i].clearMenuItem();
		}
		indentation = 0;
		currentIndexOfMenuItems = 0;
	}

	Menu& Menu::operator<<(const char* newMenuItem) {
		add(newMenuItem);
		return *this;
	}


	int Menu::run() const {
		bool validUserResponse = false;
		int userSelection = 0;

		display();
		if (!isEmpty() && currentIndexOfMenuItems > 0) {

			while (!validUserResponse) {
				cin >> userSelection;
				if (cin.fail()) {
					cin.clear();
					cout << "Invalid Integer, try again: ";
				}
				else {
					if (userSelection < 1 || userSelection > currentIndexOfMenuItems) {
						cout << "Invalid selection, try again: ";
					}
					else {
						validUserResponse = true;
					}
				}
				cin.ignore(1000, '\n');
			}
		}
		return userSelection;
	}
	Menu::operator int() const {
		int userSelection = 0;
		userSelection = run();
		return userSelection;
	}

}