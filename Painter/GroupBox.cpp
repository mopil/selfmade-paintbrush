#include "GroupBox.h"

void GroupBox::addElement(Group* element) {
	groupBox_->push_back(element);
}

GroupBox::GroupBox(HDC hdc, int l, int t, int r, int b):Group(hdc, l, t, r, b) 
{
	groupBox_ = new list<Group*>;
}

void GroupBox::draw() {
	HPEN myPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hDC_ , myPen);

	Rectangle(hDC_,left_, top_, right_, bottom_);

	SelectObject(hDC_, oldPen);
	DeleteObject(myPen);

	for (auto i = groupBox_->begin(); i != groupBox_->end(); i++) {
		(*i)->draw();
	}
}

void GroupBox::addPosition(int amountX, int amountY) {
	left_ += amountX;
	top_ += amountY;
	right_ += amountX;
	bottom_ += amountY;
	for (auto i = groupBox_->begin(); i != groupBox_->end(); i++) {
		(*i)->addPosition(amountX, amountY);
	}
}

void GroupBox::removeElements(list<Group *> &list) {
	for (auto i = groupBox_->begin(); i != groupBox_->end(); i++) {
		list.remove(*i);
		OutputDebugString(L"ø‰º“ ªË¡¶ µ \n");
	}
}
