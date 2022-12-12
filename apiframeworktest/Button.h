#pragma once
#include"UI.h";
class Image;
class Button:
	public UI
{
private:
	RECT m_rect;
public:
	void Click();
	bool IsOnButton();
public:
	Button(Vec2 pos, Vec2 scale);
	void Update() override;
	void Render(HDC hdc) override;
private:

	CLONE(Button);
private:
	Button();
	~Button();
};

