#include "MyButton.h"
#include "PainterFrame.h"

MyButton::MyButton(HDC hDC, int l, int t, int r, int b, std::string btnName,int type, PainterFrame *parent)
	: Button(hDC, l, t, r, b, btnName),type_(type),parent_(parent)
{
	// empty
}


void MyButton::onClick(MyEvent e) {
	switch (type_) {
	case RECT_TYPE:
		OutputDebugString(L"사각형 버튼 눌러 짐\n");
		parent_->setShape(RECT_TYPE);
		break;
	case CIRCLE_TYPE:
		OutputDebugString(L"타원 버튼 눌러 짐\n");
		parent_->setShape(CIRCLE_TYPE);
		break;
	}
}


void MyButton::show() {
	int correctX=0, correctY=0;
	switch (type_) {
	case RECT_TYPE:
		correctX = 32;
		correctY = 8;
		break;
	case CIRCLE_TYPE:
		correctX = 18;
		correctY = 6;
		break;
	}

	int centerX = left_ + ((right_ - left_) / 2) - correctX;
	int centerY = top_ + ((bottom_ - top_) / 2) - correctY;
	Rectangle(hDC_, left_, top_, right_, bottom_);
	TextOutA(hDC_, centerX, centerY, btn_name_.c_str(), strlen(btn_name_.c_str()));

}