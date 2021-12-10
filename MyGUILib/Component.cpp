#include "Component.h"
#include "ActionListener.h"
#include "Misc.h"


Component::Component(HDC hDC, int l, int t, int r, int b, string title, string type, int id) :
	hDC_(hDC), left_(l), top_(t), right_(r), bottom_(b), title_(title), type_(type), id_(id)
{
	// empty
}

void Component::draw() {
	int correctX = 10, correctY = 10;
	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_, right_, bottom_);
	TextOutA(hDC_, centerX, centerY, title_.c_str(), strlen(title_.c_str()));
}

void Component::setTitle(string title) {
	title_ = title;
}

string Component::getTitle() { return title_; }
string Component::getType() { return type_; }
int Component::getId() { return id_; }

bool Component::isIn(MyPoint pos) {
	if ((left_ <= pos.x_ && top_ <= pos.y_) && (right_ >= pos.x_ && bottom_ >= pos.y_)) {
		return true;
	}
	else {
		return false;
	}
}

void Component::addActionListener(ActionListener* l) {
	listeners_.push_back(l);
}