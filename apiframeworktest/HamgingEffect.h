#pragma once
#include "Object.h"

class Animation;
class Image;
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
