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

	// ������ ���� �ʿ��� ����
	MyPoint start_;
	MyPoint end_;

	// ����, �׷� �ڽ��� �����ϴ� ����Ʈ
	std::list<Group*> myGroupList;
	std::list<Button*> myButtonList;

	// ���� Ÿ�� ���� ����
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

