#include "MyLabel.h"


MyLabel::MyLabel(HDC hDC, int l, int t, int r, int b, std::string title) :
	Label(hDC, l, t, r, b, title)
{
	// empty
}


void MyLabel::draw(int correctX, int correctY) {
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;

	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(80, 80, 80));

	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC_, myBrush);
	Rectangle(hDC_, left_, top_, right_, bottom_);

	SelectObject(hDC_, oldBrush);
	DeleteObject(myBrush);

	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
}
