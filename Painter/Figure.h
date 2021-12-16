#pragma once
#include "Group.h"
#include <string>
using namespace std;

class Figure : public Group{
protected:
	string color_;
	bool fill_;
public:
	Figure(HDC hDC, int l, int t, int r, int b, string color, bool fill);
};
