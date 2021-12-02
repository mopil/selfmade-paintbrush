#include "Circle.h"

Circle::Circle(HDC hDC, int l, int t, int r, int b) : Figure(hDC, l, t, r, b) {}
void Circle::draw() {
	Ellipse(hDC_, left_, top_, right_, bottom_);

}

void Circle::addPosition(int amountX, int amountY) {
	left_ += amountX;
	top_ += amountY;
	right_ += amountX;
	bottom_ += amountY;
}