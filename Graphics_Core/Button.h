#pragma once

#include "UI.h"
#include <windows.h>
#include <vector>
using std::vector;


class Button : public UI
{
public:
	Button(SUIInfo info);
	~Button();
	virtual int Click();
	virtual int MouseButtonDown(int button);
	virtual int MouseButtonUp(int button);
private:
	virtual int MouseOver();
	virtual int MouseOut();

};