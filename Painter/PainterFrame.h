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

	// ���� Ÿ�� ���� ����
	static const int NONE = 1;
	static const int RECTANGLE = 2;
	static const int CIRCLE = 3;


public:
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

	void resetList(list<Group*>*);
	void addComponent(Component* c);
	void removeComponent(string title);

	void toggleAll();
	Component* getComponent(string type, int id);
	
};

