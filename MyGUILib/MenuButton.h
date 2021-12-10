#pragma once
#include "Button.h"
#include <list>
#include <string>
using namespace std;

class MenuItem;
class MenuButton : public Button {
protected:
	list<MenuItem*>* menuItems_ = new list<MenuItem *>();
	bool isDropped_;
public:
	MenuButton(HDC hDC, int l, int t, int r, int b, string title);
	virtual void openItems() = 0;
	virtual void closeItems();
	virtual void addItem(MenuItem*);
	void toggle();
	bool getState();
	void draw() override;
};

