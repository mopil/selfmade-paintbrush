#pragma once
#include <Windows.h>
#include <string>
#include "Misc.h"
#include "Button.h"


class PainterFrame;
class MyButton : public Button{
private:
	static const int RECT_TYPE = 2;
	static const int CIRCLE_TYPE = 3;
	PainterFrame* parent_;
	int type_;
public:
	MyButton(HDC hDC, int l, int t, int r, int b, std::string btnName,int type, PainterFrame *parent);
	void show() override;
	void onClick(MyEvent e) override;
};

