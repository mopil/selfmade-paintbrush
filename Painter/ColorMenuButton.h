#pragma once
#include "MenuButton.h"
class PainterFrame;
class ColorMenuButton : public MenuButton {
private:
	PainterFrame* container_;
public:
	ColorMenuButton(HDC hDC, int l, int t, int r, int b, string title, int id, PainterFrame* p);
	void openItems() override;
	void closeItems() override;
};
