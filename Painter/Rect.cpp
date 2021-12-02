#include "Rect.h"

Rect::Rect(HDC hDC, int l, int t, int r, int b) : Figure(hDC, l, t, r, b) {}
void Rect::draw() {
	Rectangle(hDC_, left_, top_, right_, bottom_);
}

void Rect::addPosition(int amountX, int amountY) {
	left_ += amountX;
	top_ += amountY;
	right_ += amountX;
	bottom_ += amountY;
}