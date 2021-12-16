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

	// ������ ���� �ʿ��� ����
	MyPoint start_;
	MyPoint end_;

	// ����, �׷� �ڽ��� �����ϴ� ����Ʈ
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

