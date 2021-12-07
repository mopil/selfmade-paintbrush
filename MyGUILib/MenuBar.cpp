#include "MenuBar.h"
#include "ActionListener.h"
#include "MenuButton.h"

MenuBar::MenuBar(HDC hDC, int l, int t, int r, int b, string title) :
	Component(hDC, l, t, r, b, title)
{
	// empty
}

//void MenuBar::addMenuButton(MenuButton* mb) {
//	menuButtonList_->push_back(mb);
//}

void MenuBar::draw() {
	HPEN myPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hDC_, myPen);

	Rectangle(hDC_, left_, top_, right_, bottom_);

	SelectObject(hDC_, oldPen);
	DeleteObject(myPen);
}