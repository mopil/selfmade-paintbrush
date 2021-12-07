#include "MyMenuBar.h"
#include "MenuButton.h"
#include "MenuItem.h"

class DropDownActionListener : public ActionListener {
private:
	MenuButton* menuButton_;
public:
	DropDownActionListener(MenuButton* mb) :menuButton_(mb) {};
	void actionPerformed() override {
		menuButton_->showItems();
	}
};

MyMenuBar::MyMenuBar(HDC hDC, int l, int t, int r, int b, string title) :
	MenuBar(hDC, l, t, r, b, title)
{
	// empty
}

void MyMenuBar::init() {
	MenuButton* menuBtnFigure = new MenuButton(hDC_, 0, 0, 100, 60, "도형");
	MenuItem* menuItemRectangle = new MenuItem(hDC_, 0, 100, 100, 120, "사각형",menuBtnFigure);
	menuBtnFigure->addActionListener(new DropDownActionListener(menuBtnFigure));
	menuBtnFigure->addItem(menuItemRectangle);
	menuButtonList_->push_back(menuBtnFigure);

}