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
    Text* hpText;
    Text* stressText;
    const int GetHamgingHP() { return hp->GetHP(); }
    const int GetAttackPower() { return m_attackPower; }
    const void SetAttackPower(int value) { m_attackPower = value; }
    const int GetStress() { return m_stress; }
    const void SetStress(int value) { m_stress = value; }
public:
    void Update()       override;
    void Render(HDC _dc) override;
private:
    CLONE(Hamging);
public:
    Hamging();
    ~Hamging();
};