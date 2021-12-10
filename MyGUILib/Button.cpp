#include "Button.h"
#include "ActionListener.h"

Button::Button(HDC hDC, int l, int t, int r, int b, string title, int id)
	: Component(hDC,l,t,r,b,title,"Button",id)
{
	// empty
}
