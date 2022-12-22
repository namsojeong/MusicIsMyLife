#pragma once
#include "Object.h"
#include "HP.h"
#include "Stress.h"

class Image;
class Text;
class Player;
class Hamging :
    public Object
{
private:
    Image* pImg;
    HAMGING_STATE state;
    int m_attackPower;
    int m_stress;
public:
    HP* hp;
    Stress* stress;
public:
    const HAMGING_STATE GetState() { return state; }
    const int GetHamgingHP() { return hp->GetHP(); }
    const int GetAttackPower() { return m_attackPower; }
    const void SetAttackPower(int value) { m_attackPower = value; }
    const int GetStress() { return m_stress; }
    const void SetStress(int value) { m_stress = value; }
    const void AddStress(int value) { m_stress += value; }
public:
    const void Attack(int damage);
    const void Heal(int addHP);
    const void AttackStress(int damage);
    const void HealStress(int addHP);
public:
    void Update()       override;
    void Render(HDC _dc) override;
    virtual void	EnterCollision(Collider* _pOther);
private:
    void Die();
private:
    CLONE(Hamging);
public:
    Hamging(int setHP, Vec2 scale);
public:
    Hamging();
    ~Hamging();
};