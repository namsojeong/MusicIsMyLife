#pragma once

class Text;
class HP
{
private:
	int curHP;
	int maxHP;
	bool isDead = false;
public:
	const bool IsDead() { return curHP<=0; }
	const int GetHP() { return curHP; }
	const int GetMaxHP() { return maxHP; }
	void SetHP(const int hp);
	void AddHP(const int hp);
public:
	void UpdateUiHp(Text* text);
public:
	HP();
	HP(const int maxHP=100);
	~HP();

};