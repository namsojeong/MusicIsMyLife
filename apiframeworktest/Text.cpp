#include "pch.h"
#include "Text.h"
#include "string.h"

void Text::SetText(wstring str)
{
	wsprintf(textStr, str.c_str());
}

void Text::SetTextSize(int size)
{
	lf.lfHeight = size;
}

void Text::SetFontColor(COLORREF rgb)
{
	color = rgb;
}

Text::Text(Vec2 pos, int size, wstring str)
{
	lf.lfHeight = size;
	lf.lfWeight = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 0;
	lf.lfItalic = false;
	lf.lfUnderline = 0;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = HANGUL_CHARSET;
	lf.lfOutPrecision = 0;
	lf.lfClipPrecision = 0;
	lf.lfQuality = 0;
	lf.lfPitchAndFamily = VARIABLE_PITCH | FF_ROMAN;
	lstrcpy(lf.lfFaceName, TEXT("안동엄마까투리"));

	font = CreateFontIndirect(&lf);

	SetPos(pos);
	SetText(str);
}

void Text::Update()
{
}

void Text::Render(HDC hdc)
{

	SetTextColor(hdc, color);
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, font);
	TextOut(hdc, GetPos().x, GetPos().y, textStr, lstrlen(textStr));

	Component_Render(hdc);
}

Text::~Text()
{
}
