#pragma once
#include "UI.h"

class Text;
class HP :
	public UI
{
private:
	RECT rect;
	float offsetX = 350.f;
	float offsetY = 30.f;
	int curHP;
	int maxHP = 100;
	bool isDead = false;
public:
	const bool Dead() { return curHP <= 0; }
	const int GetHP() { return curHP; }
	const int GetMaxHP() { return maxHP; }
	void SetHP(const int hp);
	void AddHP(const int hp);
public:
	//void UpdateUiHp(Text* text);
public:
	void Update() override;
	void Render(HDC hdc) override;
public:
	CLONE(HP);
public:
	HP(Vec2 pos);
	HP(const int maxHP, Vec2 pos);
	HP(const int maxHP, Vec2 pos, Vec2 scale);
	HP();
	~HP();

};