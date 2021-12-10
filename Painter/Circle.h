#pragma once
#include "Figure.h"
#include <string>
using namespace std;

class Circle : public Figure {
public:
	Circle(HDC hDC, int l, int t, int r, int b, string color);
	void draw() override;
	void addPosition(int amountX, int amountY) override;
};