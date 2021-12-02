#pragma once
#include "Group.h"
#include <list>
using namespace std;

class GroupBox : public Group {
protected:
	list<Group*>* groupBox_;

public:
	GroupBox(HDC hDC, int l, int t, int r, int b);
	void addElement(Group* element);
	void draw() override;
	void addPosition(int amountX, int amountY) override;
	void removeElements(list<Group *> &list);
};

