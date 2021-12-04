#pragma once
#include <Windows.h>

class Component {
protected:
	int left_, top_, right_, bottom_;
	HDC hDC_;
public :
	Component(HDC hDC, int l, int t, int r, int b);

};

