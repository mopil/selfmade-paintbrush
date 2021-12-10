#include "FigureMenuButton.h"
#include "MenuItem.h"
#include "PainterFrame.h"

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

FigureMenuButton::FigureMenuButton(HDC hDC, int l, int t, int r, int b, string title, PainterFrame* p)
	: MenuButton(hDC, l, t, r, b, title), container_(p)
{
	// empty
}

void FigureMenuButton::openItems() {
	// �θ� ��ư 0 0 100 60
	MenuItem* menuItemRectangle = new MenuItem(hDC_, 0, 60, 100, 120, "�簢��");
	MenuItem* menuItemCircle = new MenuItem(hDC_, 0, 120, 100, 180, "Ÿ��");
	menuItemRectangle->addActionListener(new SetShapeActionListener(container_, 2));
	menuItemCircle->addActionListener(new SetShapeActionListener(container_, 3));
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