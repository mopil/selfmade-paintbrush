#include "MenuItem.h"

MenuItem::MenuItem(HDC hDC, int l, int t, int r, int b, std::string title, MenuButton* parent)
	: Component(hDC, l, t, r, b, title), parentButton_(parent)
{
	// empty
}


void MenuItem::draw(int nextY) {
	int correctX = 10, correctY = 10;
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_+nextY, right_, bottom_+nextY);
	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
}

void MenuItem::draw() {
	int correctX = 10, correctY = 10;
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_, right_, bottom_);
	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
}

MenuButton* MenuItem::getParent() { return parentButton_; }