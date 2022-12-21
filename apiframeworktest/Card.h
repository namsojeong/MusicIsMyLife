#pragma once
#include "Object.h"
class Image;
class Player;
class Card :
    public Object
{
private:
    int _mType;
    int _attackPower;
    int _stressPower;
    Image* m_pImage;
    Vec2 m_vPos;
    RECT m_rect;
    Player* m_player;
    bool isUsed = false;
public:
    Card(Player* p);
    ~Card();
    CLONE(Card);
public:
    void SetCenterPos(Vec2 _vPos) { m_vPos = _vPos; }
    void SetCardAttackPower(const int pow) { _attackPower = pow; };
    void SetCardStressPower(const int stress) { _stressPower = stress; };
    void Attack();
public:
    virtual void Update() override;
    void Render(HDC _dc) override;
};