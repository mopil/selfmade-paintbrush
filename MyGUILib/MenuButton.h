#pragma once
#include "Button.h"
#include <list>
#include <string>
using namespace std;

class MenuItem;
class MenuButton : public Button {
protected:
	list<MenuItem*>* menuItems_ = new list<MenuItem *>();
public:
	MenuButton(HDC hDC, int l, int t, int r, int b, string title);
	void showItems();
	void addItem(MenuItem*);
};

