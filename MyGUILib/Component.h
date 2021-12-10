#pragma once
#include <Windows.h>
#include <string>
#include <list>
using namespace std;

class ActionListener;
class MyPoint;
class Component {
protected:
	int left_, top_, right_, bottom_, id_;
	HDC hDC_;
	string title_, type_;
	list<ActionListener*> listeners_;
public :
	Component(HDC hDC, int l, int t, int r, int b, string title, string type, int id);
	virtual void draw();
	virtual void setTitle(string title);
	string getTitle();
	string getType();
	int getId();

	virtual bool isIn(MyPoint pos);
	virtual void addActionListener(ActionListener* l);

};

