#pragma once
#include "Figure.h"

class Circle : public Figure {
public:
	Circle(HDC hDC, int l, int t, int r, int b);
	void draw() override;
	void addPosition(int amountX, int amountY) override;
};