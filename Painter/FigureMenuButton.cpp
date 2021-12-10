#include "FigureMenuButton.h"
#include "MenuItem.h"
#include "PainterFrame.h"
#include "Label.h"
#include "ActionListener.h"

class SetShapeActionListener : public ActionListener {
private:
	PainterFrame* container_;
	MenuButton* menuButton_;
	string type_;
public:
	SetShapeActionListener(PainterFrame* f, MenuButton * mb, string type) :container_(f), menuButton_(mb),type_(type) {}
	void actionPerformed() override {
		container_->setShape(type_);
		menuButton_->closeItems();
		menuButton_->toggle();
	}
};

class SetTitleActionListener : public ActionListener {
private:
	Component* component_;
	string title_;

public:
	SetTitleActionListener(Component* l, string title) :component_(l), title_(title) {}
	void actionPerformed() override {
		component_->setTitle(title_);
	}

};

FigureMenuButton::FigureMenuButton(HDC hDC, int l, int t, int r, int b, string title, int id, PainterFrame* p)
	: MenuButton(hDC, l, t, r, b, title, id), container_(p)
{
	// empty
}

void FigureMenuButton::openItems() {
	// 아이템 버튼 생성 (부모 버튼 0 0 100 60)
	MenuItem* menuItemRectangle = new MenuItem(hDC_, 0, 60, 100, 120, "사각형",1201);
	MenuItem* menuItemCircle = new MenuItem(hDC_, 0, 120, 100, 180, "원",1202);
	menuItemRectangle->addActionListener(new SetShapeActionListener(container_, this, "Rectangle"));
	menuItemCircle->addActionListener(new SetShapeActionListener(container_, this, "Circle"));

	// 버튼 눌렀을 때 메인라벨 구문 변경
	Label* labelMain = (Label*)container_->getComponent("Label", 2001);
	menuItemRectangle->addActionListener(new SetTitleActionListener(labelMain, "도형 사각형이 선택 됨"));
	menuItemCircle->addActionListener(new SetTitleActionListener(labelMain, "도형 원이 선택 됨"));

	// 버튼 눌렀을 때 도형 부모 버튼 구문 변경
	Button* parent = (Button*)container_->getComponent("Button", 1);
	menuItemRectangle->addActionListener(new SetTitleActionListener(parent, "사각형 "));
	menuItemCircle->addActionListener(new SetTitleActionListener(parent, " 원"));

	this->addItem(menuItemRectangle);
	this->addItem(menuItemCircle);
	container_->addComponent(menuItemRectangle);
	container_->addComponent(menuItemCircle);
}

void FigureMenuButton::closeItems() {
	MenuButton::closeItems();
	container_->removeComponent("사각형");
	container_->removeComponent("원");
}