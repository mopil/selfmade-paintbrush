#pragma once
#include "Label.h"
class MyLabel : public Label{
public:
	MyLabel(HDC hDC, int l, int t, int r, int b, std::string title);
	void draw(int correctX, int correctY) override;

};

