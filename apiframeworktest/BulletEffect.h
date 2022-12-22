#pragma once
#include "Object.h"
class Image;
class Animation;
class BulletEffect :
    public Object
{
private:
    Image* m_pImage;
    Animation* pAnim;
public:
    BulletEffect(Vec2 startPos);
    ~BulletEffect();
public:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    CLONE(BulletEffect);
};

