#pragma once
#include "Component.h"
#include <list>
using namespace std;
class MenuButton;
class Frame;
class MenuBar : public Component {
protected:
	// Frame �� ����
public:
	MenuBar(HDC hDC,int id);
	virtual void init() = 0; // ���� ����
};

