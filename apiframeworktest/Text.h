#pragma once
#include"UI.h";

class Text:
	public UI
{
private:
	RECT m_rect;
	wstring textStr;
	HFONT font;
public:
	void SetFontSize();
	void SetFontColor();
public:
	Text(Vec2 pos, Vec2 scale, wstring str);
	void Update() override;
	void Render(HDC hdc) override;
private:

	CLONE(Text);
private:
	Text();
	~Text();
};

