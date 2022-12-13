#pragma once
#include"UI.h";
class Button:
	public UI
{
private:
	RECT m_rect;
private:
	CLONE(Button);
protected:
	void Click();
	bool IsOnButton();
	void SetRect(Vec2 pos, Vec2 scale);
protected:
	virtual void ButtonEvent();
	void Update() override;
	void Render(HDC hdc) override;
protected:
	Button();
	~Button();
};

