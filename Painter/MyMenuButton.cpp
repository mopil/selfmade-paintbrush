#include "MyMenuButton.h"
#include "MenuItem.h"

MyMenuButton::MyMenuButton(HDC hDC, int l, int t, int r, int b, string title)
	: MenuButton(hDC, l, t, r, b, title)
{
	// empty
}

void MyMenuButton::openItems() {
	MenuItem* menuItemRectangle = new MenuItem(hDC_, 0, 100, 100, 120, "사각형");
	MenuItem* menuItemRectangle2 = new MenuItem(hDC_, 0, 200, 100, 180, "사각형2");
	MenuItem* menuItemRectangle3 = new MenuItem(hDC_, 0, 300, 100, 240, "사각형3");
	this->addItem(menuItemRectangle);
	this->addItem(menuItemRectangle2);
	this->addItem(menuItemRectangle3);
}