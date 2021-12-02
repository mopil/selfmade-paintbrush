#pragma once
#include "Windows.h"
#include <list>
using namespace std;

class MyPoint {
public:
	int x_, y_;
	MyPoint(int x, int y);
	MyPoint();
};

class MyEvent {
private:
	UINT msg_;
	WPARAM wParam_;
	LPARAM lParam_;
public:
	MyEvent(UINT msg, WPARAM wParam, LPARAM lParam);
	bool isLButtonDown();
	bool isLButtonUp();
	bool isRButtonDown();
	bool isRButtonUp();
	bool isCtrlKeyDown();
	bool isShiftKeyDown();
	int getX();
	int getY();
	MyPoint getPos();

};

