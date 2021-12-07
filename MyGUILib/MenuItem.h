#pragma once
#include "Component.h"
#include <string>
using namespace std;
class MenuButton;
class MenuItem : public Component {
protected:
	MenuButton* parentButton_;
public:
	MenuItem(HDC hDC, int l, int t, int r, int b, string title, MenuButton *parent);
	void draw(int nextY);
	void draw();
	MenuButton* getParent();
};

