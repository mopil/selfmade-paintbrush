#pragma once
#include "Component.h"
#include <list>
using namespace std;
class MenuButton;
class Frame;
class MenuBar : public Component {
protected:
	// Frame 을 지정
public:
	MenuBar(HDC hDC,int id);
	virtual void init() = 0; // 응용 구현
};

