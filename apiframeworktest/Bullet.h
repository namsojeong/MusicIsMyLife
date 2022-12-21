#pragma once
class Image;
#include "Object.h"
class Bullet :
    public Object
{
private:
    Vec2 vStartPos;//시작 시점
    Vec2 vEndPos;//끝 지점
private:
    float speed_x;//x축 속도
    float speed_y;//y축 속도
private:
    float gravity;//중력 가속도
    float endTime = 2;//도착지점 도달 시간
    float maxHeight;// 최대 높이
    float height; //최대.y - 시작.y
    float endHeight;// 도착.y - 시작.y
    float time = 0.f;//현재 시간
    float maxTime = 0.8f;//최대높이까지 가는 시간
private:
    Image* m_pImage;
public:
    void Init();
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void EnterCollision(Collider* _pOther);
    CLONE(Bullet);
public:
    Bullet(Vec2 endPos,Vec2 startPos, Vec2 scale);
    ~Bullet();
};

