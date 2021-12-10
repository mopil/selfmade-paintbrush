#pragma once
#include "Button.h"
#include <string>
using namespace std;
// button id 1000 # MenuButton id 1100 # MenuItem id 1200
class MenuItem : public Button {
public:
	MenuItem(HDC hDC, int l, int t, int r, int b, string title, int id);
};

