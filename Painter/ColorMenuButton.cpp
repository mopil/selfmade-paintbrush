#include "ColorMenuButton.h"
#include "FigureMenuButton.h"
#include "MenuItem.h"
#include "PainterFrame.h"
#include "Label.h"
#include "ActionListener.h"

class SetColorActionListener : public ActionListener {
private:
	PainterFrame* container_;
	MenuButton* menuButton_;
	string color_;
public:
	SetColorActionListener(PainterFrame* f, MenuButton* mb, string color) :container_(f), menuButton_(mb), color_(color) {}
	void actionPerformed() override {
		OutputDebugString(L"color 변경 됨\n");
		container_->setColor(color_); 
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

ColorMenuButton::ColorMenuButton(HDC hDC, int l, int t, int r, int b, string title, int id, PainterFrame* p)
	: MenuButton(hDC, l, t, r, b, title, id), container_(p)
{
	// empty
}

void ColorMenuButton::openItems() {
	// 아이템 버튼 생성 (부모 버튼 0 0 100 60)
	MenuItem* menuItemBlack = new MenuItem(hDC_, 100, 60, 200, 120, "검정", 1203);
	MenuItem* menuItemRed = new MenuItem(hDC_, 100, 120, 200, 180, "빨강", 1204);
	MenuItem* menuItemBlue = new MenuItem(hDC_, 100, 180, 200, 240, "파랑", 1205);
	MenuItem* menuItemGreen = new MenuItem(hDC_, 100, 240, 200, 300, "초록", 1206);

	// 리스너 추가
	Label* labelMain = (Label*)container_->getComponent("Label", 2001);
	menuItemBlack->addActionListener(new SetLabelActionListener(labelMain, "현재 색깔 : 검정 선택 됨"));
	menuItemRed->addActionListener(new SetLabelActionListener(labelMain, "현재 색깔 : 빨강 선택 됨"));
	menuItemBlue->addActionListener(new SetLabelActionListener(labelMain, "현재 색깔 : 파랑 선택 됨"));
	menuItemGreen->addActionListener(new SetLabelActionListener(labelMain, "현재 색깔 : 초록 선택 됨"));
	menuItemBlack->addActionListener(new SetColorActionListener(container_, this, "Black"));
	menuItemRed->addActionListener(new SetColorActionListener(container_, this, "Red"));
	menuItemBlue->addActionListener(new SetColorActionListener(container_, this, "Blue"));
	menuItemGreen->addActionListener(new SetColorActionListener(container_, this, "Green"));
	this->addItem(menuItemBlack);
	this->addItem(menuItemRed);
	this->addItem(menuItemBlue);
	this->addItem(menuItemGreen);
	container_->addComponent(menuItemBlack);
	container_->addComponent(menuItemRed);
	container_->addComponent(menuItemBlue);
	container_->addComponent(menuItemGreen);

}

void ColorMenuButton::closeItems() {
	MenuButton::closeItems();
	container_->removeComponent("검정");
	container_->removeComponent("빨강");
	container_->removeComponent("파랑");
	container_->removeComponent("초록");
}