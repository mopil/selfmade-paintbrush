#include "Figure.h"
Figure::Figure(HDC hdc, int l, int t, int r, int b, string color, bool fill) 
	:Group(hdc, l, t, r, b),color_(color),fill_(fill)
{
	//empty
}

