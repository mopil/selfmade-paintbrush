#include "MenuButton.h"
#include "MenuItem.h"

MenuButton::MenuButton(HDC hDC, int l, int t, int r, int b, string title, int id) 
	: Button(hDC, l, t, r, b, title, id),isDropped_(false)
{
	// empty
}


void MenuButton::closeItems() {
	list<MenuItem*> temp;
	for (auto i = menuItems_->begin(); i != menuItems_->end(); i++) {
		temp.push_back(*i);
	}

	for (auto i = temp.begin(); i != temp.end(); i++) {
		menuItems_->remove(*i);
	}
}

void MenuButton::addItem(MenuItem* mi) {
	menuItems_->push_back(mi);
}

void MenuButton::toggle() {
	if (isDropped_ == true) isDropped_ = false;
	else isDropped_ = true;
}

bool MenuButton::getState() { return isDropped_; }

void MenuButton::draw() {
	Button::draw();

	for (auto i = menuItems_->begin(); i != menuItems_->end(); i++) {
		(*i)->draw();
	}
}

