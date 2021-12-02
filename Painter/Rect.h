#pragma once
#include "Figure.h"

class Rect : public Figure {
public:
	Rect(HDC hDC, int l, int t, int r, int b);
	void addPosition(int amountX, int amountY) override;
	void draw() override ;
};