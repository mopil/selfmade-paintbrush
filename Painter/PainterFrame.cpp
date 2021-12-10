#include "PainterFrame.h"
#include "Misc.h"
#include "Figure.h"
#include "Circle.h"
#include "Rect.h"
#include "GroupBox.h"
#include <iostream>
#include "Button.h"
#include "ActionListener.h"
#include "FigureMenuButton.h"
#include "MenuItem.h"
#include "Label.h"
#include "ColorMenuButton.h"

// 전역 변수
string shape_;
string color_ = "Red";

class SetLabelActionListener : public ActionListener {
private:
	Label* label_;
	string title_;

public:
	SetLabelActionListener(Label* l, string title) :label_(l),title_(title) {}
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

class NoActionListener : public ActionListener {
public:
	NoActionListener(){}
	void actionPerformed() override {
		// empty
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
		Button* selectedButton = findClickedButton(end_);
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
		else if (shape_ == "Rectangle") {
			myGroupList.push_back(new Rect(hDC_,start_.x_, start_.y_, end_.x_, end_.y_, color_));
		}
		else if (shape_ == "Circle") {
			myGroupList.push_back(new Circle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_, color_));
		}
		invalidate();
	}
	else if (e.isRButtonUp()) {
		end_ = e.getPos();
		if (shape_ == "Rectangle") {
			myGroupList.push_back(new Rect(hDC_, start_.x_, start_.y_, end_.x_, end_.y_, color_));
		}
		else if (shape_ == "Circle") {
			myGroupList.push_back(new Circle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_, color_));
		}
		invalidate();
	}
	
}

void PainterFrame::repaint() {
	//OutputDebugString(L"repaint 호출 됨\n");

	// 도형 그리기
	for (auto i = myGroupList.begin(); i != myGroupList.end(); i++) {
		(*i)->draw();
	}

	// 컴포넌트 그리기
	for (auto i = componentList.begin(); i != componentList.end(); i++) {
		(*i)->draw();
	}

}

void PainterFrame::setShape(string type) {
	shape_ = type;
}

void PainterFrame::setColor(string color) {
	color_ = color;
}

void PainterFrame::createGroup() {
	GroupBox* newGroup = new GroupBox(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
	for (auto g = myGroupList.begin(); g != myGroupList.end(); g++) {
		MyPoint center = (*g)->getCenter();
		// 범위 내에 있는 요소들 추가
		if (newGroup->isIn(center)) {
			newGroup->addElement(*g);
			//OutputDebugString(L"요소 그룹에 추가 됨\n");
		}
	}
	// 추가 되었던 요소는 삭제
	newGroup->removeElements(myGroupList);
	myGroupList.push_front(newGroup);
	//OutputDebugString(L"새로운 그룹 푸시 됨\n");
	invalidate();
}

Group* PainterFrame::findClickedElement(MyPoint pos) {
	for (auto fig = myGroupList.begin(); fig != myGroupList.end(); fig++) {
		if ((*fig)->isIn(pos) == true) {
			//OutputDebugString(L"도형 선택 됨\n");
			return (*fig);
		}
	}
	// 못찾으면 null 리턴
	return nullptr;
}

Button* PainterFrame::findClickedButton(MyPoint pos) {
	for (auto btn = componentList.begin(); btn != componentList.end(); btn++) {
		if ( ((Button *)(*btn))->isIn(pos) == true) {
			//OutputDebugString(L"버튼 선택 됨\n");
			return (Button *)(*btn);
		}
	}
	// 못찾으면 null 리턴
	return nullptr;
}

void PainterFrame::init() {

	// 현재 상태 라벨
	Label* labelMain = new Label(hDC_, 500, 0, 999, 60, "",2001);
	labelMain->addActionListener(new NoActionListener());
	componentList.push_back(labelMain);

	// 도형 메뉴버튼
	FigureMenuButton* menuBtnFigure = new FigureMenuButton(hDC_, 0, 0, 100, 60, "도형", 4,this);
	menuBtnFigure->addActionListener(new DropDownActionListener(menuBtnFigure, this));
	componentList.push_back(menuBtnFigure);

	// 색깔 메뉴버튼
	ColorMenuButton* menuBtnColor = new ColorMenuButton(hDC_, 100, 0, 200, 60, "색깔", 5, this);
	menuBtnColor->addActionListener(new DropDownActionListener(menuBtnColor, this));
	componentList.push_back(menuBtnColor);

	// 리셋 버튼
	Button* btnReset = new Button(hDC_, 300, 0, 400, 60, "리셋",1001);
	btnReset->addActionListener(new ResetActionListener(this, &myGroupList));
	btnReset->addActionListener(new SetLabelActionListener(labelMain, "그림판 초기화 완료"));
	componentList.push_back(btnReset);
}

void PainterFrame::resetList(list<Group*> *groupList) {
	list <Group*> tempList;
	for (auto i = groupList->begin(); i != groupList->end(); i++) {
		tempList.push_back(*i);
	}

	for (auto i = tempList.begin(); i != tempList.end(); i++) {
		groupList->remove(*i);
		//OutputDebugString(L"요소 삭제 됨\n");
	}
	//OutputDebugString(L"리스트 초기화 완료\n");
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
			//OutputDebugString(L"요소 삭제 됨\n");
			return;
		}
	}
}
void PainterFrame::toggleAll() {
	for (auto btn = componentList.begin(); btn != componentList.end(); btn++) {
		if (((MenuButton*)(*btn))->getState() == true || ((MenuButton*)(*btn))->getState() == false) {
			//OutputDebugString(L"토글\n");
			((MenuButton*)(*btn))->toggle();
		}
	}
}

Component* PainterFrame::getComponent(string type, int id) {
	for (auto c = componentList.begin(); c != componentList.end(); c++) {
		if ( (*c)->getId() == id) {
			if (type == "Button") return (Button*)(*c);
			if (type == "Label") return (Label*)(*c);
		}
	}
}