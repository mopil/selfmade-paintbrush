#pragma once
#include <string>
#include <list>
#include "frame.h"
using namespace std;

class Button;
class Component;
class Group;
class PainterFrame : public Frame{
protected:

	// 응용을 위해 필요한 변수
	MyPoint start_;
	MyPoint end_;

	// 도형, 그룹 박스를 저장하는 리스트
	list<Group*> myGroupList;
	list<Component*> componentList;

public:
	static PainterFrame* getFrame(wstring, int, int);
	PainterFrame();
	PainterFrame(wstring, int, int);
	void eventHandler(MyEvent e) override;
	void repaint() override;
	void init() override;

	void setShape(string type);
	void setColor(string color);
	void createGroup();
	Group* findClickedElement(MyPoint pos);
	Button * findClickedButton(MyPoint pos);

	void resetList();
	void addComponent(Component* c);
	void removeComponent(string title);
	Component* getComponent(string type, int id);

	void saveScreen();
	void toggleFillMode();
	
};

