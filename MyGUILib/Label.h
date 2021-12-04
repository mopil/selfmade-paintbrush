#pragma once
#include <string>
#include "Component.h"
class Label : public Component {
public:
	Label(HDC hDC, int l, int t, int r, int b, std::string title);

};

