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
#include "MyMenuBar.h"
#include "FigureMenuButton.h"
#include "MenuItem.h"

// �ϴ��� ���� ���� 1���� ����Ѵ�.
int shape_;


class SetLabelActionListener : public ActionListener {
private:
	MyLabel* label_;
	string title_;

public:
	SetLabelActionListener(MyLabel* l, string title) :label_(l),title_(title) {}
	void actionPerformed() override {
		label_->setTitle(title_);
	}

};

class ResetActionListener : public ActionListener {
private:
	PainterFrame* container_;
	list <Group*> * targetList_;
public:
	ResetActionListener(PainterFrame* f, list <Group *> * targetList) :container_(f),targetList_(targetList) {}
	void actionPerformed() override {
		container_->resetList(targetList_);
	}
};


class DropDownActionListener : public ActionListener {
private:
	PainterFrame* container_;
	MenuButton* menuButton_;
public:
	DropDownActionListener(MenuButton* mb, PainterFrame *c) :menuButton_(mb),container_(c) {};
	void actionPerformed() override {
		// isDropped == false
		if (menuButton_->getState() == false) {
			menuButton_->openItems();
		}
		// isDropped == true
		else {
			menuButton_->closeItems();
		}
		menuButton_->toggle();
		container_->invalidate();
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
		MyButton* selectedButton = findClickedButton(end_);
		if (selectedButton != nullptr) {
			selectedButton->onClick();
		}
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
	//OutputDebugString(L"repaint ȣ�� ��\n");

	// ���� �׸���
	for (auto i = myGroupList.begin(); i != myGroupList.end(); i++) {
		(*i)->draw();
	}

	// ������Ʈ �׸���
	for (auto i = componentList.begin(); i != componentList.end(); i++) {
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

Group* PainterFrame::findClickedElement(MyPoint pos) {
	for (auto fig = myGroupList.begin(); fig != myGroupList.end(); fig++) {
		if ((*fig)->isIn(pos) == true) {
			OutputDebugString(L"���� ���� ��\n");
			return (*fig);
		}
	}
	// ��ã���� null ����
	return nullptr;
}

MyButton* PainterFrame::findClickedButton(MyPoint pos) {
	for (auto btn = componentList.begin(); btn != componentList.end(); btn++) {
		if ( ((MyButton *)(*btn))->isIn(pos) == true) {
			OutputDebugString(L"��ư ���� ��\n");
			return (MyButton *)(*btn);
		}
	}
	// ��ã���� null ����
	return nullptr;
}

void PainterFrame::init() {
	//MyButton* btnRect = new MyButton(hDC_, 5, 5, 100, 50, "Rectangle", RECTANGLE);
	//MyButton* btnCircle = new MyButton(hDC_, 120, 5, 215, 50, "Circle", CIRCLE);
	//componentList.push_back(btnRect);
	//componentList.push_back(btnCircle);
	//btnRect->addActionListener(new SetShapeActionListener(this, RECTANGLE));
	//btnCircle->addActionListener(new SetShapeActionListener(this, CIRCLE));

	//// �� ����
	//MyLabel* labelMain = new MyLabel(hDC_, 230, 5, 965, 115, "MAIN");
	//componentList.push_back(labelMain);

	//MyButton* btnReset = new MyButton(hDC_, 5, 70, 100, 115, "Reset", RESET);
	//MyButton* btnBanana = new MyButton(hDC_, 120, 70, 215, 115, "Banana", BANANA);
	//btnReset->addActionListener(new ResetActionListener(this, &myGroupList));
	//btnBanana->addActionListener(new SetLabelActionListener(labelMain, "Banana"));
	//componentList.push_back(btnReset);
	//componentList.push_back(btnBanana);

	//MyMenuBar* menuBar = new MyMenuBar(hDC_, 0, 0, 1000, 60, "���θ޴���");
	//componentList.push_back(menuBar);
	FigureMenuButton* menuBtnFigure = new FigureMenuButton(hDC_, 0, 0, 100, 60, "����", this);
	menuBtnFigure->addActionListener(new DropDownActionListener(menuBtnFigure, this));
	componentList.push_back(menuBtnFigure);
	//menuBar->addMenuButton(menuBtnFigure);
	//menuBar->init();
}

void PainterFrame::resetList(list<Group*> *groupList) {
	list <Group*> tempList;
	for (auto i = groupList->begin(); i != groupList->end(); i++) {
		tempList.push_back(*i);
	}

	for (auto i = tempList.begin(); i != tempList.end(); i++) {
		groupList->remove(*i);
		OutputDebugString(L"��� ���� ��\n");
	}
	OutputDebugString(L"����Ʈ �ʱ�ȭ �Ϸ�\n");
}

void PainterFrame::addComponent(Component* c) {
	componentList.push_back(c);
}

void PainterFrame::removeComponent(std::string title) {
	list <Component*> tempList;
	for (auto i = componentList.begin(); i != componentList.end(); i++) {
		tempList.push_back(*i);
	}

	for (auto i = tempList.begin(); i != tempList.end(); i++) {
		if (title == (*i)->getTitle()) {
			componentList.remove(*i);
			OutputDebugString(L"��� ���� ��\n");
			return;
		}
	}
}