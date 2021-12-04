#pragma once
#include <string>
#include "Component.h"
class Label : public Component {
protected:
	//std::string title_;

public:
	Label(HDC hDC, int l, int t, int r, int b, std::string title);
	//virtual void draw(int correctX, int correctY);
	//void setTitle(std::string title);

};

