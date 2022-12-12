#pragma once
#include"UI.h";

class Button:
	public UI
{
private:
public:
	void Click();
	bool IsOnButton();
private:
	Button();
	~Button();
};

