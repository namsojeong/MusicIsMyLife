#include "pch.h"
#include "Text.h"

Text::Text(Vec2 pos, Vec2 scale, TCHAR str)
{
	SetName(L"Text");

	m_rect.left = pos.x - scale.x / 2;
	m_rect.right = pos.x + scale.x / 2;
	m_rect.top = pos.y - scale.y / 2;
	m_rect.bottom = pos.y + scale.y / 2;

	textStr = &str;
	SetPos(pos);
	SetScale(scale);
}

void Text::Update()
{
}

void Text::Render(HDC hdc)
{
	SetTextColor(hdc, RGB(255, 0, 255));
	TextOut(hdc, GetPos().x, GetPos().y, textStr, lstrlen(textStr));
	Component_Render(hdc);
}

Text::~Text()
{
}
