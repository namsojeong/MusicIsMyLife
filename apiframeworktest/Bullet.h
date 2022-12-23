#pragma once
class Image;
#include "Object.h"
class Bullet :
    public Object
{
private:
    Vec2 vStartPos;//���� ����
    Vec2 vEndPos;//�� ����
private:
    Vec2 dir;
private:
    Image* m_pImage;
private:
    CARD_TYPE card_type;
private:
    float m_damage;
    float m_stress;
public:
    void CreateEffect();
public:
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther);
    CLONE(Bullet);
public:
    Bullet(CARD_TYPE card, Vec2 endPos,Vec2 startPos, Vec2 scale, float damage, float stress);
    ~Bullet();
};

