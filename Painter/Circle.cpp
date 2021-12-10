#include "Circle.h"

Circle::Circle(HDC hDC, int l, int t, int r, int b, string color) 
	: Figure(hDC, l, t, r, b, color)
{
	// empty
}
void Circle::draw() {

	HPEN myPen;
	if (color_ == "Red") myPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	else if (color_ == "Blue") myPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	else if (color_ == "Green") myPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	else myPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hDC_, myPen);
	Ellipse(hDC_, left_, top_, right_, bottom_);
	SelectObject(hDC_, oldPen);
	DeleteObject(myPen);

}

void Circle::addPosition(int amountX, int amountY) {
	left_ += amountX;
	top_ += amountY;
	right_ += amountX;
	bottom_ += amountY;
}