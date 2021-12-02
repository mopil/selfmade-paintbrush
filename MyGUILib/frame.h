#pragma once
#include "Windows.h"
#include <string>
#include "Misc.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
class Frame {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.

public:
	Frame();
	Frame(std::wstring, int, int);
	virtual void run();
	void invalidate();

	virtual void eventHandler(MyEvent e) = 0;
	virtual void repaint() = 0;
	virtual void init() = 0;

};

