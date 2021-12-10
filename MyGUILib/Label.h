#pragma once
#include <string>
#include "Component.h"
using namespace std;

// id 2000
class Label : public Component {
public:
	Label(HDC hDC, int l, int t, int r, int b, string title, int id);
	void draw() override;
};

