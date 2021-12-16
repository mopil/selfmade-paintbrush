#pragma once
#include "Button.h"
class CheckBox : public Button{
protected:
	//class CheckCircle : public Button {
	//	bool isChecked_ = false;
	//};
	bool isChecked_ = false;
	//CheckCircle* checkCircle_;
public:
	CheckBox(HDC hDC, int l, int t, int r, int b, string title, int id);
	void toggle();
	void draw() override;

};

