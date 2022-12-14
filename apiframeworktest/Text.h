#pragma once
#include"UI.h";
#include <wingdi.h>

class Text:
	public UI
{
private:
	WCHAR textStr[1024];
	HFONT font;
	LOGFONT lf;
	COLOR16 color = RGB(0, 0, 0);
public:
	void SetText(wstring str);
	void SetTextSize(int size);
	void SetFontColor(COLORREF rgb);
public:
	Text(Vec2 pos, int size, wstring str);
	void Update() override;
	void Render(HDC hdc) override;
private:

	CLONE(Text);
private:
	Text();
	~Text();
};

