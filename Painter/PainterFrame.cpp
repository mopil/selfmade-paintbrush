#include "PainterFrame.h"
#include "Misc.h"
#include "Figure.h"
#include "Circle.h"
#include "Rect.h"
#include "GroupBox.h"
#include <iostream>
#include "MyButton.h"
#include "Button.h"
#include "ActionListener.h"
// �ϴ��� ���� ���� 1���� ����Ѵ�.
int shape_;

class SetShapeActionListener : public ActionListener {
private:
	PainterFrame* container_ = nullptr;
	int type_;
	static const int RECT_TYPE = 2;
	static const int CIRCLE_TYPE = 3;
public:
	SetShapeActionListener(PainterFrame* f, int type) :container_(f), type_(type) {}
	void actionPerformed() override {
		switch (type_) {
		case RECT_TYPE:
			OutputDebugString(L"�簢�� ��ư ���� ��\n");
			container_->setShape(RECT_TYPE);
			break;
		case CIRCLE_TYPE:
			OutputDebugString(L"Ÿ�� ��ư ���� ��\n");
			container_->setShape(CIRCLE_TYPE);
			break;
		}
	}
};

PainterFrame::PainterFrame() :PainterFrame(L"", 800, 600) {
	//
}
PainterFrame::PainterFrame(std::wstring title, int width, int height) :Frame(title,width,height){}

void PainterFrame::eventHandler(MyEvent e)
{
	
	if (e.isLButtonDown() || e.isRButtonDown()) {
		start_ = e.getPos();
	}
	else if (e.isLButtonUp()) {
		end_ = e.getPos();
		Button* selectedButton = findClickedButton();
		if (selectedButton != nullptr)
			selectedButton->onClick();
		if (e.isShiftKeyDown()) {
			createGroup();
		}
		else if (e.isCtrlKeyDown()) {
			Group* f = findClickedElement(start_);
			if (f) f->addPosition(end_.x_ - start_.x_, end_.y_ - start_.y_);
		}
		else if (shape_ == RECTANGLE){
			myGroupList.push_back(new Rect(hDC_,start_.x_, start_.y_, end_.x_, end_.y_));
		}
		else if (shape_ == CIRCLE) {
			myGroupList.push_back(new Circle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_));
		}
		invalidate();
	}
	else if (e.isRButtonUp()) {
		end_ = e.getPos();
		if (shape_ == RECTANGLE) {
			myGroupList.push_back(new Rect(hDC_, start_.x_, start_.y_, end_.x_, end_.y_));
		}
		else if (shape_ == CIRCLE) {
			myGroupList.push_back(new Circle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_));
		}
		invalidate();
	}
	
}

void PainterFrame::repaint() {
	// ��ư �׸���
	for (auto i = myButtonList.begin(); i != myButtonList.end(); i++) {
		(*i)->draw();
	}

	// ���� �׸���
	for (auto i = myGroupList.begin(); i != myGroupList.end(); i++) {
		(*i)->draw();
	}

}

void PainterFrame::setShape(int type) {
	shape_ = type;
}

void PainterFrame::createGroup() {
	GroupBox* newGroup = new GroupBox(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
	for (auto g = myGroupList.begin(); g != myGroupList.end(); g++) {
		MyPoint center = (*g)->getCenter();
		// ���� ���� �ִ� ��ҵ� �߰�
		if (newGroup->isIn(center)) {
			newGroup->addElement(*g);
			OutputDebugString(L"��� �׷쿡 �߰� ��\n");
		}
	}
	// �߰� �Ǿ��� ��Ҵ� ����
	newGroup->removeElements(myGroupList);
	myGroupList.push_front(newGroup);
	OutputDebugString(L"���ο� �׷� Ǫ�� ��\n");
	invalidate();
}

Group * PainterFrame::findClickedElement(MyPoint pos) {
	for (auto fig = myGroupList.begin(); fig != myGroupList.end(); fig++) {
		if ((*fig)->isIn(pos) == true) {
			OutputDebugString(L"���� ���� ��\n");
			return (*fig);
		}
	}
	// ��ã���� null ����
	return nullptr;
}

Button* PainterFrame::findClickedButton() {
	for (auto btn = myButtonList.begin(); btn != myButtonList.end(); btn++) {
		if ((*btn)->isIn(start_) == true) {
			return (*btn);
		}
	}
	// �� ���Ҵµ� ��ã���� null ����
	return nullptr;
}

void PainterFrame::init() {
	MyButton* btnRect = new MyButton(hDC_, 5, 5, 100, 50, "Rectangle", RECTANGLE);
	MyButton* btnCircle = new MyButton(hDC_, 120, 5, 215, 50, "Circle", CIRCLE);
	myButtonList.push_back(btnRect);
	myButtonList.push_back(btnCircle);
	btnRect->addActionListener(new SetShapeActionListener(this, RECTANGLE));
	btnCircle->addActionListener(new SetShapeActionListener(this, CIRCLE));
	btnRect->draw();
	btnCircle->draw();

}

