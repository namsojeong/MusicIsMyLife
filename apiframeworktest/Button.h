#pragma once
#include"UI.h";

class Image;
enum BUTTON_STATE
{
	NONE,
	OVER
};
class Button:
	public UI
{
private:
	RECT m_rect;
private:
	CLONE(Button);

protected:
	Image* m_pImage;
	wstring m_pathKey;
	wstring m_path;
protected:
	void Click();
	bool IsOnButton();
	void SetRect(Vec2 pos, Vec2 scale);
	virtual void SetImage(BUTTON_STATE state);
protected:
	virtual void ButtonEvent();
	void Update() override;
	void Render(HDC hdc) override;
protected:
	Button();
	~Button();
};

