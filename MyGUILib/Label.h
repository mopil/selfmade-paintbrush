#pragma once
#include <string>
#include "Component.h"
class Label : public Component {
protected:
	std::string title_;

public:
	Label(HDC hDC, int l, int t, int r, int b, std::string title);
	virtual void draw() = 0;
	virtual void setTitle() = 0;

};

