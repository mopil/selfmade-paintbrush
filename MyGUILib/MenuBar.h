#pragma once
#include "Component.h"
#include <list>
using namespace std;
class MenuButton;
class MenuBar : public Component {
protected:
	list<MenuButton*>* menuButtonList_ = new list<MenuButton *>();
public:
	MenuBar(HDC hDC, int l, int t, int r, int b, string title, int id);
	void addMenuButton(MenuButton* mb);
	virtual void init() = 0;
	void draw() override;

};

