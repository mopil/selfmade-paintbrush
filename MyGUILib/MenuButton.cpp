#include "MenuButton.h"
#include "MenuItem.h"

MenuButton::MenuButton(HDC hDC, int l, int t, int r, int b, string title) 
	: Button(hDC, l, t, r, b, title) 
{
	// empty
}


void MenuButton::showItems() {
	auto item = menuItems_->begin();
	(*item)->draw();
	while (item != menuItems_->end()) {
		item++;
		(*item)->draw(100);
	}

}

void MenuButton::addItem(MenuItem* mi) {
	menuItems_->push_back(mi);
}