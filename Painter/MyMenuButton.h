#pragma once
#include "MenuButton.h"
class MyMenuButton : public MenuButton {
public:
	MyMenuButton(HDC hDC, int l, int t, int r, int b, string title);
	void openItems() override;
};

