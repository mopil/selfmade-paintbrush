#pragma once
#include "Button.h"
#include <string>
using namespace std;
class MenuItem : public Button {
public:
	MenuItem(HDC hDC, int l, int t, int r, int b, string title);
	virtual void draw();
};

