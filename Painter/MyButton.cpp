#include "MyButton.h"
#include "PainterFrame.h"

MyButton::MyButton(HDC hDC, int l, int t, int r, int b, std::string title,int type)
	: Button(hDC, l, t, r, b, title),type_(type)
{
	// empty
}

int MyButton::getType() { return type_; }