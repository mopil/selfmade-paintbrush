#include "Rect.h"

Rect::Rect(HDC hDC, int l, int t, int r, int b, string color, bool fill) 
	: Figure(hDC, l, t, r, b, color,fill) 
{
	//empty
}
void Rect::draw() {

	HPEN myPen;
	HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));;
	if (color_ == "Red") {
		myPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		if (fill_ == true) 	myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
		else myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	}
	else if (color_ == "Blue") {
		myPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		if (fill_ == true) 	myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 255));
		else myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	}
	else if (color_ == "Green") {
		myPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		if (fill_ == true) 	myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
		else myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	}
	else {
		myPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	}
	HPEN oldPen = (HPEN)SelectObject(hDC_, myPen);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC_, myBrush);

	Rectangle(hDC_, left_, top_, right_, bottom_);

	SelectObject(hDC_, oldPen);
	DeleteObject(myPen);

	SelectObject(hDC_, oldBrush);
	DeleteObject(myBrush);


}

void Rect::addPosition(int amountX, int amountY) {
	left_ += amountX;
	top_ += amountY;
	right_ += amountX;
	bottom_ += amountY;
}