#include "MenuItem.h"

MenuItem::MenuItem(HDC hDC, int l, int t, int r, int b, std::string title)
	: Button(hDC, l, t, r, b, title)
{
	// empty
}



void MenuItem::draw() {
	//OutputDebugString(L"MenuItem draw »£√‚ µ \n");
	int correctX = 10, correctY = 10;
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_, right_, bottom_);
	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
}