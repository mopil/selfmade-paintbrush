#pragma once
#include "MenuBar.h"
class PainterFrame;
class MyMenuBar : public MenuBar{
protected:
	PainterFrame* container_;
public:
	MyMenuBar(HDC hDC, int id, PainterFrame* c);
	void init() override;
};

