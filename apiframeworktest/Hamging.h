#pragma once
#include "Object.h"
#include "HP.h"
#include "Stress.h"
#include "ResMgr.h"

class Image;
class Text;
class Player;

struct Hamging_AttackImage
{
    wstring key;
    wstring path;
};
class Hamging :
    public Object
{
private:
    Image* pImg;
    HAMGING_STATE state;
    float m_stress;
public:
    HP* hp;
    Stress* stress;
public:
    const HAMGING_STATE GetState() { return state; }
    const int GetHamgingHP() { return hp->GetHP(); }
    const int GetStress() { return m_stress; }
    const void SetStress(int value) { m_stress = value; }
    const void AddStress(int value) { m_stress += value; }
private:
    map<UINT, Hamging_AttackImage> attackImage = {
        {(UINT)CARD_TYPE::A, Hamging_AttackImage{L"CardA_Event", L"Image\\Card\\Card_A_Event.bmp"}},
        {(UINT)CARD_TYPE::B, Hamging_AttackImage{L"CardB_Event", L"Image\\Card\\Card_B_Event.bmp"}},
        {(UINT)CARD_TYPE::C, Hamging_AttackImage{L"CardC_Event", L"Image\\Card\\Card_C_Event.bmp"}},
        {(UINT)CARD_TYPE::D, Hamging_AttackImage{L"CardD_Event", L"Image\\Card\\Card_D_Event.bmp"}},
        {(UINT)CARD_TYPE::E, Hamging_AttackImage{L"CardE_Event", L"Image\\Card\\Card_E_Event.bmp"}},
    };
    Image* GetEventImage(CARD_TYPE type) { return ResMgr::GetInst()->ImgLoad(attackImage[(UINT)type].key, attackImage[(UINT)type].path); }
public:
    const void SetHamgingSkin(CARD_TYPE type);
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