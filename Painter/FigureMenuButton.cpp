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

class SetLabelActionListener : public ActionListener {
private:
	Label* label_;
	string title_;

public:
	SetLabelActionListener(Label* l, string title) :label_(l), title_(title) {}
	void actionPerformed() override {
		label_->setTitle(title_);
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
	MenuItem* menuItemCircle = new MenuItem(hDC_, 0, 120, 100, 180, "타원",1202);

	// 리스너 추가
	Label* labelMain = (Label*)container_->getComponent("Label", 2001);
	menuItemRectangle->addActionListener(new SetShapeActionListener(container_, this, "Rectangle"));
	menuItemCircle->addActionListener(new SetShapeActionListener(container_, this, "Circle"));
	menuItemRectangle->addActionListener(new SetLabelActionListener(labelMain, "현재 도형 : 사각형 선택 됨"));
	menuItemCircle->addActionListener(new SetLabelActionListener(labelMain, "현재 도형 : 원 선택 됨"));
	this->addItem(menuItemRectangle);
	this->addItem(menuItemCircle);
	container_->addComponent(menuItemRectangle);
	container_->addComponent(menuItemCircle);
}

void FigureMenuButton::closeItems() {
	MenuButton::closeItems();
	container_->removeComponent("사각형");
	container_->removeComponent("타원");
}