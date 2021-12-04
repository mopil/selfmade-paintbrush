#include "Component.h"


Component::Component(HDC hDC, int l, int t, int r, int b, std::string title) :
	hDC_(hDC), left_(l), top_(t), right_(r), bottom_(b), title_(title)
{
	// empty
}

void Component::draw(int correctX, int correctY) {
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_, right_, bottom_);
	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
}

void Component::setTitle(std::string title) {
	title_ = title;
}