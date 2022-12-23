#include "pch.h"
#include "HP.h"
#include "Scene.h"
#include "Text.h"
#include "Core.h"
#include "SelectGDI.h"

void HP::SetHP(const int hp)
{
	curHP = hp;
}

void HP::AddHP(const int hp)
{
	curHP += hp;
	if (curHP < 0)curHP = 0;
	else if (curHP > maxHP)curHP = maxHP;
}

//void HP::UpdateUiHp(Text* text)
//{
//	wstring str = L"HP : " + to_wstring(GetHP());
// 	text->SetText(str);
//}

void HP::Update()
{

}

void HP::Render(HDC hdc)
{
	rect.left = GetPos().x;
	rect.bottom = GetPos().y;
	rect.right = rect.left + offsetX;
	rect.top = rect.bottom - offsetY;

	SelectGDI pb(hdc, PEN_TYPE::BLACK);
	Core::GetInst()->SetBrushColor(&hdc, RGB(255, 255, 255));
	SelectGDI bb(hdc, BRUSH_TYPE::COLOR);
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

	SelectGDI pg(hdc, PEN_TYPE::BLACK);
	Core::GetInst()->SetBrushColor(&hdc, RGB(255, 0, 0));
	SelectGDI bg(hdc, BRUSH_TYPE::COLOR);
	int right = rect.left + curHP * (offsetX / maxHP);
	Rectangle(hdc, rect.left, rect.top, right, rect.bottom);

	Component_Render(hdc);
}

HP::HP()
	:curHP(100)
	, maxHP(100)
{
}


HP::HP(Vec2 pos)
	:curHP(100)
	, maxHP(100)
{
	SetPos(pos);
}

HP::HP(const int maxHP, Vec2 pos)
	:curHP(maxHP)
	, maxHP(maxHP)
{
	SetPos(pos);
}

HP::HP(const int maxHP, Vec2 pos, Vec2 scale)
	:curHP(maxHP)
	, maxHP(maxHP)
{
	SetPos(pos);
	SetScale(scale);
	offsetX = scale.x;
	offsetY = scale.y;
}

HP::~HP()
{
}
