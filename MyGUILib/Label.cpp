#include "Label.h"

Label::Label(HDC hDC, int l, int t, int r, int b, std::string title) :
	Component(hDC, l, t, r, b, title)
{
	// empty
}

//void Label::setTitle(std::string title) {
//	title_ = title;
//}
//
//void Label::draw(int correctX, int correctY) {
//	int centerX = left_ + ((right_ - left_) / 2) - correctX;
//	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
//	Rectangle(hDC_, left_, top_, right_, bottom_);
//	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
//}