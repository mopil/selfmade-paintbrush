#include "PainterFrame.h"
#include "Misc.h"
#include "Circle.h"
#include "Rect.h"
#include "GroupBox.h"
#include "Button.h"
#include "Label.h"
#include "MyMenuBar.h"

// 전역 변수
string shape_;
string color_;

PainterFrame::PainterFrame() :PainterFrame(L"", 800, 600) {
	// empty
}
PainterFrame::PainterFrame(std::wstring title, int width, int height) :Frame(title,width,height){}

void PainterFrame::eventHandler(MyEvent e)
{
	Label* labelMain = (Label*)getComponent("Label", 2001);
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
			labelMain->setTitle("그룹 생성 됨");
		}
		else if (e.isCtrlKeyDown()) {
			Group* f = findClickedElement(start_);
			if (f) f->addPosition(end_.x_ - start_.x_, end_.y_ - start_.y_);
			labelMain->setTitle("도형/그룹 이동 됨");
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
		}
	}
	// 추가 되었던 요소는 삭제
	newGroup->removeElements(myGroupList);
	myGroupList.push_front(newGroup);
	invalidate();
}

Group* PainterFrame::findClickedElement(MyPoint pos) {
	for (auto fig = myGroupList.begin(); fig != myGroupList.end(); fig++) {
		if ((*fig)->isIn(pos) == true) {
			return (*fig);
		}
	}
	return nullptr;
}

Button* PainterFrame::findClickedButton(MyPoint pos) {
	for (auto btn = componentList.begin(); btn != componentList.end(); btn++) {
		if ( ((Button *)(*btn))->isIn(pos) == true) {
			return (Button *)(*btn);
		}
	}
	return nullptr;
}

void PainterFrame::init() {

	MyMenuBar* mainMenuBar = new MyMenuBar(hDC_, 0, this);
	componentList.push_back(mainMenuBar);
	mainMenuBar->init();
	
}

void PainterFrame::resetList() {
	list <Group*> tempList;
	for (auto i = myGroupList.begin(); i != myGroupList.end(); i++) {
		tempList.push_back(*i);
	}

	for (auto i = tempList.begin(); i != tempList.end(); i++) {
		myGroupList.remove(*i);
	}
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
			return;
		}
	}
}

Component* PainterFrame::getComponent(string type, int id) {
	for (auto c = componentList.begin(); c != componentList.end(); c++) {
		if ( (*c)->getId() == id) {
			if (type == "Button") return (Button*)(*c);
			else if (type == "Label") return (Label*)(*c);
		}
	}
}