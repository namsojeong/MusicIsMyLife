#pragma once
#include"UI.h";
#include <wingdi.h>

class Text:
	public UI
{
private:
	RECT m_rect;
	wstring textStr;
	HFONT font;
	COLOR16 color = RGB(0, 0, 0);
public:
	void SetFontSize();
	void SetFontColor(COLORREF rgb);
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

