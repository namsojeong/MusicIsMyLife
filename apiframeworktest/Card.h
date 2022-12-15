#pragma once
#include "Object.h"
class Image;
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
public:
    Card(int type);
    ~Card();
    CLONE(Card);
public:
    void SetCenterPos(Vec2 _vPos) { m_vPos = _vPos; }
    void SetCardAttackPower(const int pow) { _attackPower = pow; };
    void SetCardStressPower(const int stress) { _stressPower = stress; };
public:
    virtual void Update() override;
    void Render(HDC _dc) override;
};