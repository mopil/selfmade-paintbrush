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
	std::list<ActionListener*> listeners_;

public:
	Button(HDC hDC, int l, int t, int r, int b, string title);
	void onClick();
	bool isIn(MyPoint pos);

	void addActionListener(ActionListener* l);

};
