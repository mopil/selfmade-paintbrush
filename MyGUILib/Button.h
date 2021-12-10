#pragma once
#include <Windows.h>
#include "Component.h"
using namespace std;

// id 1000
class Button : public Component{
public:
	Button(HDC hDC, int l, int t, int r, int b, string title, int id);
};
