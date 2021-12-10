#include "Label.h"

Label::Label(HDC hDC, int l, int t, int r, int b, string title, int id) :
	Component(hDC, l, t, r, b, title, "Label", id)
{
	// empty
}

void Label::draw() {
	int correctX = 50, correctY = 10;
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_, right_, bottom_);
	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
}