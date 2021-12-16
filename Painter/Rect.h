#pragma once
#include "Figure.h"
#include <string>
using namespace std;

class Rect : public Figure {
public:
	Rect(HDC hDC, int l, int t, int r, int b, string color, bool fill);
	void addPosition(int amountX, int amountY) override;
	void draw() override ;
};