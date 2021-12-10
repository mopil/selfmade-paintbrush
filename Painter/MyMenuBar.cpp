#include "MyMenuBar.h"
#include "Label.h"
#include "FigureMenuButton.h"
#include "ActionListener.h"
#include "Group.h"
#include "PainterFrame.h"
#include "ColorMenuButton.h"


class SetTitleActionListener : public ActionListener{
private:
	Component* component_;
	string title_;

public:
	SetTitleActionListener(Label* l, string title) :component_(l), title_(title) {}
	void actionPerformed() override {
		component_->setTitle(title_);
	}

};

class ResetActionListener : public ActionListener{
private:
	PainterFrame* container_;
public:
	ResetActionListener(PainterFrame* f) :container_(f) {}
	void actionPerformed() override {
		container_->resetList();
	}
};


class DropDownActionListener : public ActionListener {
private:
	PainterFrame* container_;
	MenuButton* menuButton_;
public:
	DropDownActionListener(MenuButton* mb, PainterFrame* c) :menuButton_(mb), container_(c) {};
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
	NoActionListener() {}
	void actionPerformed() override {
		// empty
	}

};

MyMenuBar::MyMenuBar(HDC hDC, int id, PainterFrame* c) :
	MenuBar(hDC, id), container_(c)
{
	// empty
}

void MyMenuBar::init() {
	// 방금 명령어 출력 라벨
	Label* labelMain = new Label(hDC_, 500, 0, 999, 60, "여기는 방금 실행한 명령을 출력", 2001);
	labelMain->addActionListener(new NoActionListener());
	container_->addComponent(labelMain);

	// 도형 메뉴버튼
	FigureMenuButton* menuBtnFigure = new FigureMenuButton(hDC_, 0, 0, 100, 60, "도형", 1, container_);
	menuBtnFigure->addActionListener(new DropDownActionListener(menuBtnFigure, container_));
	container_->addComponent(menuBtnFigure);

	// 현재 도형 상태 출력 라벨
	Label* labelFigure = new Label(hDC_, 100, 0, 200, 60, "빈칸", 2002);
	labelFigure->addActionListener(new NoActionListener());
	container_->addComponent(labelFigure);

	// 색깔 메뉴버튼
	ColorMenuButton* menuBtnColor = new ColorMenuButton(hDC_, 200, 0, 300, 60, "색깔", 2, container_);
	menuBtnColor->addActionListener(new DropDownActionListener(menuBtnColor, container_));
	container_->addComponent(menuBtnColor);

	// 현재 도형 상태 출력 라벨
	Label* labelColor = new Label(hDC_, 300, 0, 400, 60, "빈칸", 2003);
	labelColor->addActionListener(new NoActionListener());
	container_->addComponent(labelColor);

	// 리셋 버튼
	Button* btnReset = new Button(hDC_, 400, 0, 500, 60, "리셋", 1001);
	btnReset->addActionListener(new ResetActionListener(container_));
	btnReset->addActionListener(new SetTitleActionListener(labelMain, "그림판 초기화 됨"));
	container_->addComponent(btnReset);
}