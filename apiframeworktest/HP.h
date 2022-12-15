#pragma once

class Text;
class HP
{
private:
	int curHP;
	int maxHP;
	bool isDead = false;
public:
	const bool IsDead() { return isDead; }
	const int GetHP() { return curHP; }
	void SetHP(const int hp);
	void AddHP(const int hp);
public:
	void UpdateUiHp(Text* text);
public:
	HP();
	HP(const int maxHP=100);
	~HP();

};