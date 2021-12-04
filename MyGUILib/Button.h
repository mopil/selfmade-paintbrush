#pragma once
#include <Windows.h>
#include <string>
#include <list>
#include "Misc.h"
#include "ActionListener.h"
#include "Component.h"
using namespace std;

class Frame;
class ActionListener;
class Button : public Component{
protected:
	//int left_, top_, right_, bottom_;
	//HDC hDC_;
	string btn_name_;
	
	std::list<ActionListener*> listeners_;

public:
	Button(HDC hDC, int l, int t, int r, int b, string btnName);
	virtual void draw() = 0;
	void onClick();
	bool isIn(MyPoint pos);

	void addActionListener(ActionListener* l);

};
