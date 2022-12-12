#pragma once
#include "Object.h"
class Image;
class Card :
    public Object
{
private:
    int _attackPower;
    int _stressPower;
    Image* m_pImage;
    Vec2 m_vPos;
public:
    Card();
    ~Card();
    CLONE(Card);
public:
    void SetCenterPos(Vec2 _vPos) { m_vPos = _vPos; }
public:
    virtual void Update() override;
    void Render(HDC _dc) override;
};

