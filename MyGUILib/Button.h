#pragma once
#include <Windows.h>
#include <string>
#include "Misc.h"
using namespace std;

class Frame;
class Button {
protected:
	int left_, top_, right_, bottom_;
	HDC hDC_;
	string btn_name_;
public:
	Button(HDC hDC, int l, int t, int r, int b, string btnName);
	virtual void show() = 0;
	virtual void onClick(MyEvent e) = 0;
	bool isIn(MyPoint pos);

};
