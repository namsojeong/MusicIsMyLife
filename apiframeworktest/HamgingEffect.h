#pragma once
#include "Object.h"
class Image;
class Animation;
class HamgingEffect :
    public Object
{
private:
    Image* m_pImage;
    Animation* pAnim;
public:
    HamgingEffect(Vec2 startPos);
    ~HamgingEffect();
public:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(HamgingEffect);
};

