#include "pch.h"
#include "HP.h"
#include "Scene.h"
#include "Text.h"


void HP::SetHP(const int hp)
{
	curHP = hp;
}

void HP::AddHP(const int hp)
{
	curHP += hp;
}

void HP::UpdateUiHp(Text* text)
{
	wstring str = L"HP : " + to_wstring(GetHP());
 	text->SetText(str);
}

HP::HP()
	:curHP(100)
	, maxHP(100)
{
}

HP::HP(const int maxHP)
	:curHP(maxHP)
	, maxHP(maxHP)
{

	
}

HP::~HP()
{
}
