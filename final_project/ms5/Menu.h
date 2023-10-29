
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	const int MAX_CHARS_ALLOWED = 51;
	class MenuItem {
		char content[MAX_CHARS_ALLOWED];
		bool emptyState = false;

		MenuItem();
		MenuItem(const char* content);

		void setMenuItem(const char* c);
		void printMenuItem() const;
		void clearMenuItem();

		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;

		friend class Menu;
	};
	class Menu {
		char title[MAX_CHARS_ALLOWED];
		MenuItem menuItems[MAX_NO_OF_ITEMS] = {};

		int currentIndexOfMenuItems;
		int indentation;
	public:
		Menu() = default;
		Menu(const char* title, int indentation = 0);

		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;

		void clear();
		void setEmptyState();

		operator bool() const;
		bool isEmpty() const;
		void display() const;

		Menu& operator=(const char* newTitle);
		void add(const char* newMenuItem);
		Menu& operator<<(const char* newMenuItem);

		int run() const;
		operator int() const;
	};
}

#endif