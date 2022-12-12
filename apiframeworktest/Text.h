#pragma once
#include"UI.h";

class Text:
	public UI
{
private:
	RECT m_rect;
	TCHAR* textStr;
public:
	Text(Vec2 pos, Vec2 scale, TCHAR str);
	void Update() override;
	void Render(HDC hdc) override;
private:

	CLONE(Text);
private:
	Text();
	~Text();
};

