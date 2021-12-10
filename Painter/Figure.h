#pragma once
#include "Group.h"
#include <string>
using namespace std;

class Figure : public Group{
protected:
	string color_;
public:
	Figure(HDC hDC, int l, int t, int r, int b, string color);
};
