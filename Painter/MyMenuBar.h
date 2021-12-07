#pragma once
#include "MenuBar.h"
class MyMenuBar : public MenuBar {
private:

public:
	MyMenuBar(HDC hDC, int l, int t, int r, int b, string title);
	void init() override;
};

