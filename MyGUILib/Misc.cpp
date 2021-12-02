#include "Misc.h"

MyEvent::MyEvent(UINT msg, WPARAM wParam, LPARAM lParam) :
	msg_(msg), wParam_(wParam), lParam_(lParam) 
{
	//  Nothing to do here.
}

bool MyEvent::isLButtonDown() {
	return msg_ == WM_LBUTTONDOWN;
}
bool MyEvent::isLButtonUp() {
	return msg_ == WM_LBUTTONUP;
}
bool MyEvent::isRButtonDown() {
	return msg_ == WM_RBUTTONDOWN;
}
bool MyEvent::isRButtonUp() {
	return msg_ == WM_RBUTTONUP;
}
bool MyEvent::isCtrlKeyDown() {
	return wParam_ & MK_CONTROL;
}
bool MyEvent::isShiftKeyDown() {
	return wParam_ & MK_SHIFT;
}

int MyEvent::getX() {
	return LOWORD(lParam_);
}

int MyEvent::getY() {
	return HIWORD(lParam_);
}

MyPoint MyEvent::getPos() {
	return MyPoint(LOWORD(lParam_), HIWORD(lParam_));
}

MyPoint::MyPoint(int x, int y): x_(x), y_(y){

}

MyPoint::MyPoint() : x_(0), y_(0) {

}