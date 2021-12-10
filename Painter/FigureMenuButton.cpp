#include "FigureMenuButton.h"
#include "MenuItem.h"
#include "PainterFrame.h"
#include "Label.h"
#include "ActionListener.h"

class SetShapeActionListener : public ActionListener {
private:
	PainterFrame* container_;
	MenuButton* menuButton_;
	//Label* figureLabel_;
	int type_;
	static const int RECT_TYPE = 2;
	static const int CIRCLE_TYPE = 3;
public:
	SetShapeActionListener(PainterFrame* f, MenuButton * mb, int type) :container_(f), menuButton_(mb),type_(type) {}
	void actionPerformed() override {
		switch (type_) {
		case RECT_TYPE:
			OutputDebugString(L"�簢�� ��ư ���� ��\n");
			container_->setShape(RECT_TYPE);
			menuButton_->closeItems();
			//figureLabel_->setTitle("���� ���� : �簢��");
			menuButton_->toggle();
			break;
		case CIRCLE_TYPE:
			OutputDebugString(L"Ÿ�� ��ư ���� ��\n");
			container_->setShape(CIRCLE_TYPE);
			menuButton_->closeItems();
			//figureLabel_->setTitle("���� ���� : ��");
			menuButton_->toggle();
			break;
		}
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
//
//class NoActionListener : public ActionListener {
//public:
//	NoActionListener(){}
//	void actionPerformed() override {
//		// empty
//	}
//
//};

FigureMenuButton::FigureMenuButton(HDC hDC, int l, int t, int r, int b, string title, int id, PainterFrame* p)
	: MenuButton(hDC, l, t, r, b, title, id), container_(p)
{
	// empty
}

void FigureMenuButton::openItems() {
	// ������ ��ư ���� (�θ� ��ư 0 0 100 60)
	MenuItem* menuItemRectangle = new MenuItem(hDC_, 0, 60, 100, 120, "�簢��",1201);
	MenuItem* menuItemCircle = new MenuItem(hDC_, 0, 120, 100, 180, "Ÿ��",1202);

	//// ���� ���� ǥ�� �� ����
	//MyLabel* labelFigure = new MyLabel(hDC_, 500, 0, 700, 60, "���� ���� : ����");
	//labelFigure->addActionListener(new NoActionListener());
	//container_->addComponent(labelFigure);

	// ������ �߰�
	Label* labelFigure = (Label*)container_->getComponent("Label", 2001);
	menuItemRectangle->addActionListener(new SetShapeActionListener(container_, this, 2));
	menuItemCircle->addActionListener(new SetShapeActionListener(container_, this, 3));
	menuItemRectangle->addActionListener(new SetLabelActionListener(labelFigure, "���� ���� : �簢��"));
	menuItemCircle->addActionListener(new SetLabelActionListener(labelFigure, "���� ���� : ��"));
	this->addItem(menuItemRectangle);
	this->addItem(menuItemCircle);
	container_->addComponent(menuItemRectangle);
	container_->addComponent(menuItemCircle);
}

void FigureMenuButton::closeItems() {
	MenuButton::closeItems();
	container_->removeComponent("�簢��");
	container_->removeComponent("Ÿ��");
}