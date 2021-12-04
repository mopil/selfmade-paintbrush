#include "Button.h"
#include "ActionListener.h"

Button::Button(HDC hDC, int l, int t, int r, int b, std::string btnName)
	: hDC_(hDC), left_(l), top_(t), right_(r), bottom_(b), btn_name_(btnName)
{
	// empty
}


bool Button::isIn(MyPoint pos) {
	if ((left_ <= pos.x_ && top_ <= pos.y_) && (right_ >= pos.x_ && bottom_ >= pos.y_)) {
		return true;
	}
	else {
		return false;
	}
}

void Button::addActionListener(ActionListener* l) {
	listeners_.push_back(l);
}

void Button::onClick() {
	for (auto i : listeners_) {
		i->actionPerformed();
	}
}