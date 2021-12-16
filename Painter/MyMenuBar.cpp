#include "MyMenuBar.h"
#include "Label.h"
#include "FigureMenuButton.h"
#include "ActionListener.h"
#include "Group.h"
#include "PainterFrame.h"
#include "ColorMenuButton.h"
#include "CheckBox.h"

class ToggleModeActionListener : public ActionListener {
private:
	PainterFrame* container_;
	CheckBox* checkBox_;
public:
	ToggleModeActionListener(PainterFrame* f, CheckBox* cb) :container_(f), checkBox_(cb) {}
	void actionPerformed() override {
		checkBox_->toggle();
		container_->toggleFillMode();
	}
};


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

class SaveActionListner : public ActionListener {
public:
	PainterFrame* container_;
	SaveActionListner(PainterFrame *c):container_(c){}
	void actionPerformed() override {
		container_->saveScreen();
	}
};

MyMenuBar::MyMenuBar(HDC hDC, int id, PainterFrame* c) :
	MenuBar(hDC, id), container_(c)
{
	// empty
}

void MyMenuBar::init() {
	// ��� ��ɾ� ��� ��
	Label* labelMain = new Label(hDC_, 500, 0, 999, 60, "����� ��� ������ ����� ���", 2001);
	labelMain->addActionListener(new NoActionListener());
	container_->addComponent(labelMain);

	// ���� �޴���ư
	FigureMenuButton* menuBtnFigure = new FigureMenuButton(hDC_, 0, 0, 100, 60, "����", 1, container_);
	menuBtnFigure->addActionListener(new DropDownActionListener(menuBtnFigure, container_));
	container_->addComponent(menuBtnFigure);

	// ���� �޴���ư
	ColorMenuButton* menuBtnColor = new ColorMenuButton(hDC_, 100, 0, 200, 60, "����", 2, container_);
	menuBtnColor->addActionListener(new DropDownActionListener(menuBtnColor, container_));
	container_->addComponent(menuBtnColor);

	// ��ũ����
	Button* saveButton = new Button(hDC_, 200, 0, 300, 60, "����", 2002);
	saveButton->addActionListener(new SaveActionListner(container_));
	saveButton->addActionListener(new SetTitleActionListener(labelMain, "ScreenShot.png�� ���� ȭ�� ���� ��"));
	container_->addComponent(saveButton);

	// üũ�ڽ�
	CheckBox * checkBox = new CheckBox(hDC_, 300, 0, 400, 60, "ä���", 2003);
	checkBox->addActionListener(new ToggleModeActionListener(container_, checkBox));
	checkBox->addActionListener(new SetTitleActionListener(labelMain, "ä��� ������"));
	container_->addComponent(checkBox);

	// ���� ��ư
	Button* btnReset = new Button(hDC_, 400, 0, 500, 60, "����", 1001);
	btnReset->addActionListener(new ResetActionListener(container_));
	btnReset->addActionListener(new SetTitleActionListener(labelMain, "�׸��� �ʱ�ȭ ��"));
	container_->addComponent(btnReset);
}