#pragma once
#include"UI.h";

class Text:
	public UI
{
private:
	RECT m_rect;
public:
	Text(Vec2 pos, Vec2 scale);
	void Update() override;
	void Render(HDC hdc) override;
private:

	CLONE(Text);
private:
	Text();
	~Text();
};

