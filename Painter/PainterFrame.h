#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "Figure.h"
#include "MyButton.h"
#include "frame.h"
#include "MyLabel.h"

class MyButton;
class PainterFrame : public Frame{
protected:

	// 응용을 위해 필요한 변수
	MyPoint start_;
	MyPoint end_;

	// 도형, 그룹 박스를 저장하는 리스트
	std::list<Group*> myGroupList;
	std::list<MyButton*> myButtonList;
	std::list<MyLabel*> myLabelList;

	// 도형 타입 변수 설정
	static const int NONE = 1;
	static const int RECTANGLE = 2;
	static const int CIRCLE = 3;

	// 버튼 타이틀 가운데 정렬 보정 상수
	static const int RECT_CORRECT_X = 32;
	static const int RECT_CORRECT_Y = 8;
	static const int CIRCLE_CORRECT_X = 18;
	static const int CIRCLE_CORRECT_Y = 6;

	static const int APPLE_CORRECT_X = 18;
	static const int APPLE_CORRECT_Y = 8;
	static const int BANANA_CORRECT_X = 16;
	static const int BANANA_CORRECT_Y = 6;


	static const int APPLE = 4;
	static const int BANANA = 5;

public:
	PainterFrame();
	PainterFrame(std::wstring, int, int);
	void eventHandler(MyEvent e) override;
	void repaint() override;
	void init() override;

	void setShape(int type);
	void createGroup();
	Group* findClickedElement(MyPoint pos);
	MyButton * findClickedButton(MyPoint pos);
	
};

