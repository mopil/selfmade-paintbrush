#pragma once
#include <Windows.h>
#include <string>
#include "Misc.h"
#include "Button.h"

class MyButton : public Button{
private:
	static const int RECT_TYPE = 2;
	static const int CIRCLE_TYPE = 3;
	int type_;
public:
	MyButton(HDC hDC, int l, int t, int r, int b, std::string title,int type);
	//void draw(int correctX, int correctY) override;
	int getType();
};

