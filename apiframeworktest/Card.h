#pragma once
#include "Object.h"
class Image;
class Card :
    public Object
{
private:
    int _attackPower;
    int _stressPower;
    Vec2    m_vDir;
    Image* m_pImage;

public:
    Card();
    ~Card();
    CLONE(Card);
public:
    void SetCenterPos(Vec2 _vPos) { m_vDir = _vPos; }
public:
    virtual void Update() override;
    void Render(HDC _dc) override;
};

