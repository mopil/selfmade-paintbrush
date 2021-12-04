#include "Component.h"


Component::Component(HDC hDC, int l, int t, int r, int b) :
	hDC_(hDC), left_(l), top_(t), right_(r), bottom_(b)
{
	// empty
}