#include "MenuButton.h"
#include "MenuItem.h"

MenuButton::MenuButton(HDC hDC, int l, int t, int r, int b, string title) 
	: Button(hDC, l, t, r, b, title),isDropped_(false)
{
	// empty
}


void MenuButton::closeItems() {
	//OutputDebugString(L"closeItems »£√‚ µ \n");
	list<MenuItem*> temp;
	for (auto i = menuItems_->begin(); i != menuItems_->end(); i++) {
		temp.push_back(*i);
	}

	for (auto i = temp.begin(); i != temp.end(); i++) {
		menuItems_->remove(*i);
	}
}

void MenuButton::addItem(MenuItem* mi) {
	//OutputDebugString(L"addItem »£√‚ µ \n");
	menuItems_->push_back(mi);
}

void MenuButton::toggle() {
	//OutputDebugString(L"toggle »£√‚ µ \n");
	if (isDropped_ == true) isDropped_ = false;
	else isDropped_ = true;
}

bool MenuButton::getState() { return isDropped_; }

void MenuButton::draw() {
	//OutputDebugString(L"MenuButton draw »£√‚ µ \n");
	int correctX = 10, correctY = 10;
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_, right_, bottom_);
	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));

	for (auto i = menuItems_->begin(); i != menuItems_->end(); i++) {
		(*i)->draw();
	}
}

