#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "Figure.h"
#include "MyButton.h"
#include "frame.h"

class MyButton;
class PainterFrame : public Frame{
protected:

	// 응용을 위해 필요한 변수
	MyPoint start_;
	MyPoint end_;

	// 도형, 그룹 박스를 저장하는 리스트
	std::list<Group*> myGroupList;
	std::list<Button*> myButtonList;

	// 도형 타입 변수 설정
	static const int NONE = 1;
	static const int RECTANGLE = 2;
	static const int CIRCLE = 3;

public:
	PainterFrame();
	PainterFrame(std::wstring, int, int);
	void eventHandler(MyEvent e) override;
	void repaint() override;
	void init() override;

	void setShape(int type);
	void createGroup();
	Group* findClickedElement(MyPoint pos);
	Button * findClickedButton();
	
};

