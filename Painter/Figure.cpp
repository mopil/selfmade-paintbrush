#include "Figure.h"
Figure::Figure(HDC hdc, int l, int t, int r, int b, string color) 
	:Group(hdc, l, t, r, b),color_(color)
{
	//empty
}

