#pragma once
#include "Object.h"
#include "HP.h"

class Image;
class Text;
class Hamging;
class Player :
    public Object
{
private:
    Image* m_pImage;
    static Hamging* m_hamging;
    int m_attackPower;
private:
    HP* hp;
    //void CreateBullet();
public:
    Text* hpText;
    int GetPlayerHP(){ return hp->GetHP(); }
    void SetAttackPower(int value) { m_attackPower = value; }
public:
    void Attack(int damage);
    void Heal(int addHP);
    void Update()       override;
    void Render(HDC _dc) override;
private:
    void Die();
private:
    CLONE(Player);
public:
    Player();
    ~Player();
};

