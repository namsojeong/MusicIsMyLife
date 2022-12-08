#pragma once
class HP
{
private:
	int curHP;
	int maxHP;
	bool isDead = false;
public:
	const bool IsDead() { return isDead; }
	const int GetHP() { return curHP; }
	void SetHP(const int hp) { curHP = hp; }
public:
	HP();
	HP(const int maxHP=100);
	~HP();

};

