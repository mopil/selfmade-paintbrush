#pragma once
#include <Windows.h>
#include "Misc.h"

class Group {
protected:
	int left_, top_, right_, bottom_;
	HDC hDC_;
public:
	Group(HDC hDC, int l, int t, int r, int b);
	MyPoint getCenter();
	bool isIn(MyPoint pos);
	virtual void addPosition(int amountX, int amountY) = 0;
	virtual void draw() = 0;
};

