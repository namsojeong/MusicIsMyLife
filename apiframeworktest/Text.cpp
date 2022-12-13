#include "pch.h"
#include "Text.h"
#include "string.h"

void Text::SetFontSize()
{
	font = CreateFont(50, 0, 0, 0, 0, 0, 0, 0,
		HANGEUL_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN,
		textStr.c_str());
}

void Text::SetFontColor(COLORREF rgb)
{
	color = rgb;
}

Text::Text(Vec2 pos, Vec2 scale, wstring str)
{
	SetName(L"Text");

	m_rect.left = pos.x - scale.x / 2;
	m_rect.right = pos.x + scale.x / 2;
	m_rect.top = pos.y - scale.y / 2;
	m_rect.bottom = pos.y + scale.y / 2;

	textStr = str;
	SetPos(pos);
	SetScale(scale);
}

void Text::Update()
{
}

void Text::Render(HDC hdc)
{
	HFONT hTmp = (HFONT)SelectObject(hdc, font);
	SetTextColor(hdc, color);
	TextOut(hdc, GetPos().x, GetPos().y, textStr.c_str(), textStr.length());
	Component_Render(hdc);
}

Text::~Text()
{
}
