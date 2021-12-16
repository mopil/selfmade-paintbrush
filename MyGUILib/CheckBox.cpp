#include "CheckBox.h"

CheckBox::CheckBox(HDC hDC, int l, int t, int r, int b, string title, int id) :
	Button(hDC, l, t, r, b, title, id) 
{
	// empty
}

void CheckBox::toggle() {
	if (isChecked_ == true) isChecked_ = false;
	else isChecked_ = true;
}

void CheckBox::draw() {
	Component::draw();
	HBRUSH myBrush;
	if (isChecked_ == true) {
		myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
	}
	else {
		myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	}
	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC_, myBrush);
	Ellipse(hDC_, left_+20, top_+25, right_-70, bottom_-25); // 300, 0, 400, 60
	SelectObject(hDC_, oldBrush);
	DeleteObject(myBrush);
}