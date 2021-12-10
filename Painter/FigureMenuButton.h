#pragma once
#include "MenuButton.h"
class PainterFrame;
class FigureMenuButton : public MenuButton {
private:
	PainterFrame* container_;
public:
	FigureMenuButton(HDC hDC, int l, int t, int r, int b, string title, PainterFrame *p);
	void openItems() override;
	void closeItems() override;
};

