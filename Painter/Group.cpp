#include "Group.h"

Group::Group(HDC hdc, int l, int t, int r, int b)
	:hDC_(hdc), left_(l), top_(t), right_(r), bottom_(b)
{
	// empty
}

MyPoint Group::getCenter() {
	int centerX = left_ + ((right_ - left_) / 2);
	int centerY = top_ + ((bottom_ - top_) / 2);
	return 	MyPoint(centerX, centerY);
}

bool Group::isIn(MyPoint  pos) {
	if ((left_ <= pos.x_ && top_ <= pos.y_) && (right_ >= pos.x_ && bottom_ >= pos.y_)) {
		return true;
	}
	else {
		return false;
	}
}


