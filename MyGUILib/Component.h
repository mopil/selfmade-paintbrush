#pragma once
#include <Windows.h>
#include <string>

class Component {
protected:
	int left_, top_, right_, bottom_;
	HDC hDC_;
	std::string title_;
public :
	Component(HDC hDC, int l, int t, int r, int b, std::string title);
	virtual void draw(int correctX, int correctY);
	virtual void setTitle(std::string title);

};

